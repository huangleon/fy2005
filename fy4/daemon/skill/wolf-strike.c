// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL;
void setup(){
	set("name","���ǰ���ȭ");
	set("practice_limit",100);
	set("usage/parry",1);
	set("damage_level",100);
	set("type","unarmed");
	set("usage/unarmed",1);
	set("effective_level",120);
	
	set("difficulty",200);
	set("skill_class","wolfmount");
	
	set("parry_msg", ({
       		"$n��ɫ������������$N����$N�е��޷����С� \n",
		"$n����һ�����ַ�ץ$N������$N��æ�˲��Ա��� \n",
		"$n˫ȭ����ӳ���������ң��ȵ�$N�������ˡ� \n",
	}) );

	set("unarmed_parry_msg", ({
       		"$n��ɫ������������$N����$N�е��޷����С� \n",
		"$n����һ�����ַ�ץ$N������$N��æ�˲��Ա��� \n",
		"$n˫ȭ����ӳ���������ң��ȵ�$N�������ˡ� \n",
	}) );
	
	action = ({
        ([      "action":               
"$N����$n�������ߣ�ͻȻ�����϶������ͻ�$n��$l",
                "dodge":                110,
                "parry":                110,
                "damage":                50,
                "damage_type":  "ץ��"
        ]),
        ([      "action":               
"$N���ɨ������;����һ����˫�ֺ�£ץ��$n��$l",
                "dodge":                130,
                "parry":                130,
                "damage":                50,
                "damage_type":  "ץ��"
        ]),
        ([      "action":               
"$N������Х����ȻһԾ���𣬺��⹥��$n��$l",
                "dodge":                150,
                "parry":                150,
                "damage":                50,
                "damage_type":  "ץ��"
        ]),
        ([      "action":               
"$Nб��һת�����Ƴ�צ���$n���ţ���������б��$n��$l",
                "dodge":                170,
                "parry":                170,
                "damage":                70,
                "damage_type":  "ץ��"
        ]),
	});
}

int valid_learn(object me)
{
	if(!::valid_learn(me)){
		return 0;
	}
	if(me->query_skill("summonwolf", 1) <= me->query_skill("wolf-strike",1)){
	    return notify_fail("��Ļ���������㣬�޷������ǰ���ȭ��\n");
	}
	return 1;
}


int help(object me)
{
	write(@HELP   
ѧϰ���ǰ���ȭ��Ҫ��ͬ�ȼ��Ļ�����Ϊ����

L30���Ϻ���duanhou��
�������֣�����æ��2��
���⹥����=���ǰ���ȭ�ȼ�
�����˺���=���ǰ���ȭ�ȼ�*3/2
����Է���ʧ��״̬����б��У������˺���*3��ȡ������ֵ

L50���ȹǡ���shigu��
�������ֲ����˺���30%תΪ�Լ�����Ѫ������æ��2��
���⹥����=50+���ǰ���ȭ�ȼ�
�����˺���=50+���ǰ���ȭ�ȼ�*2

L150����֫����canzhi��
������������������æ��1�֣�ÿ90��ʹ��һ��
���⹥���� = ���ǰ���ȭ�ȼ�

L200����Ѫ����ningxue��
�������֣�����æ��1�֡�
���⹥����=���ǰ���ȭ�ȼ�*3
����ɹ����в��˺����ֿɽ��롰��Ѫ��״̬
��״̬����20�غϣ�
������+100��������+100���м���+100
���ָ�״̬����һ������Ѫ����ȴ�90��

HELP
    );
    return 1;
}
