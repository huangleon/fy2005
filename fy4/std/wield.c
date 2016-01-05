// weapon.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//
// 1/7/2005 I temperorily put in code to prevent weapon-lose-attributes bug
//	The bug was due to some code (e.g. champion) loads player weapon partially and  damage/save it.
//	Thus, only usep weapon can be damaged for now.


#include <ansi.h>
#include <combat.h>

inherit F_EQUIP;
inherit ITEM;

mapping weapon_actions = ([
	"ն": (["damage_type"	: "����",
			"action"		: "$N�Ӷ�$w��ն��$n��$l",
			"parry"			: 20	]),				
	"��": (["damage_type"	: "����",
			"action"		: "$N��$w��$n��$l��ȥ",
			"dodge"			: 20	]),
	
	"��": (["damage_type"	: "����",
			"action"		: "$N��$w����$n��$l������ȥ",
			"parry"			: -20	]),
			
	"��": (["damage_type"	: "����",
			"action"		: "$N��$w��$n��$l��ȥ",
			"dodge"			: 15,
			"parry"			: -15	]),
	"��": (["damage_type"	: "����",
			"action"		: "$N��$w��$n��$l��ȥ",
			"dodge"			: 15,
			"parry"			: -15	]),		
	"��": (["damage_type"	: "����",
			"action"		: "$N����$wһ�ڣ���$n��$l��ȥ",
			"dodge"			: 15,
			"parry"			: -15	]),		
	"��": (["damage_type"	: "����",
			"action"		: "$N����$wһ�ڣ���$n��$l��ȥ",
			"dodge"			: 15,
			"parry"			: -15	]),		
	"��": (["damage_type"	: "����",
			"action"		: "$N����$wһ�ڣ���$n��$l��ȥ",
			"dodge"			: 15,
			"parry"			: -15	]),						
	"��": (["damage_type"	: "����",
			"action"		: "$N��$wһ���$n��$l��ȥ",
			"dodge"			: -20,
			"parry"			: 30	]),		
	"��": (["damage_type"	: "����",
			"action"		: "$N����$w����$n��$l����һ��",
			"post_action"	: "bash_weapon"		]),
			
	"��": (["damage_type"	: "����",
			"action"		: "$N��$w��׼$n��$l���˹�ȥ",	
			"post_action"	: "throw_weapon"	])
]);

void create() {
	if(clonep(this_object())) {
		destruct(this_object());
		return notify_fail("CAN NOT CLONE STARNDARD OBJECT!\n");
	}
}

void init_wield() {
	if(query("weapon_prop") 
			&& !query("weapon_prop/dodge") 
			&& (weight() >= 300000)) {
		set("weapon_prop/dodge", - weight() / 3000 );
	}
	if(!query("weapon_prop")) {
		set("weapon_prop/damage", 0);
	}
}

mapping query_action() {
	string verb, *verbs;
	
	verbs = this_object()->query("verbs");
	
	if(!pointerp(verbs)) {
		return weapon_actions["hit"];
	} else {
		verb = verbs[random(sizeof(verbs))];
		if(!undefinedp(weapon_actions[verb])) {
			return weapon_actions[verb];
		} else {
			return weapon_actions["hit"];
		}
	}
}

string throw_weapon(object me, object victim, int damage) {
	string result = "";
	object weapon = this_object();
	
	if((int)weapon->query_amount()<=2) {
		weapon->unequip();
		tell_object(me, "\n���" + weapon->query("name") + "�����ˣ�\n\n");
		me->delete_temp("weapon");
	}
	weapon->add_amount(-1);
	return result;
}

