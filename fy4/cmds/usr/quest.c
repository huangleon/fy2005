// quest.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//
	
#include <ansi.h>
inherit F_CLEAN_UP;
string time_period(int timep);

int main(object ob, string arg) {
	
	int i, time, nowtime, newbie;
	object me;
	object* mem;
	mapping quest;
	string msg,n_msg;

// NEWBIE QUEST INFORMATION

	newbie = REWARD_D->riddle_check(ob,"ÐÂÊÖÈëÃÅ");
	
	switch (newbie) {
		case 1: if (!ob->query_temp("marks/newbie_quest")) 
					n_msg = "
ÄãÏÖÔÚµÄÈÎÎñÊÇ£¬µ½·çÔÆ¸ó£¨·çÔÆ¹ã³¡ÏòÉÏ£©È¥ÕÒÌì»úÀÏÈË£¨£ñ£õ£å£ó£ô£©£¬²»ÖªµÀ
Ìì»ú¹ã³¡ÔÚÄÄ¶ù£¿·çÔÆ³ÇµÄÕýÖÐÐÄ¾ÍÊÇÁË¡£\n";
				else			
					n_msg = "
ÄãÏÖÔÚµÄÈÎÎñÊÇ£¬ÌæÌì»úÀÏÈËÈ¥ÏòÎäµ±ÕÆÃÅÊ¯ÑãÎÊ¸öºÃ£¬³ö·çÔÆ¶«³ÇÃÅµ½³à·åÂ·ÏòÄÏ£¬
ÉÏÁËÎäµ±É½¾ÍÄÜÕÒµ½Ëû¡££¨´Ó·çÔÆÌìÏÂ³ö·¢¶«ÐÐÊ®²½£¬ÄÏÐÐ°Ë²½£¬ÉÏÉ½ºóÕÒ×ÏÏö¹¬¾ÍÊÇ£¬
¼ûÃæºóÊ¯Ñã×ÔÈ»»áÓÐ°²ÅÅ£¬¶ÔÁË£¬ËûÓÐÊ±ºò±È½ÏÃ¦¿ÉÄÜÃ»×¢Òâµ½Äã£¬³öÈ¥ÔÙ½øÀ´Ëû¾Í»á
¿´µ½ÄãÁË£©\n";
				write(n_msg);
				return 1;
		case 2: if (!ob->query_temp("marks/newbie_quest")
					|| ob->query_skill("literate",1)>=1)
					n_msg = "
ÄãÏÖÔÚµÄÈÎÎñÊÇ£¬·µ»Ø·çÔÆ³ÇÏòÌì»úÀÏÈË½»²î£¨£ñ£õ£å£ó£ô£©\n";
				else
					n_msg= "
ÄãÏÖÔÚµÄÈÎÎñÊÇ£¬µ½±±³Ç¼°µÚ½Ö¹±ÔºÍõÈÊµÂÄÇ¶ùÈ¥Ñ§µã¶ÁÊéÐ´×Ö£¬
£¨learn literate from kao guan with 1£©£¬Èç¹û²»ÖªµÀÔõÃ´×ß£¬µ½±±³ÇÊäÈë£í£á£ð£ó
ÔÚµØÍ¼ÉÏÕÒ¹±Ôº¾ÍÊÇ¡£\n";
				write(n_msg);
				return 1;
		case 3: n_msg = "
ÄãÏÖÔÚµÄÈÎÎñÊÇ£¬ÌæÌì»úÀÏÈËÈ¥°Ý¼ûÒ»ÏÂ¹ØÍâ´óÕÑËÂ±¦ËþµÄËþ×££¬¿ÉÒÔ×Ô´ËÏòÄÏ´Ó³ÁÏãÕò
×ß£¨²Î¿´£è£å£ì£ð¡¡£î£å£÷£â£é£åÖÐµÄ·çÔÆµØÇø½éÉÜ£©£¬»òÕßµ½Î÷³Ç·çÔÆæäÕ¾Íõ·ç´¦×âÂí
³µ´©Ô½É³Ä®£¬£¨µ½ÄÇ¶ù¿´¿´¸æÊ¾¾ÍÖªµÀÏòÍõ·ïÎÊÊ²Ã´ÁË£©\n";
				write(n_msg);
				return 1;
		case 4: n_msg = "
ÄãÏÖÔÚµÄÈÎÎñÊÇ£¬·µ»Ø·çÔÆ³ÇÏòÌì»úÀÏÈË½»²î£¨£ñ£õ£å£ó£ô£©£¬¿ÉÒÔ´ÓÓ­Ã·¿ÍÕ»×øÂí³µ£¬
Ò²¿ÉÒÔ´Ó³ÁÏãÕòÈÆÂ·£¬ÄÇ¾ÍÒªÐ¡ÐÄ¿´¿´£è£å£ì£ð¡¡£î£å£÷£â£é£åÖÐ·çÔÆµØÇøµÄËµÃ÷ÁË¡£\n";
				write(n_msg);
				return 1;
	}		
		
// END Of Newbie QUest
	
	if(!arg || !wizardp(ob)) {
//	(1)	Player self-check
		me = this_player();
		mem = pointerp(me->query_team()) ? me->query_team() : ({ me });
		i = sizeof(mem);
		while(i--){
			if (mem[i]) {
		    	    if (mem[i] != me) {
		    	      	if(mapp(mem[i]->query("quest"))) {
		    	      		quest =  mem[i]->query("quest");
					if (quest["quest_type"] != "special") {
						msg = WHT"¶ÓÓÑ "+ mem[i]->name() + " ÏÖÔÚµÄÈÎÎñÊÇ: µ½"+quest["quest_location"]
							+"È¥"+ HIR + quest["quest_type"] + NOR WHT"¡º"NOR + quest["quest"] + NOR+ WHT "¡»£¬";	
					}else
						msg = WHT"¶ÓÓÑ "+ mem[i]->name() + " ÏÖÔÚµÄÈÎÎñÊÇ: "NOR + quest["short"] + "£¬";															
					tell_object(me, msg);
					
					nowtime = time() - mem[i]->query("quest_time");
//					time = 	quest["duration"] >= 900 ? quest["duration"] : 900;
					time = 	quest["duration"] >= 1 ? quest["duration"] : 900;
					if( nowtime  < time ) {
						tell_object(me,"±ØÐëÔÚ" + time_period(time-nowtime) + "ÄÚÍê³ÉÕâ¸öÈÎÎñ¡£\n");
					} else 
	                			write(YEL"µ«ÊÇ"+ mem[i]->name() +"ÒÑ¾­Ã»ÓÐ×ã¹»µÄÊ±¼äÀ´Íê³ÉËüÁË¡£\n"NOR);
	                	}
		    	    }
			}
		}
	
	    	if(!me->query("quest")) {
		        if((me->query("next_time")) > time()) {
			    	return notify_fail(WHT"ÄãÒª¹ý" 
		                	+ time_period(me->query("next_time") - time()) 
		                	+ "Ö®ºó²Å¿ÉÒªÈÎÎñ¡£\n"NOR);
		        }
		        else {
		       		return notify_fail(NOR"ÄãÏÖÔÚÃ»ÓÐÈÎºÎÈÎÎñ£¡\n");            
		        }
	    	}
		
		if(mapp(me->query("quest"))) {
			quest =  me->query("quest");
	        if (quest["quest_type"] != "special") {
				msg = WHT"ÄãÏÖÔÚµÄÈÎÎñÊÇ: µ½"+quest["quest_location"]+"È¥"+ HIR+ quest["quest_type"] + NOR WHT"¡º"NOR + quest["quest"] + NOR WHT"¡»£¬";	
			}else
				msg = WHT"ÄãÏÖÔÚµÄÈÎÎñÊÇ: " + quest["short"] + WHT"£¬";															              
			tell_object(me,msg);
			nowtime = (int)time() - me->query("quest_time");
//					time = 	quest["duration"] >= 900 ? quest["duration"] : 900;
					time = 	quest["duration"] >= 1 ? quest["duration"] : 900;
			if( nowtime  < time) {
				tell_object(me,"Äã±ØÐëÔÚ" + time_period(time-nowtime) + "ÄÚÍê³ÉÕâ¸öÈÎÎñ¡£\n"NOR);
			} else {
		                write("µ«ÊÇÄãÒÑ¾­Ã»ÓÐ×ã¹»µÄÊ±¼äÀ´Íê³ÉËüÁË¡£\n"NOR);
		                me->set("quest", 0 );
		                me->delete("cont_quest");	// È¥³ýÁ¬ÐøQUest¼ÇÊý
		                me->delete("annie_quest");
		                me->delete_temp("annie_quest");
		                me->delete_temp("luyu");
		                return notify_fail("Õâ¸öÈÎÎñ×Ô¶¯È¡ÏûÁË¡£\n");
			}
		} else if(!me->query("quest")) {
		        if((me->query("next_time")) > time()) {
			    return notify_fail(WHT"ÄãÒª¹ý" 
		                	+ time_period(me->query("next_time") - time()) 
		                	+ "Ö®ºó²Å¿ÉÒªÈÎÎñ¡£\n"NOR);
		        }
		        else {
		            	return notify_fail(NOR"ÄãÏÖÔÚÃ»ÓÐÈÎºÎÈÎÎñ£¡\n");            
		        }
	    	} else
	    		return notify_fail(HIR"³ÌÐò´íÎó£¬ÇëÍ¨ÖªÎ×Ê¦²ì¿´¡£\n"NOR);
		
	
	} 
// (2)	Wizard check Players' quests
	else {
	 	if(!(ob = present(arg, environment(ob))) && !(ob =  find_player(arg))) {
		return notify_fail("ÄãÒª²ì¿´Ë­µÄÈÎÎñ£¿\n");
		}
		if(!ob->query("quest")) {
                	return notify_fail(ob->name()+"ÏÖÔÚÃ»ÓÐÈÎºÎÈÎÎñ£¡\n");
		}
		if(mapp(ob->query("quest"))) {
			quest =  ob->query("quest");
               		if (quest["quest_type"] != "special") {
				msg = WHT""+ob->name() + "ÏÖÔÚµÄÈÎÎñÊÇ: µ½"+quest["quest_location"]+"È¥"+ quest["quest_type"] + "¡º"NOR + quest["quest"] + NOR WHT"¡»£¬";	
			}else
				msg = WHT""+ob->name() + "ÏÖÔÚµÄÈÎÎñÊÇ: " + quest["short"] + "£¬"NOR;	
                	write(msg);
		} 
	
		nowtime = (int)time() - ob->query("quest_time");
//					time = 	quest["duration"] >= 900 ? quest["duration"] : 900;
					time = 	quest["duration"] >= 1 ? quest["duration"] : 900;
		if( nowtime  < time) {
			write("±ØÐëÔÚ" + time_period(time-nowtime) + "ÄÚÍê³ÉÕâ¸öÈÎÎñ¡£\n"NOR);
		} else {
	                write(NOR"µ«ÊÇÒÑ¾­Ã»ÓÐ×ã¹»µÄÊ±¼äÀ´Íê³ÉËüÁË¡£\n"NOR);
		}
	}	
	return 1;
}

