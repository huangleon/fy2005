// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL;
#include <ansi.h>

void setup(){
	set("name","����ն");
	set("type","dagger");
	set("usage/dagger",1);
	set("usage/parry",1);
	set("effective_level",300);
	set("difficulty",300);
	
	set("skill_class","npc");
	set("parry_msg", ({
		"$n�����ؽ����е�$v������ǰ��ǿ�ҵĵ��罫$N�Ƶ����˼�����\n",
	}) );

	set("unarmed_parry_msg", ({
		  "$n���е�$v�����ػӳ������Ҳ����ĵ������$N��\n",
	}) );	
	
	
	action = ({
        ([  "action":       "$N����һ��$w���������쵶�⡣�ӻ���������$n���ң�$n�ݷ�������������ɫ֮�У���
�⾹�������޾������಻ȥ",
			"dodge":		100,
			"damage":		200,
			"damage_type":	"����"
		]),
        ([  "action":       "$N����ͻת����������Ļ��Ⱥ�Х�����������ĵ���·�������һĨ����",
			"dodge":		150,
			"damage":		180,
			"damage_type":	"����"
		]),
        ([  "action":       "$N���е�$wͻȻ����ǧ�����֮�䣬�޲������Ѽ�������̩ɽѹ��һ�㣬��$n����
������",
			"dodge":		200,
			"damage":		220,
			"damage_type":	"����"
		]),
        ([  "action":       "$N����һת�����ֱ��������֣����紺�绯�꣬�����ѩ���裬��̬�����Ѽ�",
			"dodge":		220,
			"damage":		300,
			"damage_type":	"����"
		]),
        ([  "action":       "$N˫�ֽ���$w��˫��һ����һ�ɳ��졣���浶�ƣ��������Σ���$n$l����",
			"dodge":		300,
			"damage":		500,
			"damage_type":	"����"
	        ]),
	});
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
    	object my_weapon;
    	int badint;
    	my_weapon=me->query_temp("weapon");
    	if(damage_bonus < 300 ) return 0;
        if(victim->query_skill_mapped("iron-cloth") == "yijinjing") {
        	badint = victim->query_skill("iron-cloth")*2+random(victim->query_skill("iron-cloth"));
		if(badint) {
			victim->receive_wound("kee",badint,me);
			switch(random(2)) {
        			case 0: return HIW"$N����"+my_weapon->query("name")+"͸��һ˿˿����,��������$n�Ļ����񹦣�\n"NOR;
               			case 1: return HIW"$nֻ����ͷһ��,$N��"+my_weapon->query("name")+"��͸����� ������\n"NOR;
           		}
		}
	}
	return 0;
}
