// meditate.c

#include <skill.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    	int sen_cost=30, mana_gain;
    
    	seteuid(getuid());
	
	if (userp(me))
    		return notify_fail("´ËÖ¸ÁîÒÑ±»exerciseÈ¡´ú£¬Çëhelp exercise \n");
	
    	if(environment(me)->query("no_fight"))
        	return notify_fail("Äã²»¿ÉÒÔÔÚÕâÀïÚ¤Ë¼¡£\n");
    	if( me->is_fighting() ) return notify_fail("Õ½¶·ÖĞÚ¤Ë¼¡ª¡ªÕÒËÀÂğ£¿\n");
    	if( me->is_busy() )
        	return notify_fail("ÄãÉÏÒ»¸ö¶¯×÷»¹Ã»ÓĞÍê³É£¬²»ÄÜÚ¤Ë¼¡£\n");
    
    	if( arg && !sscanf(arg, "%d", sen_cost) )
        	return notify_fail("ÄãÒª»¨¶àÉÙ¾«ÉñÚ¤Ë¼£¿\n");
    
    	if( sen_cost < 10 ) return notify_fail("Äã×îÉÙÒª»¨ 10 µã¡¸Éñ¡¹²ÅÄÜÚ¤Ë¼¡£\n");
    
    	if( (int)me->query("sen") < sen_cost )
        	return notify_fail("ÄãÏÖÔÚ¾«ÉñÌ«²îÁË£¬½øĞĞÚ¤Ë¼½«»áÃÔÊ§£¬ÓÀÔ¶ĞÑ²»¹ıÀ´£¡\n");
    
    	if( (int)me->query("kee") * 100 / (int)me->query("max_kee") < 70 )
        	return notify_fail("ÄãÏÖÔÚÉíÌå×´¿öÌ«²îÁË£¬ÎŞ·¨¼¯ÖĞ¾«Éñ£¡£¨ÆøÑªÖµÖÁÉÙÔÚ70%ÒÔÉÏ£©\n");
    
    	if( (int)me->query("gin") * 100 / (int)me->query("max_gin") < 70 )
        	return notify_fail("ÄãÏÖÔÚÉíÌå×´¿öÌ«ĞéÈõÁË£¬ÎŞ·¨½øÈëÚ¤Ë¼µÄ×´Ì¬£¡£¨¾«Á¦ÖµÖÁÉÙÔÚ70%ÒÔÉÏ£©\n");
    
    	write("ÄãÅÌÏ¥¶ø×ø£¬¾²×øÚ¤Ë¼ÁËÒ»»á¶ù¡£\n");
    
    	me->add("sen", -sen_cost);
    	me->start_busy(1);
    // This function ranged from 1 to 15 when sen_cost = 30
    	mana_gain = sen_cost * ((int)me->query_skill("spells")/10 
                            + (int)me->query_spi() ) / 30;
    	mana_gain = (mana_gain + random(mana_gain))/5;
    
    	if( mana_gain < 1 ) {
        	write("µ«ÊÇµ±ÄãÕö¿ªÑÛ¾¦£¬Ö»¾õµÃÄÔÖĞÒ»Æ¬¿Õ°×¡£\n");
        	return 1;
    	}
    
    	me->add("mana", mana_gain );
    
    	if( (int)me->query("mana") > (int)me->query("max_mana") * 2) {
        	if( (int)me->query("max_mana") >=  ((int)me->query_skill("spells", 1) +
             			me->query_skill("spells")/5) * 5 ) {
            		write("ÄãºöÈ»¾õµÃÄÔÖĞÒ»Æ¬»ìÂÒ£¬ËÆºõ·¨Á¦µÄÌáÉıÒÑ¾­µ½ÁËÆ¿¾±¡£\n");
            		me->set("mana", 2*me->query("max_mana"));
        	} else {
            		write("ÄãµÄ·¨Á¦Ìá¸ßÁË£¡\n");
			me->add("max_mana", 1);
			me->set("mana", me->query("max_mana"));
        	}
    	}	
    	return 1;
}


int help(object me)
{
    write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ : meditate [<ºÄ·Ñ¡¸Éñ¡¹µÄÁ¿£¬Ô¤ÉèÖµ 30>][0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m 
¾²×øÚ¤Ë¼£¬½«ÓÎÀëµÄ¾«ÉñÁ¦ÓĞĞ§µØ¼¯ÖĞÄı¾Û³ÉÄÜ¹»ÓÃÀ´Ê©Õ¹·¨ÊõµÄÄÜÁ¿
£¬½åÒÔÔö¼Ó×Ô¼ºµÄ·¨Á¦¡£

´ò×øµÃµ½µÄ·¨Á¦×î´óÖµ == »ù±¾ÖäÊõµÈ¼¶*5 + µ±Ç°µÄÓĞĞ§ÖäÊõµÈ¼¶
¾ÙÀı:¡¡ÖäÊõ (spells)                           - Éî²»¿É²â 200
  ¡¡¡¡ ÖäÎÄ (spells)         £º ÂéÆÅº®Á·Êõ       ÓĞĞ§µÈ¼¶£º500  
·¨Á¦×î´óÖµ = 200*5 + 500 = 1500

Æ½¾ù×ª»¯Ğ§ÂÊ£½ £¨ÓĞĞ§ÖäÊõµÈ¼¶£¯£±£°£«ÁéĞÔ£©£¯£±£°£°

Çë²Î¿¼ help attributes.txt 
Ïà¹ØÖ¸Áî£º
	Ôö¼ÓÄÚÁ¦	£å£ø£å£ò£ã£é£ó£å	
	Ôö¼ÓÁéÁ¦	£ò£å£ó£ğ£é£ò£á£ô£å
	
	»Ö¸´ÌåÁ¦£º	£å£ø£å£ò£ô¡¡£ò£å£ã£ï£ö£å£ò
	»Ö¸´ĞÄÉñ£º	£å£ø£å£ò£ô¡¡£ò£å£æ£ò£å£ó£è
	»Ö¸´¾«Á¦£º	£å£ø£å£ò£ô¡¡£ò£å£ç£å£î£å£ò£á£ô£å
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
HELP
        );
    return 1;
}
