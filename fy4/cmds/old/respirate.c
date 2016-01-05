// respirate.c

#include <skill.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    	int gin_cost=30, atman_gain;
    	string magic_skill;
    
    	seteuid(getuid());
    
    	if (userp(me))
    		return notify_fail("´ËÖ¸ÁîÒÑ±»exerciseÈ¡´ú£¬Çëhelp exercise \n");
    		
    	if(environment(me)->query("no_fight"))
        	return notify_fail("Äã²»¿ÉÒÔÔÚÕâÀïĞŞĞĞ¡£\n");
    	if( me->is_fighting() )
        	return notify_fail("Õ½¶·Ò²ÊÇÒ»ÖÖĞŞĞĞ£¬µ«²»ÄÜºÍÁéÁ¦µÄĞŞĞĞÍ¬Ê±½øĞĞ¡£\n");
    	if( me->is_busy() )
        	return notify_fail("ÄãÉÏÒ»¸ö¶¯×÷»¹Ã»ÓĞÍê³É£¬²»ÄÜĞŞĞĞ¡£\n");
    
    	if( arg && !sscanf(arg, "%d", gin_cost) )
        	return notify_fail("ÄãÒª»¨¶àÉÙ¾«Á¦ĞŞĞĞ£¿\n");
    
    	if( gin_cost < 10 ) return notify_fail("Äã×îÉÙÒª»¨ 10 µã¾«Á¦²ÅÄÜ½øĞĞĞŞĞĞ¡£\n");
    
    	if( (int)me->query("gin") < gin_cost )
        	return notify_fail("ÄãÏÖÔÚ¾«Á¦²»×ã£¬ÎŞ·¨ĞŞĞĞÁéÁ¦£¡\n");
    
    	if( (int)me->query("kee") * 100 / (int)me->query("max_kee") < 70 )
        	return notify_fail("ÄãÏÖÔÚÉíÌå×´¿öÌ«²îÁË£¬ÎŞ·¨¼¯ÖĞ¾«Éñ£¡£¨ÆøÑªÖµÖÁÉÙÔÚ70%ÒÔÉÏ£©\n");
    
    	if( (int)me->query("sen") * 100 / (int)me->query("max_sen") < 70 )
        	return notify_fail("ÄãÏÖÔÚ¾«Éñ×´¿öÌ«²îÁË£¬ÎŞ·¨¿ØÖÆ×Ô¼ºµÄĞÄÁé£¡£¨ĞÄÉñÖµÖÁÉÙÔÚ70%ÒÔÉÏ£©\n");
    
    	write("ÄãÅÌÏ¥¶ø×ø£¬±ÕÉÏÑÛ¾¦¿ªÊ¼Äı¾ÛË¼Ğ÷¡£\n");
    	me->start_busy(1);
    	me->add("gin", -gin_cost);
    
    	// This function ranged from 1 to 15 when gin_cost = 30
    	atman_gain = gin_cost * ((int)me->query_skill("magic")/10 + (int)me->query_int() ) / 30;
    	atman_gain = (atman_gain + random(atman_gain))/5;
    
    	if( atman_gain < 1 ) {
        	write("µ«ÊÇÄãÒ»²»Ğ¡ĞÄÈ´Ë¯ÖøÁË¡£\n");
        	return 1;
    	}
    
    	me->add("atman", atman_gain );
    
    	if( (int)me->query("atman") > (int)me->query("max_atman") * 2) {
        	if( (int)me->query("max_atman") >= ((int)me->query_skill("magic", 1) +
             					me->query_skill("magic")/5) * 5 ) {
            		write("Äã¾õµÃÒ»ÕóÌìĞıµØ×ª£¬Í·ÕÇµÃÏñÒªÁÑ¿ªÒ»Ñù£¬ËÆºõÁéÁ¦µÄĞŞĞĞÒÑ¾­Óöµ½ÁËÆ¿¾±¡£\n");
        		me->set("atman", 2*me->query("max_atman"));	
        	} else {
            		write("ÄãµÄÁéÁ¦Ìá¸ßÁË£¡\n");
            		me->add("max_atman", 1);
            		me->set("atman", me->query("max_atman"));
        	}
        }	
    	return 1;
}

int help(object me)
{
    write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ : respirate [<ºÄ·Ñ¡¸¾«¡¹µÄÁ¿£¬Ô¤ÉèÖµ 30>][0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m 
´ò×øĞŞĞĞ£¬ÀûÓÃ¡¸Á¶¾«»¯Æø£¬Á¶Æø»¯Éñ£¬Á¶Éñ»¹Ğé¡¹µÄ·½·¨½«ÄãµÄ¾«Á¦
×ª±ä³ÉÁéÁ¦¡£

´ò×øµÄµÃµ½µÄÁéÁ¦×î´óÖµ == »ù±¾·¨ÊõµÈ¼¶*5 + µ±Ç°µÄÓĞĞ§·¨ÊõµÈ¼¶
¾ÙÀı:	 ·¨Êõ (magic)                        - ³öÉñÈë»¯  150
 	¡¡·¨Êõ (magic)     £º Ç¬À¤ÎŞĞÎ         ÓĞĞ§µÈ¼¶£º275 
ÁéÁ¦×î´óÖµ = 150*5 + 275 = 1025

Æ½¾ù×ª»¯Ğ§ÂÊ£½ £¨ÓĞĞ§·¨ÊõµÈ¼¶£¯£±£°£«²ÅÖÇ£©£¯£±£°£°

Çë²Î¿¼ help attributes.txt
Ïà¹ØÖ¸Áî£º
	Ôö¼ÓÄÚÁ¦	£å£ø£å£ò£ã£é£ó£å	
	Ôö¼Ó·¨Á¦	£í£å£ä£é£ô£á£ô£å
	
	»Ö¸´ÌåÁ¦£º	£å£ø£å£ò£ô¡¡£ò£å£ã£ï£ö£å£ò
	»Ö¸´ĞÄÉñ£º	£å£ø£å£ò£ô¡¡£ò£å£æ£ò£å£ó£è
	»Ö¸´¾«Á¦£º	£å£ø£å£ò£ô¡¡£ò£å£ç£å£î£å£ò£á£ô£å
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
HELP
        );
    return 1;
}
