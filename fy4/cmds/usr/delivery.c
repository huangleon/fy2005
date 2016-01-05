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
				return notify_fail(HIW"ƒ„“™π˝" 
                + QUESTS_D->wait_period(me->query("next_delivery_time") - time()) 
                + "÷Æ∫Û≤≈ø…ºÃ–¯ÀÕª®°£\n"NOR);
			}else 
			return notify_fail("ƒ„œ÷‘⁄√ª”–»Œ∫ŒÀÕª®»ŒŒÒ£°\n");            
		}
		if(mapp(me->query("delivery")))
		{
			mapping delivery;
			delivery =  me->query("delivery");
            write(WHT"ƒ„œ÷‘⁄µƒ»ŒŒÒ «ÃÊ"  + delivery["sender"] + "ÀÕª®∏¯◊°‘⁄"
+delivery["area"]+"µƒ"+delivery["receiver"]->name()+"°£\n"NOR);
		} else 
		{
			return notify_fail("ƒ„œ÷‘⁄√ª”–»Œ∫ŒÀÕª®»ŒŒÒ£°\n");            
		}
		nowtime = (int)time() - me->query("delivery_time");
		if(nowtime  < 600) 
		{
			time_period(nowtime, me);
		} else 
		{
            return notify_fail("ƒ„“—æ≠√ª”–◊„πªµƒ ±º‰¿¥ÕÍ≥…À¸¡À°£\n");
			if (nowtime < 1200)
			{
				return notify_fail(HIW"ƒ„“™π˝" 
				+  QUESTS_D->wait_period(1200-nowtime) 
				+ "÷Æ∫Û≤≈ø…ºÃ–¯ÀÕª®°£\n"NOR);
			}
		}
	} else 
	{
		if(!(ob = present(arg, environment(ob))) && !(ob =  find_player(arg))) 
		{
			return notify_fail("ƒ„“™≤Ïø¥À≠µƒÀÕª®»ŒŒÒ£ø\n");
		}
		if(!ob->query("delivery")) 
		{
			if((ob->query("next_delivery_time")) > time()) 
			{
				return notify_fail(HIW+ob->name()+"“™π˝" 
                + QUESTS_D->wait_period(me->query("next_delivery_time") - time()) 
                + "÷Æ∫Û≤≈ø…ºÃ–¯ÀÕª®°£\n"NOR);
			}else 
				return notify_fail(ob->name()+"œ÷‘⁄√ª”–»Œ∫ŒÀÕª®»ŒŒÒ£°\n");
		}

		if(mapp(ob->query("delivery"))) 
		{
			mapping delivery;
			delivery =  ob->query("delivery");
			write(WHT""+ob->name()+"œ÷‘⁄µƒ»ŒŒÒ «ÃÊ"  + delivery["sender"] + "ÀÕª®∏¯◊°‘⁄"
+delivery["area"]+"µƒ"+ delivery["receiver"]->name()+"°£\n"NOR);
		}else 
		{
			return notify_fail(ob->name()+"œ÷‘⁄√ª”–»Œ∫ŒÀÕª®»ŒŒÒ£°\n");            
		}

		nowtime = (int)time() - ob->query("delivery_time");
		if(nowtime  < 600) 
		{
			time_period(nowtime, ob);
		} else 
		{
			return notify_fail(ob->name()+"“—æ≠√ª”–◊„πªµƒ ±º‰¿¥ÕÍ≥…À¸¡À°£\n");
			if (nowtime < 1200)
			{
				return notify_fail(HIW+ob->name()+"“™π˝" 
				+  QUESTS_D->wait_period(1200-nowtime) 
				+ "÷Æ∫Û≤≈ø…ºÃ–¯ÀÕª®°£\n"NOR);
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
	
	if(d) time = chinese_number(d) + "ÃÏ";
	else time = "";
	
	if(h) time += chinese_number(h) + "–° ±";
	if(m) time += chinese_number(m) + "∑÷";
	time += chinese_number(s) + "√Î";
	tell_object(me,"»ŒŒÒ“—æ≠ø™ º¡À" + time + "\n");
	return 1;
}

int help(object me) {
	write(@HELP
[0;1;37m©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§[0m
[0;1;36m÷∏¡Ó∏Ò Ω : 	÷∏¡Ó∏Ò Ω : delivery[0m
[0;1;37m©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§[0m   
 
’‚∏ˆ÷∏¡Óø…“‘œ‘ æ≥ˆƒ„µ±«∞µƒÀÕª®»ŒŒÒ°£

[0;1;37m©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§[0m  
HELP);
	return 1;
}
