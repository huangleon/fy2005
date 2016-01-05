#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int lvl;

	if( me!=this_player(1) ) return 0;
	if( wiz_level(me) < wiz_level("(arch)") )
		return notify_fail("ÄãµÄÎ×Ê¦µÈ¼¶Ì«µÍ£¬Ã»ÓĞÊ¹ÓÃÕâ¸öÖ¸ÁîµÄÈ¨Á¦¡£\n");
	
	if( !arg || arg=="" ) {
		return notify_fail("µ±Ç°QuestµÄ¶îÍâ½±ÀøÎª£º"+ QUESTS_D->query_holiday()+" \n");	
	}
	
	if( sscanf(arg, "%d", lvl)!=1 ) 
		return notify_fail("²Î¼ûHELP¸ñÊ½ËµÃ÷¡£\n");
		
	seteuid(getuid());
	
	if (lvl>=0 && lvl<=900) {
		QUESTS_D->set_holiday(lvl);
		write(HIR"\nµ±Ç°Ã¿¸öQuestµÄ½±ÀøÎªÔ­À´µÄ"+ (lvl+100)+"%£¬ÓĞĞ§ÆÚ³ÖĞøµ½ÏµÍ³ÖØÆô»òÔÙ´ÎÉèÖÃ¡£\n"NOR);
		CHANNEL_D->do_sys_channel("info","Ìì»úÊ¹Ãü£¨Quest£©µÄ¾­Ñé/ÄÜÁ¦½±ÀøÏÖÔÚÉèÖÃÎª "+(lvl+100)+"£¥£¬´ó¼Ò¼ÓÓÍ°¡£¡");
		log_file("QBONUS_UPDATE_LOG", 
					sprintf("(%s)%s ¸Ä¶¯QUEST½±Àøµ½%d¡£\n",
   					ctime(time()), 
   					me->name(1)+"("+ me->query("id")+")", 
					lvl,
				));
		return 1;
	}
		
	return notify_fail("ÄãÖ»ÄÜÉèÖÃ0-900Ö®¼äµÄÊı×Ö¡£\n");
}

int help (object me)
{
        write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÎ×Ê¦Ö¸Áî¸ñÊ½ : 	holiday_bonus <Êı×Ö>[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

´ËÃüÁîÊÇ¸ø¹ÜÀíÎ×Ê¦¶¯Ì¬¸Ä±äÓÎÏ·ÖĞQuestµÄ½±Àø£¨0-900£©

½±Àø = »ù±¾½±Àø*£¨100+bonus£©/100

ÄãËùÄÜĞŞ¸ÄµÄ±ãÊÇÕâ¸öbonusÊıÖµ£¬±ÈÈçËµbonus = 100Ïàµ±ÓÚ¼Ó±¶½±Àø

Ã¿´ÎÖØĞÂÆô¶¯ºóBONUS×Ô¶¯»Ö¸´Îª0

´ËÃüÁîÓ°ÏìQuestËùµÃµÄ¾­ÑéÖµ¡¢ÒÔ¼°QuestËùµÃµÄABILITYÖµ£¬
´ËÃüÁîÓ°ÏìËùÓĞµ÷ÓÃ/adm/daemons/questdÖĞgive_rewardº¯ÊıµÄ½±Àø
´ËÃüÁî¶ÔTASKÃ»ÓĞÓ°Ïì

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m  
HELP
);
        return 1;
}
 
