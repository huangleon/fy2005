// annie 07.2003 && Silencer @ FY4 workgroup. Oct.2004


#include <ansi.h>
inherit F_ABILITY;

int main(object me, string arg)
{
	string *lists,temp,id;
	
	int i, a_num, saved_quest, saved_quest1, saved_ability, learned_ability;
	object ob;
	string arg1, myclass;
	
	if (wizardp(me))
	{
		if(arg && sscanf(arg, "-%s", id) == 1)
		{
			ob = present(id, environment(me));
			if (!ob) ob = find_player(id);
			if (!ob) ob = find_living(id);
			if (!ob) return notify_fail("ÄãÒª²ì¿´Ë­µÄÄÜÁ¦£¿\n");			
		} else
			ob = me;					
	} else
		ob = me;

	saved_quest = ob->query("saved_quest")/60;
	saved_quest1 = (ob->query("saved_quest")*100/60)%100;
	saved_ability = saved_quest/100;			// 100¸öQuestËãÒ»¸öability
	learned_ability = ob->query("learned_ability");
	
	if (arg && ob==me)
	{
		if (!sscanf(arg,"+ %d",a_num))
			return notify_fail("Ìá¸ßÄÜÁ¦µÄ¸ñÊ½£ºability + ÄÜÁ¦Ãû³Æ \n");
		if (a_num <1 || a_num > 20)
			return notify_fail("Ã»ÓĞ´Ë´úÂëµÄÄÜÁ¦£¨ÇëÊäÈë1-20£©\n");
		if (F_LEVEL->get_level(ob->query("combat_exp"))< 80)
			return notify_fail("Ìá¸ßÄÜÁ¦ÖÁÉÙĞèÒª¾­ÑéµÈ¼¶80¡£\n");
			
		if (a_num<16)
		{
			arg1 = g_ability[a_num-1];
			
			if (!check_ability_improve(ob, arg1,0))
				return notify_fail("ÄãµÄ¾­ÑéµÈ¼¶»¹²»×ãÒÔÕÆÎÕ¸ü¸ßµÄ¸ÃÏîÄÜÁ¦¡£\n");
			if (!deduct_ability_cost(ob, arg1,0))
				return notify_fail("ÄãÃ»ÓĞ×ã¹»µÄÄÜÁ¦µã´¢ĞîÀ´Ìá¸ß´ËÏîÄÜÁ¦¡£\n");
			improve_ability( ob, arg1, 0);
			tell_object(ob, "¸ÃµÚ"+ (a_num) + "ÄÜÁ¦Ìá¸ßÍê±Ï¡£\n");
			return 1;
		}
		
		if (!stringp(myclass = ob->query("class")))
			return notify_fail("ÄãÎŞÃÅÎŞÅÉ£¬ÈçºÎÄÜ¹»Áì»áÃÅÅÉÎä¹¦µÄ¾«Ëè£¿\n");
		
		if (!arrayp(m_ability[myclass]))
		{
			return notify_fail("OOPS£¬ÄãËùÔÚµÄÃÅÅÉµÄÌØÉ«»¹Ã»Ğ´ºÃÒ®¡£\n");
		} else
		{	
			arg1 = m_ability[myclass][a_num-16];
			if (!check_ability_improve(ob, arg1,1))
				return notify_fail("ÄãµÄ¾­ÑéµÈ¼¶»¹²»×ãÒÔÕÆÎÕ¸ü¸ßµÄ¸ÃÏîÄÜÁ¦¡£\n");
			if (!deduct_ability_cost(ob, arg1,1))
				return notify_fail("ÄãÃ»ÓĞ×ã¹»µÄÄÜÁ¦µã´¢ĞîÀ´Ìá¸ß´ËÏîÄÜÁ¦¡£\n");
			improve_ability( ob, arg1, 1);
			tell_object(ob, "¸ÃµÚ"+ (a_num) + "ÄÜÁ¦Ìá¸ßÍê±Ï¡£\n");
		}
				
		return 1;
	}
	
	write(WHT"\t¡¡¡¡		»ù±¾ÄÜÁ¦½ø½×\n"NOR);
	write(HIR BLK"©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤\n"NOR);
	write(WHT    "ĞòºÅ		¹¦Ğ§			  µÈ¼¶	    	Éı¼¶µãÊı\n"NOR);	
	write(HIR BLK"©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤\n"NOR);
	
	for(i=0; i<sizeof(g_ability); i++)
		write(WHT + (i+1)+ NOR"\t"+ get_ability_info(ob, g_ability[i],0) + NOR);		
	write(HIR BLK"©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤\n"NOR);

		
	write(WHT"\t¡¡¡¡		ÃÅÅÉÄÜÁ¦½ø½×\n"NOR);
	write(HIR BLK"©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤\n"NOR);
	
	if (!stringp(myclass = ob->query("class")))	write("ÎŞÃÅÎŞÅÉÎŞÌØÉ«¡£\n");
//	else if (ob->query("betrayer"))
//		write("ÄãÓĞÅÑÊ¦Ç°¿Æ£¬ÎŞ·¨Áì»áĞÂÃÅÅÉµÄ¾«Ëè¡£\n");
	else if (!arrayp(m_ability[myclass]))
		write("OOPS£¬ÄãËùÔÚµÄÃÅÅÉµÄÌØÉ«»¹Ã»Ğ´ºÃÒ®¡£\n");
	else
		for(i=0; i<5; i++)
			write(WHT + (i+16)+ NOR"\t"+ get_ability_info(ob, m_ability[myclass][i],1) + NOR);		

	write(HIR BLK"©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤\n"NOR);

	write("ÄãÏÖÔÚ×Ü¹²Íê³ÉÁË"YEL+ saved_quest + "."+ saved_quest1+ NOR"¸öÄÜÁ¦Quest£¬ºÏ¼Æ"WHT + saved_ability + NOR"µãÄÜÁ¦¡£
ÄãÒÑ¾­ÓÃÈ¥ÁË" RED+ learned_ability +NOR "µãÄÜÁ¦£¬»¹Ê£ÏÂ"HIG+ (saved_ability-learned_ability) + NOR"µã¿É¹©·ÖÅä¡£\n");

	write(HIR BLK"©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤\n"NOR);
	
	return 1;
}


int help(object me)
{
write(@HELP

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ : 	ability [0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

ability 	ÈÃÄãÖªµÀÄãÄ¿Ç°ËùÑ§¹ıµÄÒ»ÇĞÄÜÁ¦£¬
ability + n	Ìá¸ßµÚ£îÏîÄÜÁ¦µÄ¼¶±ğ¡£

ÄÜÁ¦ÊÇ·çÔÆ2005ÖĞ³ı¾­ÑéÖµ¡¢¼¼ÄÜÖµÒÔÍâÌá¸ß×ÔÉíµÄÒ»¸öÖØÒªÍ¾¾¶¡£
ÏàÍ¬¾­ÑéµÈ¼¶µÄ£¬ÄÜÁ¦¸ßµÄÈË»áÓĞ¸ü¶àµÄÆøÑª£¬Ôì³É¸ü´óµÄÉËº¦Á¦£¬
»òÕß¿ÉÒÔÓĞ¸ü¸ßµÄÑ§Ï°Ğ§ÂÊ¡£ÈçºÎºÏÀí·ÖÅäÄÜÁ¦µãÊÇ³ÉÎª¸ßÊÖµÄÒ»
´ó»ù±¾ÒªÇó¡£

µ±ÄãµÄ¾­Ñé¼¶±ğµ½´ï80Ê±£¬¾Í¿ÉÒÔÌá¸ß×ÔÉíµÄ¸÷ÏîÄÜÁ¦ÁË£¡
ÊäÈë£á£â£é£ì£é£ô£ù¾Í¿ÉÒÔ¿´µ½Ò»¸öÇåÎúµÄÁĞ±í¡£·ÖÁ½´óÀà£¬µÚÒ»
Àà¹²ÓĞ£±£µÏî£¬ËùÓĞÃÅÅÉ¶¼¿ÉÒÔĞŞÏ°£¬´ó¶àÊÇÌá¸ß»ù±¾ÊôĞÔµÄ£»µÚ
¶şÀàÓĞÎåÏî£¬ÊôÓÚÃÅÅÉÎä¹¦µÄ¾«ËèËùÔÚ£¬²»Í¬ÃÅÅÉ¸÷ÓĞÌØÉ«¡£

Ã¿ÏîÄÜÁ¦¹²·ÖÊ®¼¶£¬Ã¿¼¶µÄ¹¦Ğ§¶¼ÓĞÏêÏ¸ËµÃ÷¡£ĞŞÏ°µÚÒ»ÀàÄÜÁ¦µÄ
ÒªÇóÎªµÈ¼¶80£¬ĞŞÏ°µÚ¶şÀàÄÜÁ¦µÄÒªÇóÎªµÈ¼¶100¡£Ò»¿ªÊ¼µÄÊ±ºò£¬
ÄãÒ²Ğí×î¶àÖ»ÄÜĞŞÏ°µ½µÚ¶ş¼¶£¬Ëæ×ÅÄã±¾ÉíµÈ¼¶µÄÌá¸ß£¬¾­ÑéÃ¿Ôö
³¤Îå¼¶±ã¿ÉÒÔ¶àĞŞÏ°Ò»¸öÄÜÁ¦¼¶±ğ¡£

¸ÃĞŞÏ°Ê²Ã´ÄØ£¿Õâ¾ÍÊÇÓÉ¸÷¸ö²»Í¬ÃÅÅÉµÄÌØµã»òÕß¸öÈËÏ²ºÃËù¾ö¶¨
ÁË¡£Èç¹ûÄãÏëÔÚÕ½¶·ÖĞ³Ö¾Ã£¬¾Í¶àÌá¸ßĞ©Ôö³¤¾«ÆøÉñµÄÄÜÁ¦£¬Èç¹û
ÄãÒªÌá¸ßÉ±ÉËÁ¦£¬¾ÍÌá¸ßĞ©Á¦Á¿£¬Èç¹ûÄãÊÇÀûÓÃ·¨ÊõµÄÃÅÅÉ£¬ÄÇÃ´
Ìá¸ß²ÅÖÇ¿ÉÒÔÔö¼ÓÃüÖĞÂÊ£¬»òÕß¶à¼ÓĞ©·¨Á¦¡£¡£¡£¡£

ĞŞÏ°ÄÜÁ¦µÄµãÊı´ÓÄÄÀïÀ´£¿ºÜ¼òµ¥£¬Ò²ÊÇ´ÓÍê³ÉÌì»úÀÏÈËµÄQuestÖĞ
µÃµ½¡£µ±ÄãµÄ¾­ÑéµÈ¼¶´ïµ½80Ê±£¬¿ÉÒÔÉè¶¨Ò»¸ö²ÎÊı
		set ability 1
ÔÚ´ËÇé¿öÏÂ£¬Quest½«²»ÔÙÔö¼ÓÄãµÄ¾­ÑéÖµ£¬¶øÊÇ×ªÈëÄÜÁ¦µãÖĞ´¢´æ
ÆğÀ´£¬Ã¿100¸öQuest¿ÉÒÔ×ª»¯ÎªÒ»¸öÄÜÁ¦µã¹©Äã·ÖÅä¡£µ±ÄãÏë¼ÌĞø
Ìá¸ß¾­ÑéÊ±£¬Ö»ĞèÒª set ability 0 ¾Í¿ÉÒÔÁË¡£

×¢Òâ£¬²»×÷·ÖÅäµÄABILITYµãÊı×î¶àÖ»ÄÜ´¢´æ6µã£¬³¬¹ı6µãºóQuest
½±Àø½«×Ô¶¯·ÖÅäµ½¾­ÑéÉÏ¡£

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m  
HELP
    );

    return 1;
}
 
