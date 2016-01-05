// enhancesave.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int points, num;

	if( !arg ) 
	return notify_fail("ÄãÏÖÒÑ´æÈëÁË"+(string)(me->query("enhance/pot_save"))+"µãÇ±ÄÜ¡£\n");
	
	points = me->query("potential") - me->query("learned_points");
	
	if (sscanf(arg,"%d",num)!=1)
		return notify_fail("Enhancesave <Ç±ÄÜÊıÄ¿>\n");
		
	if( num<0 )
		return notify_fail("ÊäÈëµÄÇ±ÄÜ±ØĞëÊÇÕıÊı¡£\n");
	
	if( points < num )
		return notify_fail("ÄãÏÖÓĞµÄÇ±ÄÜÉÙÓÚÄãÊäÈëµÄÊıÄ¿¡£\n");

	if(me->is_busy())
		return notify_fail("ÄãÉÏ¸ö¶¯×÷»¹Ã»Íê³É¡£\n");

	me->add("enhance/pot_save", num);
	me->add("potential",-num);
	write("Äã³É¹¦µØ´æÈëÁË" + (string)(num)+ "µãÇ±ÄÜ£¡\n");
	me->start_busy(1);
	return 1;
}

int help(object me)
{
        write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ : 	enhancesave <Ç±ÄÜÖµ>[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

Õâ¸öÖ¸Áî¿ÉÒÔÈÃÄã½«Ç±ÄÜ´æ´¢ÆğÀ´ÓÃÓÚÒÔºóµÄEnhance¡£
´æ´¢ºóµÄÇ±ÄÜ½«²»ÄÜÔÙ·µ»Ø£¬Ö»ÄÜÓÃÓÚEnhance¡£
Ê¹ÓÃÎŞ²ÎÊıµÄEnhancesave¿É²ì¿´µ±Ç°ÒÑ´æ´¢µÄÇ±ÄÜÖµ¡£

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m  

HELP
        );
        return 1;
}
