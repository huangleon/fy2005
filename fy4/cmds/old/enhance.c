// enhance.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int points, to_pay,to_pay_exp;
	int enhanced = 0, price = 1;
	int base_exp = 50000;
	int base_pot = 10000;
	string msg, addthis;

	if( !arg ) return notify_fail("ÄãÒªÌá¸ßÄÄÒ»ÏîÊôĞÔ£¿\n");
	
//	points = me->query("potential") - me->query("learned_points");
	points = me->query("enhance/pot_save");
	
//	if (me->query("enhance/num")>10)
//		return notify_fail("ÄãÌá¸ßÊôĞÔµÄ´ÎÊı²»ÄÜ³¬¹ı10´Î¡£\n");
	
	if( (int) me->query("combat_exp") < 4000000 )
		return notify_fail("ÄãµÄ¾­ÑéÌ«µÍ£¬»¹²»ÄÜ¹»Ìá¸ßÈÎºÎÊôĞÔ¡£\n");
	
	if( points < 30000 )
		return notify_fail("Äã´æÈë(enhancesave)µÄÇ±ÄÜ²»¹»Ìá¸ßÈÎºÎÊôĞÔ¡£\n");

	if(me->is_busy())
		return notify_fail("ÄãÉÏ¸ö¶¯×÷»¹Ã»Íê³É¡£\n");

	switch (arg) {
	case "²ÅÖÇ" :
	case "caizhi" :
			enhanced =  me->query("enhance/int");
			msg = "²ÅÖÇ";
			addthis = "int";
			to_pay= 90000;
			to_pay_exp=400000;
			break;
        case "Á¦Á¿" :
        case "liliang" :
                        enhanced =  me->query("enhance/str");
                        msg = "Á¦Á¿";
                        to_pay= 90000;
			to_pay_exp=400000;
                        addthis = "str";
                        break;         
        case "ÄÍÁ¦" :
        case "naili" :
                        enhanced =  me->query("enhance/dur");
                        msg = "ÄÍÁ¦";
                        to_pay= 80000;
			to_pay_exp=300000;
                        addthis = "dur";
                        break;
        case "ÌåÖÊ" :
        case "tizhi" :
                        enhanced =  me->query("enhance/con");
                        msg = "ÌåÖÊ";
                        to_pay= 80000;
			to_pay_exp=300000;
                        addthis = "con";
                        break;
        case "ÓÂÆø" :
        case "yongqi" :
                        enhanced =  me->query("enhance/cor");
                        msg = "ÓÂÆø";
                        to_pay= 80000;
			to_pay_exp=300000;
                        addthis = "cor";
                        break;
        case "ÈÍĞÔ" :
        case "renxing" :
                        enhanced =  me->query("enhance/fle");
                        msg = "ÈÍĞÔ"; 
                        to_pay= 80000;
			to_pay_exp=200000;
                        addthis = "fle";
                        break;
        case "ÔËÆø" :
        case "yunqi" :
                        enhanced =  me->query("enhance/kar");
                        msg =  "ÔËÆø";
                        to_pay= 80000;
			to_pay_exp=200000;
                        addthis = "kar";
                        break;
        case "ÁéĞÔ" :
        case "lingxing" :
                        enhanced =  me->query("enhance/spi");
                        msg = "ÁéĞÔ";    
                        to_pay= 30000;
			to_pay_exp=100000;
                        addthis = "spi";
                        break;
        case "÷ÈÁ¦" :
        case "meili" :
                        enhanced =  me->query("enhance/per");
                        msg = "÷ÈÁ¦";
                        to_pay= 30000;
			to_pay_exp=100000;
                        addthis = "per";
                        break;
        case "ËÙ¶È" :
        case "sudu" :                 
                        enhanced =  me->query("enhance/agi");
                        msg = "ËÙ¶È";
                        to_pay= 30000;
			to_pay_exp=100000;
                        addthis = "agi";
                        break;
        case "ÆøÁ¿" :
        case "qiliang" :                    
                        enhanced =  me->query("enhance/tol");
                        msg =  "ÆøÁ¿";
                        to_pay= 30000;
			to_pay_exp=100000;
                        addthis = "tol";
                        break;
        case "¶¨Á¦" :
        case "dingli" :
                        enhanced =  me->query("enhance/cps");
                        msg = "¶¨Á¦";
                        to_pay= 30000;
			to_pay_exp=100000;
                        addthis = "cps";
                        break;
        default :
			return notify_fail("Ã»ÓĞÕâ¸ö²ÎÊı¡£\n");

	}

	if (enhanced>4)
		return notify_fail("ÄãÒÑ¾­²»ÄÜ¼ÌĞøÌá¸ß"+msg+"ÁË¡£\n");
	
	enhanced=enhanced? enhanced*2:1;
	
	if (points < to_pay*enhanced) 
		return notify_fail("Äã´æÈë(enhancesave)µÄÇ±ÄÜ²»¹»Ìá¸ß"+msg+"¡£\n");
		
	me->add("enhance/" + addthis, 1);
	me->add(addthis, 1);
	me->add("enhance/pot_save",-to_pay*enhanced);
	me->add("combat_exp", -to_pay_exp*enhanced);
	me->add("enhance/num",1);
	write("ÄãµÄ" + msg + "Ìá¸ßÁË£¡\n");
	me->start_busy(1);
	return 1;
}

