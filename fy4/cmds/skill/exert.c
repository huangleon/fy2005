// exert.c

#include <skill.h>
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
    	string force;
    	int result, amount, pass,chance;
    	string arg1;
    	
    	seteuid(getuid());
    
    	if( environment(me)->query("no_magic")||environment(me)->query("no_fight") )
        	return notify_fail("Äã²»¿ÉÒÔÔÚÕâÀïÓÃÄÚ¹¦¡£\n");
    	if( me->is_busy() )
        	return notify_fail("ÄãÉÏÒ»¸ö¶¯×÷»¹Ã»ÓÐÍê³É£¬²»ÄÜÊ©ÓÃÄÚ¹¦¡£\n"); 
    	if( !arg ) return notify_fail("ÄãÒªÓÃÄÚ¹¦×öÊ²÷á£¿\n");
    
    	if( stringp(force = me->query_skill_mapped("force")) )
    	{
        	notify_fail("ÄãËùÑ§µÄÄÚ¹¦ÖÐÃ»ÓÐÕâÖÖ¹¦ÄÜ¡£\n");
        	
        	if (sscanf(arg,"%s %d", arg1, amount)== 2) {
        		if (arg1 == "qi" || arg1 == "shen" || arg1 == "jing")
        			pass = 1;
        	} else if (sscanf(arg,"%s",arg1)==1) {
        		if (arg1 == "qi" || arg1 == "shen" || arg1 == "jing")
        			pass = 1;
        	}
        	chance = 20 - me->query_temp("marks/kongmen_adjust")*10;        	
        	if (me->is_fighting() && random(1000) < chance && !me->query("boss") && !me->query("big_boss")
        		&& me->query_temp("timer/pfm_fail")+ 30 < time()
        		&& !pass )// ÔÚÕ½¶·ÖÐ¡¡%2 chance of fail a perform, and let ppl exert recover
	        {
	        	message("vision", HIR"\n"+me->name()+HIR"ÕæÆøÒ»²í£¬Â¶³öÁËºÃ´óµÄÒ»¸öÆÆÕÀ£¡£¡£¡\n"NOR,
	        		environment(me), me);
	        	tell_object(me, HIR"\nÄãÕæÆøÒ»²í£¬Ã»ÓÃ³ö¾øÕÐ·´¶øÂ¶³öÁË¿ÕÃÅ£¡\n"NOR);
	        	me->set_temp("timer/pfm_fail",time());
	        	me->perform_busy(3);
	        	return 1;
	        }
        	if( SKILL_D(force)->exert_function(me, arg) )        {
            	if (!me->is_fighting() && me->query_busy()<1)
            		me->start_busy(1);
            	me->force_status_msg("force");
            	return 1;
        	}
        	return 0;
    	}
    	return notify_fail("ÄãÇëÏÈÓÃ enable Ö¸ÁîÑ¡ÔñÄãÒªÊ¹ÓÃµÄÄÚ¹¦¡£\n");
}


int help (object me)
{
    write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½£ºexert <¹¦ÄÜÃû³Æ> [<Ê©ÓÃ¶ÔÏó>] [<ÄÚÁ¦µãÊý>] [0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
ÓÃÄÚÁ¦½øÐÐÒ»Ð©ÌØÒì¹¦ÄÜ£¬Äã±ØÐëÒªÖ¸¶¨<¹¦ÄÜÃû³Æ>£¬<Ê©ÓÃ¶ÔÏó>Ôò¿ÉÓÐ
¿ÉÎÞ¡£ÔÚÄãÊ¹ÓÃÄ³Ò»ÖÖÄÚ¹¦µÄÌØÒì¹¦ÄÜÖ®Ç°£¬Äã±ØÐëÏÈÓÃ enable Ö¸ÁîÀ´
Ö¸¶¨ÄãÒªÊ¹ÓÃµÄÄÚ¹¦¡££¨Èç¹ûÄã¸Ä±ä×Ô¼ºµÄÄÚ¹¦£¬ÄãÔ­±¾Ðî»ýµÄÄÚÁ¦²¢²»
ÄÜÖ±½Ó×ª»»¹ýÈ¥£¬±ØÐë´Ó0¿ªÊ¼¡££©

ÄÚ¹¦µÄÌØÊâ¹¦ÓÃ¿É¼û¸÷ÃÅÅÉµÄ¾ßÌå½éÉÜ¡£

ËùÓÐÃÅÅÉÄÚ¹¦¶¼¾ßÓÐµÄ¹¦ÄÜ£º
	»Ö¸´ÌåÁ¦£º	£å£ø£å£ò£ô £ñ£é
	»Ö¸´ÐÄÉñ£º	£å£ø£å£ò£ô £ó£è£å£î
	»Ö¸´¾«Á¦£º	£å£ø£å£ò£ô £ê£é£î£ç
	ÖÎÁÆÍâÉË£º	£å£ø£å£ò£ô £è£å£á£ì (ÓÐÒ»²¿·ÖÄÚ¹¦ÎÞ´Ë¹¦ÄÜ£©
ÌåÁ¦£¯ÐÄÉñ£¯¾«Á¦Æ½¾ù»Ö¸´Öµ£½ £¨£±£°£«ÓÐÐ§ÄÚ¹¦µÈ¼¶£¯£±£°£©£ªºÄ·ÑÄÚÁ¦£ª£¯£²£°

ÔÚÕ½¶·ÖÐÊ¹ÓÃÌØÊâ¼¼ÄÜÓÐ2%µÄ¿ÉÄÜ»áÊ§°Ü£¬Ôì³É×Ô¼ºÃ¦ÂÒ£¬ÐÞÏ°Ä³Ð©
ÌØ¶¨µÄÎä¹¦¿ÉÒÔ½µµÍ´Ë¸ÅÂÊ¡£

Ïà¹ØÖ¸Áî£º
	»Ö¸´ÄÚÁ¦£º	£å£ø£å£ò£ã£é£ó£å¡¡£ñ£é
	»Ö¸´·¨Á¦£º	£å£ø£å£ò£ã£é£ó£å¡¡£ó£è£å£î
	»Ö¸´ÁéÁ¦£º	£å£ø£å£ò£ã£é£ó£å¡¡£ê£é£î£ç
	
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
HELP
        );
    return 1;
}
