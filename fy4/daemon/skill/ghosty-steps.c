// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL;
void setup() {
	set("name","̫��ò�");
	set("type","step");
	set("usage/dodge",1);
	set("usage/move",1);
	set("effective_level",130);
	set("difficulty",200);
	set("skill_class","ninja");
	set("dodge_msg", ({
	        "$n��Ӱһ�Σ����Ǽ�Ų��$N�ı���\n",
	        "$n΢΢����һ����������Ʈ�����⡣\n",
	        "$n˫��΢΢�趯����������һƬ��Ҷ����������Ʈ����\n",
	        "$n˫��΢�ߣ���һֻ��ݵ����ӷ��˿���\n",
	        "$n����һ���������˵������⡣\n"
	}) );
}

/*
int valid_learn(object me)
{
	object ob;
	
	if(!::valid_learn(me)) {
		return 0;
	}
	if (REWARD_D->check_m_success( me, "���˵ı���" )!= 1) 
		return notify_fail("���ʮ����δ��Ӧת���������书��\n");
	if ((int)me->query("tianfeng/ghosty-steps")!=1){
		return notify_fail("���ʮ����δ��Ӧ���������书��\n");
	}
	return 1;
}
*/

int help(object me)
{
	write(@HELP   
��̫��ٻá�
��150��̫��ò��������е������������������ؼ�����Ҫenable̫��ò�
���ܹ�ʹ�á�ʹ��ʱֻ�� perform taixubaihuan������æ��һ�֡�
ת����������Ϊ����ǰ��������̫��ò��ȼ�����������
HELP
    );
    return 1;
}
