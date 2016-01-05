// cast.c

#include <ansi.h>
#include <skill.h>
#define LOWER_LIMIT 2000
inherit F_CLEAN_UP;

int main(object me, string arg)
{
    	string spells, spl, trg;
    	object target;
 		int chance;
 		   
    	seteuid(getuid());
    
    	if( me->is_busy() )
        	return notify_fail("( ÄãÉÏÒ»¸ö¶¯×÷»¹Ã»ÓĞÍê³É£¬²»ÄÜÄîÖäÎÄ¡£)\n");
    
    	if( environment(me)->query("no_magic") || environment(me)->query("no_fight"))
        	return notify_fail("ÕâÀï²»×¼ÄîÖäÎÄ¡£\n");
    	
    	if( !arg ) return notify_fail("Ö¸Áî¸ñÊ½£ºcast <·¨Êõ> [on <Ä¿±ê>]\n");
    	if( sscanf(arg, "%s on %s", spl, trg)==2 ) {
        	target = present(trg, environment(me));
        	if(!objectp(target)) 
            		return notify_fail(" ÄãµÄÖäÎÄÒªÓÃÔÚË­ÉíÉÏ£¿\n");
		if( !target ) target = present(trg, me);
        	if( !target ) 
        		return notify_fail("ÕâÀïÃ»ÓĞ " + trg + "¡£\n");
    	} else {
        	spl = arg;
        	target = 0;
    	}

    	spl = replace_string( spl, " ", "_");
		chance = 20 - me->query_temp("marks/kongmen_adjust")*10;
    	if( stringp(spells = me->query_skill_mapped("spells")) ){
    		if (me->is_fighting() && random(1000) < chance && !me->query("boss") && !me->query("big_boss")
        		&& me->query_temp("timer/pfm_fail")+ 30 < time())// ÔÚÕ½¶·ÖĞ¡¡%2 chance of fail a perform
	        {
	        	message("vision", HIR"\n"+me->name()+HIR"ĞÄÍ·Ò»»Å£¬Â¶³öÁËºÃ´óµÄÒ»¸öÆÆÕÀ£¡£¡£¡\n"NOR,
	        		environment(me), me);
	        	tell_object(me, HIR"\nÄãĞÄÍ·Ò»»Å£¬Ã»ÓÃ³ö·¨Êõ·´¶øÂ¶³öÁË¿ÕÃÅ£¡\n"NOR);
	        	me->set_temp("timer/pfm_fail",time());
	        	me->perform_busy(3);
	        	return 1;
	        }
//        	return (int)SKILL_D(spells)->cast_spell(me, spl, target);
			if ((int)SKILL_D(spells)->cast_spell(me, spl, target)) {
				
				if (userp(me) && ANNIE_D->check_buff(me,"forceshield")) {
	        		if (me->query("force") > 300)
	        			me->set("force", me->query("force") - 300);
	        		else
	        			me->set("force",0);
	        		me->force_status_msg("force");
	        	} 
	        					
				me->force_status_msg("mana");
				return 1;
			}
			return 0;
    	}
    	return notify_fail("ÄãÇëÏÈÓÃ enable spells Ö¸ÁîÑ¡ÔñÄãÒªÊ¹ÓÃµÄÖäÎÄÏµ¡£\n");
}

int help (object me)
{
    write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ : 	cast <ÖäÊõÃû³Æ> [on <Ê©Öä¶ÔÏó>][0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

Ê©·¨±ØĞëÒªÖ¸¶¨<ÖäÊõÃû³Æ>£¬<Ê©Öä¶ÔÏó>Ôò²¢²»ÊÇËùÓĞµÄ¶¼ĞèÒª¡£

·çÔÆÖĞµÄÎä¹¦¿É¹éÎªËÄ´óÀà£º£¨·Ö±ğ¶ÔÓ¦µÄÊ¹ÓÃÃüÁîÎª£©
£¨1£©´«Í³Îä¼¼£¨ÈçÉñ»úµ¶·¨¡¢ÆåµÀĞÄ·¨£©£º£¨perform/exert£©
£¨2£©·¨Êõ£º£¨ÈçĞË¹úìøËÂµÄ°ËÊ¶ÉñÍ¨£©£º(conjure)
£¨3) ÖäÊõ£º£¨ÈçÈıÇåµÄÈıÇåµÀÊõ¡¢´óÕÑµÄ¹ÛÒôÁù×ÖÃ÷Öä£©£º(cast)
£¨4£©½µÍ·Êõ£º£¨ÈçµÛÍõ¹ÈµÄÍ¨Ìì½µ£¬ÀÇÉ½µÄÑªÀÇÖä£©£º£¨curse£©

ËùÎ½ÖäÊõ£¬Ö¸µÄÊÇSpells»ù´¡ÉÏµÄÌØÊâÖäÊõ£¬±ÈÈçÈıÇåµÄÈıÇåµÀÊõ 
(necromancy) ºÍ´óÕÑµÄ¹ÛÒôÁù×ÖÃ÷Öä£¨kwan-yin-spells£©¡£

ÔÚÊ¹ÓÃÄ³Ò»¸öÖäÊõÖ®Ç°£¬ĞëÏÈÓÃ enable Ö¸ÁîÀ´Ö¸¶¨ÒªÊ¹ÓÃµÄ·¨ÊõÏµ¡£
±ÈÈçÄãÒªÊ¹ÓÃÈıÇåµÄ¡º×ÏÓÄÖ®¼ı¡»¡²drainerbolt¡³£¬¾ÍĞèÒªÊ×ÏÈ
enable spells necromancy£¬È»ºóÔÚÕ½¶·ÖĞÊ¹ÓÃ
cast drainerbolt on xxxx

ÔÚÕ½¶·ÖĞÊ¹ÓÃÌØÊâ¼¼ÄÜÓĞ2%µÄ¿ÉÄÜ»áÊ§°Ü£¬Ôì³É×Ô¼ºÃ¦ÂÒ£¬ĞŞÏ°Ä³Ğ©
ÌØ¶¨µÄÎä¹¦¿ÉÒÔ½µµÍ´Ë¸ÅÂÊ¡£

×¢£º²»Í¬µÄÖäÊõÏµ·¨Á¦ÖÖÀà²»Í¬£¬Äã¿ÉÒÔËæÊ±×ª»»×Ô¼ºµÄÖäÊõÏµ£¬
	µ«Ğî»ıµÄ·¨Á¦»áÔİÊ±ÇåÁã¡£

Ïà¹ØÖ¸Áî: perform, exert , curse, conjure

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m    
HELP
        );
    return 1;
}