/*
int time_period(int timep, object me) {
	int t, d, h, m, s;
	string time;
	t = timep;
	s = t % 60;             t /= 60;
	m = t % 60;             t /= 60;
	h = t % 24;             t /= 24;
	d = t;
	
	if(d) time = chinese_number(d) + "Ìì";
	else time = "";
	
	if(h) time += chinese_number(h) + "Ð¡Ê±";
	if(m) time += chinese_number(m) + "·Ö";
	time += chinese_number(s) + "Ãë";
	tell_object(me,"±ØÐëÔÚ" + time + "Íê³ÉÕâ¸öÈÎÎñ¡£\n");
	return 1;
}*/

string time_period(int timep) {
	int t, d, h, m, s;
	string time;
	t = timep;
	s = t % 60;             t /= 60;
	m = t % 60;             t /= 60;
	h = t % 24;             t /= 24;
	d = t;
	
	if(d) time = chinese_number(d) + "Ìì";
		else time = "";
	if(h) time += chinese_number(h) + "Ð¡Ê±";
	if(m) time += chinese_number(m) + "·Ö";
	time += chinese_number(s) + "Ãë";
	
	return time;
}



int help(object me) {
	write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ : 		£ñ£õ£å£ó£ô[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m

Õâ¸öÖ¸Áî¿ÉÒÔÏÔÊ¾³öÄãºÍÄãµÄ¶ÓÓÑµ±Ç°µÄÈÎÎñ¡£

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m

HELP);
	return 1;
}
