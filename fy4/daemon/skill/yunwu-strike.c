// yunwu-strike.c
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL;

void setup() {
	set("name","�����Ʒ�");
	set("practice_limit",100);
	set("usage/parry",1);
	set("type","unarmed");
	set("effective_level",150);
	set("difficulty",200);
	set("usage/unarmed",1);
	set("skill_class","huangshan");
	set("parry_msg",			({
			"$nʹ��һ�С�������ɽ��������������$N��$w������ס��\n",
			"$n���Ʋ�㣬һ�С��ƿ���ɢ������$N����$w���֡�\n",
			"$nʹ�����ƺ�ãã����˫��һ������ƫ��$N��$w��\n",
			})
	);
	set("unarmed_parry_msg",	({
			"$n˫��һ����һ�С�����Ƶ�������ĳ�һ�ƣ��Ƶ�$N�����Ա���\n",
			"$nʩչ�������Ƹ��񡹣����赭д�Ļ�����$N�Ĺ��ơ�\n",
			})
	);
	action = ({
			([      "action":               
					"$Nʹ��һ�С����Ʊ��ա�������һ�ݣ�˫�����϶��£�����$n��$l",
			        "dodge":                100,
			        "parry":                100,
			        "force":                100,
			        "damage_type":  "����"
			]),
			([      "action":               
					"$Nʹ��һ�С���ӳ��ա���˫��һ�֣�ֱ��$n��$l",
			        "dodge":                100,
			        "parry":                100,
			        "force":                 70,
			        "damage_type":  "����"
			]),
			([      "action":               
					"$Nʹ�������Ʒ��еġ��������ɡ������Ʋ���$n��$l",
			        "dodge":                100,
			        "parry":                100,
			        "force":                50,
			        "damage_type":  "����"
			]),
			([      "action":               
					"$N˫��һ��һ����Σ�ʹ��������ɽ�С�����׼$n��$l����б��",
			        "dodge":                100,
			        "parry":                100,
			        "force":                150,
			        "damage_type":  "����"
			]),
			([      "action":               
					"$N��������վ����˫����ӣ�ʹ������ɽ�ƺ�����Ϯ��$n$l",
			        "dodge":                100,
			        "parry":                100,
			        "force":                140,
			        "damage_type":  "����"
			]),
			([      "action":               
					"$Nʹ�������ո��ơ�������˫�ƣ��ӿ��е�ͷ��$n��$l���ƹ���",
			        "dodge":                200,
			        "parry":                200,
			        "force":                150,
			        "damage_type":  "����"
			]),
	});
}		

int valid_learn(object me)
{
	object ob;
	if(!::valid_learn(me)) {
		return 0;
	}
	if (me->query("class")!="huangshan")
		return notify_fail("�㻹����ѧ�����书��\n");
	if( (int)me->query("max_force") < 500 ) {
	        return notify_fail("�������������û�а취�������Ʒ���\n");
	}
	 return 1;
}

int practice_skill(object me)
{
        return notify_fail("�����Ʒ�ֻ��ѧ�ġ�\n");
}
