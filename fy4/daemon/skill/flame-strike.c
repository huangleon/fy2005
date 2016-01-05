inherit SKILL;
#include <ansi.h>

void setup() {
	set("name","���溮����");
	set("type","unarmed");
	set("effective_level",200);
	set("difficulty",200);
	set("usage/unarmed",1);
	set("usage/parry",1);
	set("damage_level",250);
	set("practice_limit",100);
	set("skill_class","assassin");
	
	set("parry_msg",			({
			"$n����Ϊ����һ�С����Ͻ��͡�����$N����$w���֡�\n",
			"$n˫�ƽ���ʹ��һ�С����ȴ���������ž����һ����$N��$w����˫��֮�䡣\n",
			"$n��һת��һ�С���ˮ�ɱ�������$N����$w���֡�\n",
			"$nʹ�����ס��־���˫��һ������ƫ��$N��$w��\n",
		})
	);
	set("unarmed_parry_msg", 	({
			"$n�������ǣ�һ�С�����Ϊ��������ĳ�ʮ���ƣ��Ƶ�$N�����Ա���\n",
			"$n����Ϊָ��һ�С��ƻ�ǻ𡹷���$N������ҪѨ��\n",
			"$nʩչ������ָ˫�ɡ������赭д�Ļ�����$N�Ĺ��ơ�\n",
		})
	);
	
	action = ({
			([      "action":               
			"$Nʹ��һ�С�����ȡ����������һ����������󴩳�����$n��$l",
			        "dodge":                130,
			        "parry":                100,
			        "damage_type":  "����"
			]),
			([      "action":               
			"$Nʹ��һ�С������ݱ���������������Σ�����Ϊʵ����$n��$l",
			        "dodge":                100,
			        "parry":                230,
			        "damage_type":  "����"
			]),
			([      "action":               
			"$Nʹ�������ɵ�ɽ��������Ȱ�����$n��ǰ��һ������$n��$l",
			        "dodge":                130,
			        "parry":                210,
			        "damage_type":  "����"
			]),
			([      "action":               
			"$N˫��һ�������б��¡���һ�ɼ��������Ĺ�������$n��$l",
			        "dodge":                220,
			        "parry":                230,
			        "damage_type":  "����"
			]),
			([      "action":               
			"$N���ƻ��˸�ȦȦ�������Ƴ���һ�С����Ǻ��⡹����$n$l",
			        "dodge":                120,
			        "parry":                130,
			        "damage_type":  "����"
			]),
			([      "action":               
			"$Nʹ�������ǵ�㡹������ɢ���ߴ�ͬʱ��$n��$l���ƹ���",
			        "dodge":                170,
			        "parry":                110,
			        "damage_type":  "����"
			]),
			([      "action":               
			"$N����������һ�С���������졹˫�Ʋ����Ƴ�",
			        "dodge":                170,
			        "parry":                240,
			        "damage_type":  "����"
			]),
	});
}

int valid_learn(object me) {
	if(!::valid_learn(me)){
		return 0;
	}
	if((int)me->query_skill("jingxing", 1)+30 < (int)me->query_skill("flame-strike", 1) ) {
		return notify_fail("��ľ����ķ�����㣬�޷������溮���ơ�\n");
	}
	if((int)me->query("max_force") < 100 ) {
		return notify_fail("�������̫�����޷������溮���ơ�\n");
	}
	return 1;
}


//	200+150 = 350 extra
mixed hit_ob(object me, object victim, int damage_bonus)
{
	int damage, lvl;
	
	if (me->query("class")!="assassin") return;
	lvl= me->query_skill("flame-strike",1);
	
	damage = lvl + F_LEVEL->get_level(me->query("combat_exp"));
	
	damage = COMBAT_D->magic_modifier( me, victim, "kee", damage/2 + random(damage/2));
	victim->receive_wound("kee", damage ,me);
	if (random(2)) 
		return RED "$N�����˳�һ���ɺ�����棬�ǿ���$n��ȫ��\n" NOR;
	else	
		return WHT "$N����͸��˿˿����,$n�����ߡ�\n" NOR;
}

/*
mapping query_action(object me, object weapon) {
	mapping act=([]);
	if(sizeof(action) > 0) {
		if (random(2))
			act["action"] = RED + action[random(sizeof(action))]["action"] + NOR;
		else 
			act["action"] = WHT + action[random(sizeof(action))]["action"] + NOR;
	}
	return act; 
}*/
