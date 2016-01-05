// fight.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 
// Last modification:
//		- 06/28/2001 by Daniel Q. Yu.
//

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj, old_target;
	seteuid(getuid());
	
	if(!arg || !objectp(obj = present(arg, environment(me))))
		return notify_fail("ÄãÏë¹¥»÷Ë­£¿\n");
	
	if( !wizardp(me) && environment(me)->query("no_fight") && !obj->query("practice_dummy"))
		return notify_fail("ÕâÀï½ûÖ¹Õ½¶·¡£\n");

	if( !obj->is_character() )
		return notify_fail("¿´Çå³şÒ»µã£¬ÄÇ²¢²»ÊÇÉúÎï¡£\n");

	if( obj->is_fighting(me) )
		return notify_fail("¼ÓÓÍ£¡¼ÓÓÍ£¡¼ÓÓÍ£¡\n");

	if( !living(obj) )
		return notify_fail(obj->name() + "ÒÑ¾­ÎŞ·¨Õ½¶·ÁË¡£\n"); 

	if(obj==me)	return notify_fail("Äã²»ÄÜ¹¥»÷×Ô¼º¡£\n");
	if( userp(obj) ){
		if((object)obj->query_temp("pending/fight")!=me ) {
			message_vision("\n$N¶ÔÖø$nËµµÀ£º" 
				+ RANK_D->query_self(me) 
				+ me->name() + "£¬Áì½Ì"
				+ RANK_D->query_respect(obj) 
				+ "µÄ¸ßÕĞ£¡\n\n", me, obj);
			if( objectp(old_target = me->query_temp("pending/fight")) )
				tell_object(old_target, YEL + me->name() + "È¡ÏûÁËºÍÄã±ÈÊÔµÄÄîÍ·¡£\n" NOR);
			me->set_temp("pending/fight", obj);
			tell_object(obj, YEL "Èç¹ûÄãÔ¸ÒâºÍ¶Ô·½½øĞĞ±ÈÊÔ£¬ÇëÄãÒ²¶Ô" + me->name() + "("+(string)me->query("id")+")"+ "ÏÂÒ»´Î fight Ö¸Áî¡£\n" NOR);
			write(YEL "ÓÉì¶¶Ô·½ÊÇÓÉÍæ¼Ò¿ØÖÆµÄÈËÎï£¬Äã±ØĞëµÈ¶Ô·½Í¬Òâ²ÅÄÜ½øĞĞ±ÈÊÔ¡£\n" NOR);
			return 1;
		} else {
			message_vision("\n$N¶ÔÖø$nËµµÀ£º" 
					+ RANK_D->query_self(me) 
					+ me->name() 
					+ "£¬Áì½Ì" + RANK_D->query_respect(obj) 
					+ "µÄ¸ßÕĞ£¡\n\n", me, obj);
			me->fight_ob(obj);
			obj->fight_ob(me);
		}
	} else {
		if( obj->query("can_speak") ) {
			message_vision("\n$N¶ÔÖø$nËµµÀ£º" 
					+ RANK_D->query_self(me) 
					+ me->name() + "£¬Áì½Ì"
					+ RANK_D->query_respect(obj) 
					+ "µÄ¸ßÕĞ£¡\n\n", me, obj);
			if( !userp(obj) && !obj->accept_fight(me) ) {
				tell_object(me,"¿´ÆğÀ´" + obj->name() + "²¢²»Ïë¸úÄã½ÏÁ¿¡£\n");
				return 1;
			} else {
				me->fight_ob(obj);
				obj->fight_ob(me);
			}
		} else {
			if (!COMBAT_D->legitimate_kill(me, obj)) {
				if (stringp(obj->query("NO_KILL")))
					return notify_fail(obj->query("NO_KILL"));
			}
			message_vision("\n$N´óºÈÒ»Éù£¬¿ªÊ¼¶Ô$n·¢¶¯¹¥»÷£¡\n\n", me, obj);
			me->fight_ob(obj);
			obj->kill_ob(me);
		}
	}
	return 1;
}
int help(object me)
{
  write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ : 	 fight <ÈËÎï>[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   
 
Õâ¸öÖ¸ÁîÈÃÄãÏòÒ»¸öÈËÎï¡¸ÌÖ½Ì¡¹»òÕßÊÇ¡¸ÇĞ´èÎäÒÕ¡¹£¬ÕâÖÖĞÎÊ½µÄÕ½¶·
´¿´âÊÇµãµ½ÎªÖ¹£¬Òò´Ë²»»áÖÂÃü£¬µ«ÊÇ²¢²»ÊÇËùÓĞµÄNPC ¶¼Ï²»¶´ò¼Ü£¬Òò
´ËÓĞĞí¶àÊ±ºòÄãµÄ±ÈÎäÒªÇó»á±»¾Ü¾ø¡£Òª×¢ÒâµÄÊÇ£¬¼´Ê¹ÔÚ±ÈÎäÖĞ£¬Å¼¶û
Ò²»áÓĞ³öÊÖ¹ıÖØ¶øÖÂÈËËÀÍöÖ®Àı¡£
 
ÆäËûÏà¹ØÖ¸Áî: kill

PS. Èç¹û¶Ô·½²»Ô¸Òâ½ÓÊÜÄãµÄÌôÕ½£¬ÄãÈÔÈ»¿ÉÒÔåÉĞĞÓÃ kill Ö¸Áî¿ªÊ¼
	Õ½¶·£¬ÓĞ¹Ø fight ¸ú kill µÄÇø·ÖÇë¿´ 'help combat'.

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

HELP
    );
    return 1;
}
 
