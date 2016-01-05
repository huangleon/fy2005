// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// kongshoudao.c
inherit SKILL;
void setup() {
	set("name","���ֵ�");
	set("damage_level",400);
	set("usage/unarmed",1);
	set("usage/parry",1);
	set("type","unarmed");
	set("effective_level",100);
	set("difficulty",200);
	set("skill_class","npc");
	set("parry_msg", ({
        "$n����һ����˫��һ�ŵأ�ȫ����$N��$w�Ĺ�����Χ��\n",
	}) );

	set("unarmed_parry_msg", ({
        "$n����һ����˫��һ�ŵأ�ȫ����$N�Ĺ�����Χ��\n",
	}) );	
	action = ({
        ([      "action":               
"$N������ǰ�������ں�˫��������$n��$l����",
                "dodge":                30,
                "parry":                10,
                "damage":                50,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N��ŵ�أ����������ת�������񼲷�ɨ��Ҷ��ɨ��$n��$l",
                "dodge":                10,
                "parry":                30,
                "damage":                50,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N������Σ���������벻���ĽǶ�ײ��$n��$l",
                "dodge":                30,
                "parry":                10,
                "damage":                80,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�ҽ���գ��γ�һƬ��Ӱ�����Ǽ���$n��$lһ���߳�����",
                "dodge":                10,
                "parry":                30,
                "damage":                70,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N���Ծ���������ת��˫�Ŵ�������һǰһ�������$n��$l",
                "dodge":                20,
                "parry":                30,
                "damage":                60,
                "damage_type":  "����"
        ]),
	});
}