string bash_weapon(object me, object victim, int damage) {
	object ob, weapon = this_object();
	int wap, wdp, d;
	string result = "";
	
	if(!objectp(me) || !objectp(victim) || !objectp(ob = victim->query_temp("weapon"))) {
		return result;
	}
	
	// me-- weapon, victim -- ob.
	
	if(damage==RESULT_PARRY) {
		wap = (int)weapon->weight() / 500  
				+ (int)weapon->query("rigidity") 
				+ (int)me->query_str() * 10; 
		wdp = (int)ob->weight() / 500
				+ (int)ob->query("rigidity")
				+ (int)victim->query_str() * 10;
		wap = random(wap);
		
	// victim weapon broken
		if( !random(40) && wap > 3*(wdp/2+random(wdp/2)) && userp(victim)
			&& ob->query("skill_type")!="throwing" ) {
			result += HIW "ֻ������ž����һ����$n���е�" + ob->name() + HIW"�Ѿ���Ϊ���أ�\n" NOR;
			ob->set("orig_name", ob->query("name"));
			ob->set("name", "�ϵ���" + ob->query("name"));
			d = ob->query("weapon_prop/damage") - 1;
			ob->set("weapon_prop/damage",1);
			ob->set("item_damaged", 1);
			ob->unequip();
			ob->set("value",0);
			victim->add_temp("apply/damage",-d);
			ob->set("last_broken_cause","����");
			ob->save();	
		}	else if(!random(30) && wap > wdp/2+random(wdp/2) && userp(victim)) {
			result += WHT"$nֻ��������" + ob->name() + WHT"�ѳֲ��������ַɳ���\n" NOR;
			ob->unequip();
			ob->move(environment(victim));
			ob->set("last_broken_cause","�ɳ�");
			ob->save();
			victim->reset_action();
		} else if( wap > random(wdp / 2) ) {
			result += CYN"$nֻ��������$v"CYN"һ����Щ���֣�\n"NOR;
		} else {
			result += CYN"$N��$w"CYN"��$n��$v"CYN"�����ð�����Ļ��ǡ�\n"NOR;
		}
	}
	return result;
}

string wear_off(object me, object victim, int damage) {
	object ob, weapon = this_object();
	int wap, wdp, i;
	mapping armors;
	mixed* armor_keys;
	string result = "";
	
	if(!objectp(me) || !objectp(victim)) {
		return result;
	}
	
	ob = victim->query_temp("weapon");
	if(damage == RESULT_DODGE) {
		return result;
	}
	if(damage == RESULT_PARRY && objectp(ob)) {
		// we also use wap/(wap+wdp) formular
		wap = (int)weapon->weight() / 500 + (int)weapon->query("rigidity") 
				+ (int)me->query_str() * 10;
		wdp = (int)ob->weight() / 500 + (int)ob->query("rigidity") 
				+ (int)victim->query_str() * 10;

		// victim weapon broken.		
		if((!random(40) && random(wap) > random(wap+wdp)) && userp(victim)
			&& ob->query("skill_type")!="throwing" ) {
			result += HIW "$n���е�$v"HIW"���ĳ�һ��ȱ�ڣ�\n" NOR;
			ob->add("weapon_prop/damage",-1);
			if((int)ob->query("weapon_prop/damage") < 1 ) {
				ob->set("weapon_prop/damage",1);
			} else {
				victim->add_temp("apply/damage",-1);
			}
			ob->set("item_damaged", 1);
			ob->save();
		}
		// attacker(me) weapon broken
		if(!random(40) && random(wdp) > random(wap+wdp) && userp(me)
			&& weapon->query("skill_type")!="throwing") {
			result += HIW "$N���е�$w"HIW"���ĳ�һ��ȱ�ڣ�\n" NOR;
			weapon->add("weapon_prop/damage",-1);
			if((int)weapon->query("weapon_prop/damage") < 1 ) {
				weapon->set("weapon_prop/damage",1);
			} else {
				me->add_temp("apply/damage",-1);
			}
			weapon->set("item_damaged", 1);
			weapon->save();
		}
	}
	// victim armor broken
	if(damage > 20 && !random(40) 
		&& mapp(armors = victim->query_temp("armor")) 
		&& sizeof(armor_keys = keys(armors)) > 0
		&& userp(victim)) {
		ob = armors[armor_keys[random(sizeof(armor_keys))]];
		
		// û�б������Ķ���������
		if (ob->query("armor_prop/armor")>0) {
			result += HIW "$n" + ob->query("armor_worn") + "��" +ob->name()
					+ HIW"��Ū����һ�����\n" NOR;
			ob->add("armor_prop/armor",-1);
			if((int)ob->query("armor_prop/armor") < 0 ) {
				ob->set("armor_prop/armor",0);
			} else {
				victim->add_temp("apply/armor",-1);
			}
			ob->set("item_damaged", 1);
			ob->save();
		}
	}
	
	return result;
}
