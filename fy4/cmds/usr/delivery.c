// flower_delivery.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// created by suu on Oct/31/01
	
#include <ansi.h>
inherit F_CLEAN_UP;
int time_period(int timep, object me);

int main(object ob, string arg) {
	int nowtime = time();
	object me;
	if(!arg || !wizardp(ob)) 
	{
		me = this_player();
		if(!me->query("delivery")) 
		{
			if((me->query("next_delivery_time")) > time()) 
			{
				return notify_fail(HIW"��Ҫ��" 
                + QUESTS_D->wait_period(me->query("next_delivery_time") - time()) 
                + "֮��ſɼ����ͻ���\n"NOR);
			}else 
			return notify_fail("������û���κ��ͻ�����\n");            
		}
		if(mapp(me->query("delivery")))
		{
			mapping delivery;
			delivery =  me->query("delivery");
            write(WHT"�����ڵ���������"  + delivery["sender"] + "�ͻ���ס��"
+delivery["area"]+"��"+delivery["receiver"]->name()+"��\n"NOR);
		} else 
		{
			return notify_fail("������û���κ��ͻ�����\n");            
		}
		nowtime = (int)time() - me->query("delivery_time");
		if(nowtime  < 600) 
		{
			time_period(nowtime, me);
		} else 
		{
            return notify_fail("���Ѿ�û���㹻��ʱ����������ˡ�\n");
			if (nowtime < 1200)
			{
				return notify_fail(HIW"��Ҫ��" 
				+  QUESTS_D->wait_period(1200-nowtime) 
				+ "֮��ſɼ����ͻ���\n"NOR);
			}
		}
	} else 
	{
		if(!(ob = present(arg, environment(ob))) && !(ob =  find_player(arg))) 
		{
			return notify_fail("��Ҫ�쿴˭���ͻ�����\n");
		}
		if(!ob->query("delivery")) 
		{
			if((ob->query("next_delivery_time")) > time()) 
			{
				return notify_fail(HIW+ob->name()+"Ҫ��" 
                + QUESTS_D->wait_period(me->query("next_delivery_time") - time()) 
                + "֮��ſɼ����ͻ���\n"NOR);
			}else 
				return notify_fail(ob->name()+"����û���κ��ͻ�����\n");
		}

		if(mapp(ob->query("delivery"))) 
		{
			mapping delivery;
			delivery =  ob->query("delivery");
			write(WHT""+ob->name()+"���ڵ���������"  + delivery["sender"] + "�ͻ���ס��"
+delivery["area"]+"��"+ delivery["receiver"]->name()+"��\n"NOR);
		}else 
		{
			return notify_fail(ob->name()+"����û���κ��ͻ�����\n");            
		}

		nowtime = (int)time() - ob->query("delivery_time");
		if(nowtime  < 600) 
		{
			time_period(nowtime, ob);
		} else 
		{
			return notify_fail(ob->name()+"�Ѿ�û���㹻��ʱ����������ˡ�\n");
			if (nowtime < 1200)
			{
				return notify_fail(HIW+ob->name()+"Ҫ��" 
				+  QUESTS_D->wait_period(1200-nowtime) 
				+ "֮��ſɼ����ͻ���\n"NOR);
			}
		}
	}	
	return 1;
}

int time_period(int timep, object me) {
	int t, d, h, m, s;
	string time;
	t = timep;
	s = t % 60;             t /= 60;
	m = t % 60;             t /= 60;
	h = t % 24;             t /= 24;
	d = t;
	
	if(d) time = chinese_number(d) + "��";
	else time = "";
	
	if(h) time += chinese_number(h) + "Сʱ";
	if(m) time += chinese_number(m) + "��";
	time += chinese_number(s) + "��";
	tell_object(me,"�����Ѿ���ʼ��" + time + "\n");
	return 1;
}

int help(object me) {
	write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	ָ���ʽ : delivery[0m
[0;1;37m����������������������������������������������������������������[0m   
 
���ָ�������ʾ���㵱ǰ���ͻ�����

[0;1;37m����������������������������������������������������������������[0m  
HELP);
	return 1;
}
