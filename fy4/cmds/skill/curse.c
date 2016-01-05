#include <ansi.h>
#include <skill.h>
#define LOWER_LIMIT 2000
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	string curse, spl, trg;
	object target;
	int chance;
	
	seteuid(getuid());

	if( me->is_busy() )
		return notify_fail(" ÄãÉÏÒ»¸ö¶¯×÷»¹Ã»ÓĞÍê³É£¬²»ÄÜÏÂ½µÍ·¡£\n");

	if( environment(me)->query("no_magic") )
		return notify_fail("ÕâÀï²»×¼ÏÂ½µÍ·¡£\n");
		
	if( environment(me)->query("no_fight") )
		return notify_fail("ÕâÀï²»×¼ÏÂ½µÍ·¡£\n");
		
	if( environment(me)->query("no_curse") )
		return notify_fail("ÕâÀï²»×¼ÏÂ½µÍ·¡£\n");
		
//	if (me->query_temp("till_death/lockup")==1)
//    		return notify_fail(" £¨ÄãÑªÂö²»³©£¬ÕæÆøÊÜÖÍ£¬Ò»Ê±¾¹È»ÏÂ²»ÁË½µÍ·¡££©\n");  

	if( !arg ) return notify_fail("Ö¸Áî¸ñÊ½£ºcurse <½µÍ·> [on <Ä¿±ê>]\n");
	if( sscanf(arg, "%s on %s", spl, trg)==2 ) {
		target = present(trg, environment(me));
                if(!objectp(target)) 
	 		return notify_fail(" ÄãµÄ½µÍ·ÒªÓÃÔÚË­ÉíÉÏ£¿\n");
		if( !target ) target = present(trg, me);
		if( !target ) return notify_fail("ÕâÀïÃ»ÓĞ " + trg + "¡£\n");
	} else {
		spl = arg;
		target = 0;
	}
	chance = 20 - me->query_temp("marks/kongmen_adjust")*10;
	spl = replace_string( spl, " ", "_");
	if( stringp(curse= me->query_skill_mapped("cursism")) ){
		if (me->is_fighting() && random(1000)<chance && !me->query("boss") && !me->query("big_boss")
        		&& me->query_temp("timer/pfm_fail")+ 30 < time())// ÔÚÕ½¶·ÖĞ¡¡%2 chance of fail a perform
	        {
	        	message("vision", HIR"\n"+me->name()+HIR"ĞÄÍ·Ò»»Å£¬Â¶³öÁËºÃ´óµÄÒ»¸öÆÆÕÀ£¡£¡£¡\n"NOR,
	        		environment(me), me);
	        	tell_object(me, HIR"\nÄãĞÄÍ·Ò»»Å£¬Ã»ÓÃ³ö·¨Êõ·´¶øÂ¶³öÁË¿ÕÃÅ£¡\n"NOR);
	        	me->set_temp("timer/pfm_fail",time());
	        	me->perform_busy(3);
	        	return 1;
	        }
		if ((int)SKILL_D(curse)->curse_curses(me, spl, target)) {
			if (userp(me) && ANNIE_D->check_buff(me,"forceshield")) {
        		if (me->query("force") > 300)
        			me->set("force", me->query("force") - 300);
        		else
        			me->set("force",0);
        	}
			me->force_status_msg("force");
			return 1;
		}
		return 0;
	}	
	return notify_fail("ÇëÏÈÓÃ enable curseÖ¸ÁîÑ¡ÔñÄãÒªÊ¹ÓÃµÄ½µÍ·ÊõÌåÏµ¡£\n");
}

int help (object me)
{
        write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ : 	curse <½µÍ·> [on <Ê©Êõ¶ÔÏó>][0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

Ê©½µÍ·±ØĞëÒªÖ¸¶¨<½µÍ·Ãû³Æ>£¬<Ê©Êõ¶ÔÏó>Ôò²¢²»ÊÇËùÓĞµÄ¶¼ĞèÒª¡£

·çÔÆÖĞµÄÎä¹¦¿É¹éÎªËÄ´óÀà£º£¨·Ö±ğ¶ÔÓ¦µÄÊ¹ÓÃÃüÁîÎª£©
£¨1£©´«Í³Îä¼¼£¨ÈçÉñ»úµ¶·¨¡¢ÆåµÀĞÄ·¨£©£º£¨perform/exert£©
£¨2£©·¨Êõ£º£¨ÈçĞË¹úìøËÂµÄ°ËÊ¶ÉñÍ¨£©£º(conjure)
£¨3) ÖäÊõ£º£¨ÈçÈıÇåµÄÈıÇåµÀÊõ¡¢´óÕÑµÄ¹ÛÒôÁù×ÖÃ÷Öä£©£º(cast)
£¨4£©½µÍ·Êõ£º£¨ÈçµÛÍõ¹ÈµÄÍ¨Ìì½µ£¬ÀÇÉ½µÄÑªÀÇÖä£©£º£¨curse£©

ËùÎ½½µÍ·£¬Ö¸µÄÊÇcursism»ù´¡ÉÏµÄÌØÊâ½µÍ·Êõ£¬ÈçµÛÍõ¹ÈµÄÍ¨Ìì½µ¡£

ÔÚÊ¹ÓÃÄ³Ò»¸ö½µÍ·Ö®Ç°£¬ĞëÏÈÓÃ enable Ö¸ÁîÀ´Ö¸¶¨ÒªÊ¹ÓÃµÄ½µÍ·Ïµ¡£
±ÈÈçÄãÒªÊ¹ÓÃµÛÍõ¹ÈµÄÍ¨Ìì½µ£¨celecurse£©ÖĞµÄ¡ºÑª½µ¡»£¨bloodcurse£©
¾ÍĞèÒªÊ×ÏÈ
enable cursism celecurse
cast bloodcurse on xxxx

Ïà¹ØÖ¸Áî: perform, exert , conjure, cast

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m     
HELP
        );
        return 1;
}
