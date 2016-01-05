// vote.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 
#include <ansi.h>
#include <vote.h>
inherit F_CLEAN_UP;

int main(object me, string arg) {
	string who,what;
	string msg;
	object victim;
	int result;
	int diff;
	
	seteuid(getuid());
	if((int)me->query("mud_age") < NEW_PERIOD) {
		return notify_fail("Äã»¹Ã»ÓĞµ½ÄÜÍ¶Æ±µÄÄê¼Í£¡\n");
	}	
	if((int)me->query("level") < NEW_LEVEL) {
		return notify_fail("¹úÄÚÕ¾¹æ¶¨Íæ¼ÒµÈ¼¶±ØĞë´ïµ½"+NEW_LEVEL+"£¡\n");
	}
	if(!arg) {
		return notify_fail("Ö¸Áî¸ñÊ½£ºvote <what> on <who>\n");
	}
	if(sscanf(arg,"%s on %s",what,who)	!= 2) {
		return notify_fail("Ö¸Áî¸ñÊ½£ºvote <what> on <who>\n");
	}
	if(!objectp(victim = find_player(who)) || !userp(victim)) {
		return notify_fail("ß×£®£®£®ÓĞÕâ¸öÈËÂğ£¿\n");
	}
	if(me==victim) {
		return notify_fail("Äã²»¿ÉÒÔÍ¶×Ô¼ºµÄÆ±£¡\n");
	}
	if(wizardp(victim)) {
		return notify_fail("Äã²»¿ÉÒÔ°ş¶áËû/ËıµÄÈÎºÎÈ¨Á¦£¡\n");
	}
	log_file("VOTE",sprintf("%s:%s(%s)[%s] vote %s on %s(%s)\n",
			ctime(time()),me->name(1),me->query("id"),
			query_ip_number(me),
			what,victim->name(1),victim->query("id")));	
	switch(what) {
		case "kickout":
			result = VOTE_D->add_vote(me,what,who);
			if(!result) {
				return notify_fail("ÒÑ¾­ÓĞÈË´ÓÄãÁ¬ÏßµÄÓòÃûÍ¶¹ıÆ±ÁË£¡\n");
			}
			if((diff = KICKOUT_NO - result) > 0) {
				CHANNEL_D->do_sys_channel("vote",sprintf(
						"%s(%s)Í¶Æ±°ş¶á%s(%s)½øÈë·çÔÆµÄÈ¨Àû£¬»¹²î%sÆ±¡£",
						me->name(1),
						me->query("id"),
						victim->name(1),
						victim->query("id"),
						chinese_number(diff)));
			} else {
				CHANNEL_D->do_sys_channel("vote",sprintf(
						"%s(%s)Í¶Æ±°ş¶á%s(%s)½øÈë·çÔÆµÄÈ¨Àû£¬±í¾öÍ¨¹ı¡£",
						me->name(1),
						me->query("id"),
						victim->name(1),
						victim->query("id")));
				victim->set("kickout_time",time());
				victim->save();
				victim->ccommand("quit");
				seteuid(ROOT_UID);
				if (victim)	destruct(victim);
				VOTE_D->matter_finalized(what,who);
			}
			break;
		case "chblk":
			if(victim->query("chblk_on")) {
				return notify_fail("Ëû/ËıÒÑ¾­±»°ş¶áÁËÊ¹ÓÃ¹«¹²ÆµµÀµÄÈ¨Á¦£¡\n");
			}
			result = VOTE_D->add_vote(me,what,who);
			if(!result) {
				return notify_fail("ÒÑ¾­ÓĞÈË´ÓÄãÁ¬ÏßµÄÓòÃûÍ¶¹ıÆ±ÁË£¡\n");
			}
			if((diff = CHBLK_NO - result) > 0) {
				CHANNEL_D->do_sys_channel("vote",sprintf(
						"%s(%s)Í¶Æ±°ş¶á%s(%s)Ê¹ÓÃ¹«¹²ÆµµÀµÄÈ¨Àû£¬»¹²î%sÆ±¡£",
						me->name(1),
						me->query("id"),
						victim->name(1),
						victim->query("id"),
						chinese_number(diff)));
			} else {
				CHANNEL_D->do_sys_channel("vote",sprintf(
						"%s(%s)Í¶Æ±°ş¶á%s(%s)Ê¹ÓÃ¹«¹²ÆµµÀµÄÈ¨Àû£¬±í¾öÍ¨¹ı¡£",
						me->name(1),
						me->query("id"),
						victim->name(1),
						victim->query("id")));
				victim->set("chblk_on",1);
				victim->save();
				VOTE_D->matter_finalized(what,who);
			}
			break;
		case "chnoblk":
			if(!victim->query("chblk_on")) {
				return notify_fail("Ëû/ËıÃ»ÓĞ±»°ş¶áÁËÊ¹ÓÃ¹«¹²ÆµµÀµÄÈ¨Á¦£¡\n");
			}
			result = VOTE_D->add_vote(me,what,who);
			if(!result) {
				return notify_fail("ÒÑ¾­ÓĞÈË´ÓÄãÁ¬ÏßµÄÓòÃûÍ¶¹ıÆ±ÁË£¡\n");
			}
			if((diff = CHNOBLK_NO - result) > 0) {
				CHANNEL_D->do_sys_channel("vote",sprintf(
						"%s(%s)Í¶Æ±¸øÓè%s(%s)Ê¹ÓÃ¹«¹²ÆµµÀµÄÈ¨Àû£¬»¹²î%sÆ±¡£",
						me->name(1),
						me->query("id"),
						victim->name(1),
						victim->query("id"),
						chinese_number(diff)));
			} else {
				CHANNEL_D->do_sys_channel("vote",sprintf(
						"%s(%s)Í¶Æ±¸øÓè%s(%s)Ê¹ÓÃ¹«¹²ÆµµÀµÄÈ¨Àû£¬±í¾öÍ¨¹ı¡£",
						me->name(1),
						me->query("id"),
						victim->name(1),
						victim->query("id")));
				victim->delete("chblk_on");
				victim->save();
				VOTE_D->matter_finalized(what,who);
			}
			break;
		default:
			return notify_fail("Ö¸Áî¸ñÊ½£ºvote <what> on <who>\n");
			break;
	}
	return 1;
}