int help(object me)
{
        write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ : 	enhance <×ÔÉíÊôĞÔ>[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m           

Ö¸Áî¸ñÊ½ : enhance <ÈËÌå²ÎÊı>
Õâ¸öÖ¸Áî¿ÉÒÔÈÃÄã½«´æ´¢µÄÇ±ÄÜ£¨enhancesave£©ºÍ¾­ÑéÓÃÓÚÌá¸ßÄã
Ö¸¶¨µÄ²ÎÊı¡£ĞèÒª¾­ÑéÖµ´óÓÚ4M²ÅÄÜÊ¹ÓÃ¡£

µÚÒ»´ÎÊ¹ÓÃ£º

²ÅÖÇ/Á¦Á¿
enhance Á¦Á¿ ÈÃÄã½«90000Ç±ÄÜºÍ400000¾­ÑéÓÃÓÚÌá¸ßÒ»µãÁ¦Á¿¡£

ÓÂÆø/ÄÍÁ¦/ÌåÖÊ
enhance ÄÍÁ¦ ÈÃÄã½«80000Ç±ÄÜºÍ300000¾­ÑéÓÃÓÚÌá¸ßÒ»µãÄÍÁ¦¡£

ÔËÆø/ÈÍĞÔ
enhance ¶¨Á¦ ÈÃÄã½«80000Ç±ÄÜºÍ200000¾­ÑéÓÃÓÚÌá¸ßÒ»µãÔËÆø¡£

ÆøÁ¿/ÁéĞÔ/¶¨Á¦/ËÙ¶È/÷ÈÁ¦
enhance ÁéĞÔ ÈÃÄã½«30000Ç±ÄÜºÍ100000¾­ÑéÓÃÓÚÌá¸ßÒ»µãÁéĞÔ¡£

µÚN´ÎÊ¹ÓÃµÄ»¨·ÑÎªµÚÒ»´ÎµÄ2^£¨N-1£©±¶¡£

×¢ÒâÊÂÏî£º
Ñ§Íê»ù±¾¼¼ÄÜÔÙÊ¹ÓÃEnhance£¬¾ÙÀıÀ´Ëµ£¬Èç¹ûÄãµÄForceÊÇ180£¬ÌåÖÊ
ÊÇ36£¬ÀûÓÃenhance½«ÌåÖÊÌá¸ßµ½40£¬ÒÔºó¼´Ê¹Ñ§ÁË200¼¶forceÌåÖÊÒ²
½«Ö»ÊÇ40¡£Ã¿ÏîÊôĞÔ×î¶àÖ»ÄÜÌá¸ßÎå´Î¡£

Èç²»ÄÜÊäÈëÖĞÎÄ£¬¿ÉÓÃÆ´Òô´úÌæ¡£
²ÅÖÇ caizhi	ÌåÖÊ tizhi
ÁéĞÔ lingxing	÷ÈÁ¦ meili
ÓÂÆø yongqi	Á¦Á¿ liliang
ÄÍÁ¦ naili	ÈÍĞÔ renxing
ËÙ¶È sudu	ÆøÁ¿ qiliang
ÔËÆø yunqi	¶¨Á¦ dingli

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m 

HELP
        );
        return 1;
}
