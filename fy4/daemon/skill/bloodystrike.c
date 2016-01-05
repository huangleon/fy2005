// bloodystrike.c
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL;

void setup() {
	set("name","���ڴ���ӡ");
	set("type","unarmed");
	set("effective_level",110);
	set("usage/parry",1);
	set("usage/unarmed",1);
	set("difficulty",200);
	set("practice_limit",100);
	set("skill_class","lama");
	set("parry_msg", 			({
			"$n˫��΢�ϣ�ʹ��һ�С�ǧ��ӭɲ�𡹣���ž����һ����$N��$w����˫��֮�䡣\n",
			"$n��һת��һ�С�������쳾������$N����$w���֡�\n",
			"$nʹ����ճ���־���˫��һ������ƫ��$N��$w��\n",
			})
	);
	set("unarmed_parry_msg",	({
			"$n����������һ�С��ҷ�ȱ���������ĳ����ƣ��Ƶ�$N�����Ա���\n",
			"$nʩչ��������Թ�ա������赭д�Ļ�����$N�Ĺ��ơ�\n",
			})
	);

	action = ({
			([      "action":               
			"$Nʹ��һ�С��ຣ�����ġ���������ϣ����ƴ�������$n��$l",
			        "dodge":                100,
			        "parry":                100,
			        "force":                100,
			        "damage_type":  "����"
			]),
			([      "action":               
			"$Nʹ��һ�С����������š������ƻ���Ϊʵ����$n��$l",
			        "dodge":                100,
			        "parry":                100,
			        "force":                 70,
			        "damage_type":  "����"
			]),
			([      "action":               
			"$Nʹ�����ڴ���ӡ�еġ�����ȴ��·����һ������$n��$l",
			        "dodge":                100,
			        "parry":                100,
			        "force":                50,
			        "damage_type":  "����"
			]),
			([      "action":               
			"$N˫��һ��ʹ��������Ϊ���𡹣���׼$n��$l�����ĳ�",
			        "dodge":                100,
			        "parry":                100,
			        "force":                150,
			        "damage_type":  "����"
			]),
			([      "action":               
			"$N����������ǰ�������Ƴ���һ�С�������ǿա�����$n$l",
			        "dodge":                100,
			        "parry":                100,
			        "force":                140,
			        "damage_type":  "����"
			]),
			([      "action":               
			"$Nʹ����������ɱֹɱ����������շ��𣬴ӿ��е�ͷ��$n��$l���ƹ���",
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
�����ޱߡ���fofawubian��
��Ҫ���������ڴ���ӡ��
æ�Ҷ��֣�����ɹ������æ�����У����ʧ���򹥻��Է�һ�У�����
�ɰ�����������æ�ң����жԵ��˲�������ĳ�ޡ�

�������ǻ�����sheshensihu��
��Ҫ�����������ڴ���ӡ�ͣ������������ڷ𷨡�
����ɹ���������׵ȼ�����ղ������ȼ���
�Ե��˲������⣽�����ޱߡ���޵�5����
ά��120�룬CDT8���ӡ�

��ӡ������yinqi��
��Ҫ�����������ڴ���ӡ�ͣ������������ڷ𷨡�
����������һ���к�����޷����ܡ��ڶ����к�����޷��мܣ�����æ
�����غ�
���⹥���������ڴ���ӡ�ȼ���
�����˺��������ڴ���ӡ�ȼ���
���һ���Ķ��⹥�����Ͷ����˺������������ڷ𷨵ȼ����������
������߶�������
HELP
    );
    return 1;
}
