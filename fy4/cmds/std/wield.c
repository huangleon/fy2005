// wield.c

inherit F_CLEAN_UP;

int do_wield(object me, object ob);

int main(object me, string arg)
{
	object ob, *inv;
	int i, count;

	if( !arg ) return notify_fail("ÄãÒª×°±¸Ê²÷áÎäÆ÷£¿\n");
	
	if(arg=="all") {
		inv = all_inventory(me);
		for(count=0, i=0; i<sizeof(inv); i++) {
			if( inv[i]->query("equipped") ) continue;
			if(do_wield(me, inv[i]) ) count ++;
		}
		if (!count)
			write("ÄÜÄÃµÄ¶¼ÄÃÉÏÁË¡£¡£¡£¡£\n");			
		return 1;
	}
	

	if( !objectp(ob = present(arg, me)) )
		return notify_fail("ÄãÉíÉÏÃ»ÓĞÕâÑù¶«Î÷¡£\n");

	if( ob->query("equipped") )
		return notify_fail("ÄãÒÑ¾­×°±¸ÖøÁË¡£\n");

	return do_wield(me, ob);
}

int do_wield(object me, object ob)
{
	string str;

	if (ANNIE_D->check_buff(me,"disarmed"))
		return notify_fail("ÄãÊÖ±ÛËáÂé£¬Ò»Ê±ÎŞ·¨ÄÃÆğÕâ¼şÎäÆ÷¡£\n");
		
	if (userp(me)) {
		if (ob->query("class"))
		if (ob->query("class")!= me->query("class"))
			return notify_fail("ÄãµÄÃÅÅÉÎä¹¦²»ÊÊºÏÓÃÕâ¼şÎäÆ÷¡£\n");
		
		if (ob->query("experience"))
		if (ob->query("experience")>me->query("combat_exp"))
			return notify_fail("ÄãµÄÊµÕ½¾­ÑéÌ«µÍ£¬·¢»Ó²»ÁËÕâ¼şÎäÆ÷µÄÍşÁ¦¡£\n");
		
		if (ob->query("level_required"))
		if (ob->query("level_required") > F_LEVEL->get_level(me->query("combat_exp")))
			return notify_fail("ÄãµÄÊµÕ½¾­ÑéµÈ¼¶Ì«µÍ£¬·¢»Ó²»ÁËÕâ¼şÎäÆ÷µÄÍşÁ¦£¨Ğè"
				+ ob->query("level_required")+"¼¶£©\n");
		
		if (ob->query("strength"))
		if (ob->query("strength")>me->query_str())
			return notify_fail("ÄãµÄ±ÛÁ¦Ì«Èõ£¬¾Ù²»ÆğÕâ¼şÎäÆ÷¡£\n");
		
		if (ob->query("agility"))
		if (ob->query("agility")>me->query_agi())
			return notify_fail("Äã²»¹»Ãô½İ£¬ÎŞ·¨½«Õâ¼şÎäÆ÷ÔË×ªÈçÒâ¡£\n");
			
		if (ob->query("score"))
		if (ob->query("score")<me->query("score"))
			return notify_fail("Õâ¼şÎäÆ÷Ì«¹ıÒõ¶¾£¬ÄãÕâÑùÓĞÉí·İµÄÈË²»ÊÊºÏÓÃ°É¡£\n");	
	}
	
	if (ob->query("item_damaged") && ob->query("weapon_prop/damage") < 5)
		return notify_fail("Õâ¼şÎäÆ÷ÒÑ¾­ÑÏÖØËğ»µ£¬²»ºÏÔÙÓÃ¡£\n");
		
	if( ob->wield() ) {
		if( !stringp(str = ob->query("wield_msg")) )
			str = "$N×°±¸$n×÷ÎäÆ÷¡£\n";
//		message_vision(str, me, ob);
		F_EQUIP->selective_message(str,me,ob,"equip_msg");
		ob->query("equip_fun");
		me->set_temp("timer/switch_equip",time());	
		return 1;
	} else
		return 0;
}

int help(object me)
{
	write(@HELP
	
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ : 	wield all | <×°±¸Ãû³Æ>[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

Õâ¸öÖ¸ÁîÈÃÄã×°±¸Ä³¼şÎïÆ·×÷ÎäÆ÷, Äã±ØĞèÒªÓµÓĞÕâÑùÎïÆ·.

×¢Òâ£º¼´Ê¹ÔÚÕ½¶·ÖĞÉõÖÁÃ¦ÂÒ×´Ì¬ÏÂÄã¶¼¿ÉÒÔÖ´ĞĞ´ËÖ¸Áî£¬µ«ÊÇÒ»ĞÄÄÑÒÔ
	¶şÓÃ£¬ÔÚÖ´ĞĞ´ËÖ¸ÁîµÄ»ØºÏÖĞÕĞ¼ÜºÍ¹¥»÷Á¦»áÓĞËùÏÂ½µ¡£
	
Äã¿ÉÒÔÊ¹ÓÃsetÀ´ÆÁ±Î×Ô¼º»òËûÈË×°±¸/ÍÑĞ¶µÄĞÅÏ¢
	set equip_msg <1£¬2 »òÕß 3>	
´Ë²ÎÊıµÄÄ¿µÄÊÇÎªÁË¼õÉÙÆµ·±µÄ´©´÷ÍÑĞ¶Ë¢ÆÁ¡£Èç¹ûÉèÎª£±£¬Äã½«¿´²»µ½
×Ô¼º×°±¸£¯È¥³ıÎäÆ÷µÄĞÅÏ¢£»Èç¹ûÊÇ£²£¬Äã½«¿´²»µ½±ğÈË×°±¸£¯È¥³ıÎäÆ÷
µÄĞÅÏ¢£»Èç¹ûÊÇ£³£¬ÔòÁ½¸ö¶¼¿´²»µ½¡£Îª½ÚÊ¡ÏµÍ³×ÊÔ´£¬ĞÂÈËµÇÂ½Ê±×Ô¶¯
ÉèÎª2¡£
				
ÆäËûÏà¹ØÖ¸Áî: unwield | wear | remove

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m 
 
HELP
    );
    return 1;
}
