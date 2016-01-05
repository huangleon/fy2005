/*	ABILITY2

str/int/comp/agi/karma/con
mana/force/atman
gin/kee/sen

shaolin/lama/legend: con, composure, str, kee/gin/sen 150+

taoist/yinshi: int, karma, agi,  mana/force/atman 50+

huashan/bonze: comp, int, con, mana/force/atman 50+

officer/beggar/wolfmount/moon/knight/fugui agi, str, karma, mana/force/atman 50+

*/

#include <ansi.h>
inherit F_ABILITY;

int main(object me, string arg)
{
	string *lists,temp,id;
	
	int i, a_num, total_count, saved_book, saved_task, saved_count, saved_ability3, learned_ability3, n;
	object ob;
	string arg1, myclass;
	string *done_class = ({"huashan", "official", "beggar", "lama", "shenshui", "fugui", "shaolin", "wolfmount", "knight", "taoist", "yinshi", "bonze", "moon", "legend"});
	
	if( wizardp(me) ) {
		if( arg && sscanf(arg, "-%s", id) == 1 ) {
			ob = present(id, environment(me));
			if( !ob ) {
				ob = find_player(id);
			}
			if( !ob ) {
				ob = find_living(id);
			}
			if( !ob ) {
				return notify_fail("ÄãÒª²ì¿´Ë­µÄÄÜÁ¦£¿\n");
			}
		} else {
			ob = me;
		}
	} else {
		ob = me;
	}
	n = 300; // 300 task --> 1 ability3
	total_count = ob->query("TASK");
	saved_book = ob->query("marks/book_task");
	saved_task = total_count - saved_book;
	saved_count = saved_task + saved_book/2;
	saved_ability3 = saved_count/n;
	learned_ability3 = ob->query("learned_ability3");
	
	if( arg && ob == me ) {
		if( !sscanf(arg, "+ %d", a_num) ) {
			return notify_fail("Ìá¸ßÄÜÁ¦µÄ¸ñÊ½£ºability3 + ÄÜÁ¦Ãû³Æ \n");
		}
		if( member_array(ob->query("class"), done_class) != -1 ) {
			if (a_num < 1 || a_num > 10) {
				return notify_fail("Ã»ÓĞ´Ë´úÂëµÄÄÜÁ¦£¨ÇëÊäÈë1-10£©\n");	
			}
		} else {
			if( a_num < 1 || a_num > 6 ) {
				return notify_fail("Ã»ÓĞ´Ë´úÂëµÄÄÜÁ¦£¨ÇëÊäÈë1-6£©\n");
			}
		}
		if( F_LEVEL->get_level(ob->query("combat_exp")) < 40 ) {
			return notify_fail("Ìá¸ßÄÜÁ¦ÖÁÉÙĞèÒª¾­ÑéµÈ¼¶40¡£\n");
		}			
		if( !stringp(myclass=ob->query("class")) ) {
			return notify_fail("ÄãÎŞÃÅÎŞÅÉ£¬ÈçºÎÄÜ¹»Áì»áÃÅÅÉÎä¹¦µÄ¾«Ëè£¿\n");
		}
		if( !arrayp(m_ability[myclass]) ) {
			return notify_fail("OOPS£¬ÄãËùÔÚµÄÃÅÅÉµÄÌØÉ«»¹Ã»Ğ´ºÃÒ®¡£\n");
		} else {	
			arg1 = m_ability3[myclass][a_num-1];
			if( !check_ability_improve(ob, arg1, 3) ) {
				return notify_fail("ÄãµÄ¾­ÑéµÈ¼¶»¹²»×ãÒÔÕÆÎÕ¸ü¸ßµÄ¸ÃÏîÄÜÁ¦¡£\n");
			}
			if( !deduct_ability_cost(ob, arg1, 3) ) {
					return notify_fail("ÄãÃ»ÓĞ×ã¹»µÄÄÜÁ¦µã´¢ĞîÀ´Ìá¸ß´ËÏîÄÜÁ¦¡£\n");
			}
			improve_ability(ob, arg1, 3);
			tell_object(ob, "¸ÃµÚ"+ (a_num) + "ÄÜÁ¦Ìá¸ßÍê±Ï¡£\n");
		}
		return 1;
	}

	write(sprintf(WHT"\t¡¡¡¡	TASK %sÄÜÁ¦½ø½×\n"NOR,"/std/char/master"->query_chinese_class(ob->query("class"))));
	write(HIR BLK"©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤\n"NOR);
	write(WHT    "ĞòºÅ		¹¦Ğ§			  µÈ¼¶	    	Éı¼¶µãÊı\n"NOR);	
	write(HIR BLK"©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤\n"NOR);

//	if( ob->query("betrayer") ) {
//		write("ÄãÓĞÅÑÊ¦Ç°¿Æ£¬ÎŞ·¨Áì»áĞÂÃÅÅÉµÄ¾«Ëè¡£\n");
//	}
	if( !stringp(myclass=ob->query("class")) ) {
		write("ÎŞÃÅÎŞÅÉÎŞÌØÉ«¡£\n");
	} else if( !arrayp(m_ability[myclass]) ) {
		write("OOPS£¬ÄãËùÔÚµÄÃÅÅÉµÄÌØÉ«»¹Ã»Ğ´ºÃÒ®¡£\n");
	} else {
		for( i = 0; i < 6; i++) {
			write(WHT + (i+1)+ NOR"\t"+ get_ability_info(ob, m_ability3[myclass][i], 3) + NOR);		
		}
		if( member_array(myclass,done_class) != -1 ) {
			for( i = 6; i < 10; i++) {
				write(WHT + (i+1)+ NOR"\t"+ get_ability_info(ob, m_ability3[myclass][i], 3) + NOR);
			}
		}
	}
	write(HIR BLK"©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤\n"NOR);

	write("ÄãÏÖÔÚ×Ü¹²Íê³ÉÁË"YEL + saved_task + NOR"¸öTASK£¬"YEL + saved_book + NOR"¸öÁ¯»¨±¦¼ø£¬´¢´æÁË"YEL + saved_count + NOR"TASKµãÊı¡£
ºÏ¼Æ"WHT + saved_ability3 + NOR"µã¸ß¼¶ÄÜÁ¦¡£
ÄãÒÑ¾­ÓÃÈ¥ÁË" RED+ learned_ability3 +NOR "µã¸ß¼¶ÄÜÁ¦£¬»¹Ê£ÏÂ"HIG+ (saved_ability3-learned_ability3) + NOR"µã¿É¹©·ÖÅä¡£\n");

	write(HIR BLK"©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤\n"NOR);
	
	return 1;
}


int help(object me)
{
write(@HELP

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ : 	ability3 [0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

ability3 	ÈÃÄãÖªµÀÄãÄ¿Ç°ËùÑ§¹ıµÄÒ»ÇĞÄÜÁ¦£¬
ability3 + n	Ìá¸ßµÚ£îÏîÄÜÁ¦µÄ¼¶±ğ¡£

¸ß¼¶ÄÜÁ¦ÊÇ·çÔÆÖĞ³ı¾­ÑéÖµ¡¢¼¼ÄÜÖµÒÔÍâÌá¸ß×ÔÉíµÄÒ»¸öÖØÒªÍ¾¾¶¡£
ÏàÍ¬¾­ÑéµÈ¼¶µÄ£¬ÄÜÁ¦¸ßµÄÈË»áÓĞ¸ü¶àµÄÆøÑª£¬Ôì³É¸ü´óµÄÉËº¦Á¦£¬
»òÕß¿ÉÒÔÓĞ¸ü¸ßµÄÑ§Ï°Ğ§ÂÊ¡£ÈçºÎºÏÀí·ÖÅäÄÜÁ¦µãÊÇ³ÉÎª¸ßÊÖµÄÒ»
´ó»ù±¾ÒªÇó¡£

ĞŞÏ°ÄÜÁ¦µÄµãÊı´ÓÄÄÀïÀ´£¿ÊÇ´ÓTASKÖĞÀ´£¬Ã¿300¸öTASKµãÊı¿ÉÒÔ×ª
»¯ÎªÒ»¸ö¸ß¼¶ÄÜÁ¦µã¹©Äã·ÖÅä¡£
Ã¿Íê³ÉÒ»¸öTASK»òÕßÏ×¸ø¶Î¹«¹«Á½Ò³¡¶Á¯»¨±¦¼ø¡·¿ÉÒÔ»ñµÃÒ»¸öµã
Êı¡£

µ±ÄãµÄ¾­Ñé¼¶±ğµ½´ï40Ê±£¬¾Í¿ÉÒÔÌá¸ß×ÔÉíµÄ¸÷ÏîÄÜÁ¦ÁË£¡
ÊäÈëability3¾Í¿ÉÒÔ¿´µ½Ò»¸öÇåÎúµÄÁĞ±í¡£²»Í¬ÃÅÅÉµÄ¸ß¼¶ÄÜÁ¦ÊÇ
²»Í¬µÄ¡£Ä¿Ç°Ã¿¸öÃÅÅÉ¹²ÓĞÁùÏîÑ¡Ôñ£¬ºÜ¿ì½«ÓĞ¸ü¶àµÄÄÚÈİ¼ÓÈë¡£

Ã¿ÏîÄÜÁ¦¹²·ÖÊ®¼¶£¬Ã¿¼¶µÄ¹¦Ğ§¶¼ÓĞÏêÏ¸ËµÃ÷¡£

¸ÃĞŞÏ°Ê²Ã´ÄØ£¿Õâ¾ÍÊÇÓÉ¸÷¸ö²»Í¬ÃÅÅÉµÄÌØµã»òÕß¸öÈËÏ²ºÃËù¾ö¶¨
ÁË¡£Èç¹ûÄãÏëÔÚÕ½¶·ÖĞ³Ö¾Ã£¬¾Í¶àÌá¸ßĞ©Ôö³¤¾«ÆøÉñµÄÄÜÁ¦£¬Èç¹û
ÄãÒªÌá¸ßÉ±ÉËÁ¦£¬¾ÍÌá¸ßĞ©Á¦Á¿£¬Èç¹ûÄãÊÇÀûÓÃ·¨ÊõµÄÃÅÅÉ£¬ÄÇÃ´
Ìá¸ß²ÅÖÇ¿ÉÒÔÔö¼ÓÃüÖĞÂÊ£¬»òÕß¶à¼ÓĞ©·¨Á¦¡£¡£¡£¡£

×¢£ºÓëÆÕÍ¨ÄÜÁ¦ABILITY²»Í¬£¬¸ß¼¶ÄÜÁ¦ÖĞµÄÄ§Á¦¡¢·¨Á¦¡¢ÄÚÁ¦µÄÌá
¸ß²¢²»»áÔö¼ÓÏàÓ¦µÄ¾«ÆøÉñÊıÖµ¡£

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m  
HELP
    );

    return 1;
}
 