int help(object me) {
	write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ : 	vote <what> on <who>[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

ÕâÌõÖ¸ÁîÊÇÖÚÍæ¼ÒÔÚÃ»ÓĞ¹ÜÀíÈËÔ±ÔÚÏßµÄÊ±ºòÀ´´¦Àí
Î¥·´·çÔÆÌìÌõµÄÈËµÄ£¬ĞèÒªÔÚÎå·ÖÖÓÄÚÓĞ×ã¹»Æ±Êı²Å¿ÉÒÔÉúĞ§¡£

ÆäÖĞ<what>¿ÉÒÔÊÇÒÔÏÂÖĞµÄÒ»Ïî£º

kickout:	°ş¶á½øÈë·çÔÆµÄÈ¨Àû£¨ĞèÒªÊ®ÎåÆ±£©
chblk:		°ş¶áÊ¹ÓÃ¹«¹²ÆµµÀµÄÈ¨Á¦£¨ĞèÒªÆßÆ±£©
chnoblk:	¸øÓèÊ¹ÓÃ¹«¹²ÆµµÀµÄÈ¨Á¦£¨ĞèÒªÎåÆ±£©

×¢£ºËùÓĞµÄÍ¶Æ±»î¶¯¶¼ÓĞ¼ÇÂ¼£¬·²ÊÇÀÄÓÃÍ¶Æ±µÄÈËÒ»¾­²ì³ö¶¼»á
°´ÕÕ·çÔÆÌìÌõ´¦ÖÃ£¡

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
HELP);
	return 1;
}
