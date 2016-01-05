// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL;
void setup() {
	set("name","��ǧҶ�Ʒ�");
	set("type","unarmed");
	set("effective_level",120);
	set("usage/unarmed",1);
	set("usage/parry",1);
	set("difficulty",200);
	set("skill_class","shaolin");
	set("practice_limit",100);
	set("parry_msg", ({
	        "$n˫��һ�֣�ʹ��һ�С�Ǭ����˽������ž����һ����$N��$w����˫��֮�䡣\n",
	        "$n��һת��һ�С���ͬ�ڡ�����$N����$w���֡�\n",
	        "$nʹ�����������ơ�������������˫��һ������ƫ��$N��$w��\n",}) 
        );

	set("unarmed_parry_msg", ({
	        "$n��������һ�С���������������ĳ����ƣ��Ƶ�$N�����Ա���\n",
	        "$nʩչ����Ǭ����˽�������赭д�Ļ�����$N�Ĺ��ơ�\n",}) 
        );
	
	action = ({
        ([      "action":               
"$Nʹ��һ�С���Ե��ȡ���������ӣ�һ�������������$n��$l",
                "dodge":                100,
                "parry":                100,
                "force":                100,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ��һ�С����ⴺ�⡹������һ����Ӱ������������$n��$l",
                "dodge":               100,
                "parry":                100,
                "force":                 70,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ����ǧҶ�Ʒ��еġ������������������ţ��������ƣ�һ������$n��$l",
                "dodge":               100,
                "parry":                100,
                "force":                50,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N���μ�����ʹ����������桹����ӰͻȻ��Ϊһ�壬˫���ѵ���$n����ǰ",
                "dodge":                100,
                "parry":                100,
                "force":                150,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N˫��һ���������ζ�����һ�С�ë�̴󺣡�����$n$l",
                "dodge":                100,
                "parry":                100,
                "force":                140,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N˫�ƻζ���ʹ����ͬ��󱯡����Ʒ簵���޴��������ӿ��е�ͷ��$n��$l���ƹ���",
                "dodge":                200,
                "parry":                200,
                "force":                150,
                "damage_type":  "����"
        ]),
	});
}


int help(object me)
{
	write(@HELP   
L20	��ǧ��ǧ�䡻��qianshouqianbian��
�����æ�����У���ǧҶ�Ʒ��ȼ�Խ�ߣ��ɹ���Խ�ߡ�
���л�Ե�����ɶ�������ޡ�

HELP
    );
    return 1;
}
