// death_recover.c	´ËÎªÎ×Ê¦×¨ÓÃÖ¸Áî£¬ÓÃÀ´»Ö¸´Íæ¼ÒÒòBUG¶øÔì³ÉµÄËÀÍöËğÊ§¡£
//		-- silencer@fy4

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object player;
	mapping death;
	string *lost_skill;
	int player_level, i;
	
	if( me!=this_player(1) ) return 0;
		
	if( !arg)
		return notify_fail("Ö¸Áî¸ñÊ½£ºdeath_recover <Ê¹ÓÃÕß>\n");

	player = find_player(arg);
	if (!player || !objectp(player))
		return notify_fail("µ±Ç°Ã»ÓĞ"+arg+"Õâ¸öÍæ¼Ò¡£\n");
		
	death = player->query("death");
	if (!death || !sizeof(death))
		return notify_fail("´ËÈËÃ»ÓĞËÀÍö¼ÍÂ¼£¬ÎŞ·¨ÓÃ´ËÃüÁî»Ö¸´¡£\n");

	write(sprintf("Íæ¼ÒµÄËÀÍö¼ÍÂ¼Îª%O\n",death));
		
	/*message_vision(HIW"$N½«ÊÖÖĞµÄ·¨ÕÈÒ»»Ó£¬Ò»µÀÈáºÍµÄ¹âÃ¢´ÓÌì¶ø½µ£¬×¢Èë$nÌåÄÚ¡£\n\n"NOR,me,player); */
	
	tell_object(me,player->query("id")+"ÉÏ´ÎËÀÍöÊ±¼äÎª"+ctime(death["time"])+"¡£\n");
	tell_object(player,"ÉÏ´ÎËÀÍöÊ±¼äÎª"+ctime(death["time"])+"¡£\n");
	player->add("combat_exp",death["exp_lost"]);
		tell_object(player,"ÄãËğÊ§µÄ¾­ÑéÖµÈ«²¿»Ö¸´ÁË£¬ÄãµÄÊôĞÔ»Ö¸´Õı³£¡£\n");
	player->delete("attr_apply");	// if they have more from previous death... well, lucky them.		
	
	/*log_file("BUG_RECOVER", sprintf(
		"%s ÓÚ %s Ìæ %s »Ö¸´Ò»´ÎËÀÍöËğÊ§£¬(exp %d, pot %d)\n",
			me->query("id"), ctime(time()), player->query("id"),
			death["exp_lost"], death["pot_lost"]));*/
	
	player->delete("death");
						
	return 1;
}


int help(object me)
{
write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÎ×Ê¦Ö¸Áî¸ñÊ½ : 	death_recover <Ä³ÈË>[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

ËùÓĞ×î½üËÀÍöµÄËğÊ§ÖµÔÚÍæ¼ÒµÄÊı¾İÖĞ¶¼ÓĞ¼ÇÂ¼£¬
´ËÃüÁîÊÇÌá¹©¸øÎ×Ê¦»Ö¸´Íæ¼ÒÒòÏµÍ³BUGÔì³ÉµÄ²»Õı³£ËÀÍö¡£

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m 
HELP
    );
    return 1;
}
