// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL;
void setup() {
	set("name","������ħ�����˲�");
	set("type","step");
	set("difficulty",200);
	set("usage/dodge",1);
	set("usage/move",1);
	set("effective_level",200);
	set("skill_class","demon");
	set("dodge_msg", ({
	        "$nһ�С�ħ����Ӱ����ȫ����ǧ�ٸ���Ӱ��������$N��һ�С�\n",
	        "$n���۵��һ�С�����ħ�¡������μ������㿪$N������һ����\n",
	        "$n������������Х������һ�С�ħ�����¡����������⡣\n",
	        "$n˫����̤������һ�С�ħ���컡��������ޱ�����ص������ߡ�\n",
	        "$nʹ��������ħ�����˲��еġ�ħӰ��á������λ�ʵΪ��ض㿪��$N��һ�С�\n",
	        "$n�ڿ�һԾ��˫�������̤��һ�С�ħ�����������㿪���ߡ�\n",
	        "$n���λζ���һ�С�ħ���¡����ȫ����������Ӱ�ӳ����⡣\n",
	        "$n����һ������һ�С���ħ���Ρ���������һ���ޱȹ��������Ť���ŵ������ߡ�\n"
		}) );
	
}


