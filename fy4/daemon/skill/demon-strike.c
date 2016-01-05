// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL;
void setup() {
	set("name","�����ħ��������");
	set("usage/unarmed",1);
	set("usage/parry",1);
	set("effective_level",170);
	set("damage_level",100);
	set("type","unarmed");
	set("difficulty",200);
	set("skill_class","demon");
	set("parry_msg", ({
        	"$nʹ����ճ���־���˫��һ������ƫ��$N��$w��\n",
	}) );
	set("unarmed_parry_msg", ({
        	"$nʩչ�������ħ�������ƣ����赭д�Ļ�����$N�Ĺ��ơ�\n",
	}) );
	action = ({
        ([      "action":               
"$N˫��һ��һ�С�ħ����١��ó�������Ӱ£��$n��$l",
                "dodge":                130,
                "parry":                110,
                "damage":                150,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N˫�Ʒ׷ɣ�һ�С�ħ��ʳ⸡�ֱȡ$n��$l",
                "dodge":                110,
                "parry":                130,
                "damage":                30,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����һ����˫�������Ƴ���һ�С�ħ����ء�ǿ�����Ʒ�ֱ��$n��$l",
                "dodge":                130,
                "parry":                110,
                "damage":                150,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ�������ħ���������еġ�ħ߱ɭɭ������ȫ��$n��$l������˫��֮��",
                "dodge":                110,
                "parry":                130,
                "damage":                160,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����Ϊ����һ�С�Ǭ����ħ���������Ʒֿ�$n������Ҫ��",
                "dodge":                200,
                "parry":                300,
                "damage":                140,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�������ᣬȫ�����һ�С�ħ�ߺ͹ѡ���˫���������",
                "dodge":                70,
                "parry":                210,
                "damage":                280,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�������ߣ�һ�С�ħ�����ݡ���ɭɭ�Ʒ��޿ײ����ػ���$n��$l",
                "parry":                140,
                "force":                120,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nʹ�������ħ���������еġ�����ħ��˫��Я���ħ��֮������$n��$l",
                "parry":                240,
                "force":                220,
		"damage" :		250,
                "damage_type":  "����"
        ]),
	});
}


int valid_learn(object me)
{
	if(!::valid_learn(me)) {
		return 0;
	}
    	if( (int)me->query_skill("demon-force", 1) < me->query_skill("demon-strike",1)) {
        return notify_fail("��������ħ�ķ�����㣬�޷��������ħ�������ơ�\n");
    	}
    	return 1;
}

