// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit SKILL;
void setup() {
	set("name","�޿�����");
	set("type","force");
	set("effective_level",100);
	set("difficulty",200);
	set("usage/force",1);
	set("skill_class","ninja");
}

/*
void skill_improved(object me)
{
	int s,diff;
	
	s = me->query_skill("ghosty-force", 1);
	diff = (s-100)/10;
	if((int)me->query("age_modify") > -diff && diff > 0) {
        tell_object(me, HIG "����޿�������פ����Ч�����Եø��������ˣ�\n" NOR);
		me->set("age_modify",-diff);
		me->update_age();
	}
}*/

/*
int valid_learn(object me)
{
	object ob;
	
	if(!::valid_learn(me)) {
		return 0;
	}
	if (REWARD_D->check_m_success( me, "���˵ı���" )!= 1) 
		return notify_fail("���ʮ����δ��Ӧת���������书��\n");
	if (!(int)me->query("tianfeng/ghosty-force")){
		return notify_fail("���ʮ����δ��Ӧ���������书��\n");
	}
	return 1;
}
*/

int help(object me)
{
	write(@HELP   
������������juyin��
��100���޿����������������������������ؼ�����enable�޿�����
����ʹ�ã���������Լ��������Ѿ�����������߹�����������ؼ���
�����ر�˵�������޷�ͬʱʹ�á�
ʹ�÷�����exert juyin
���������Ч�ȼ�Ϊ���������޿������ȼ�����
HELP
    );
    return 1;
}
