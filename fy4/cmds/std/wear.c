// wear.c

#include <ansi.h>

inherit F_CLEAN_UP;

int do_wear(object me, object ob);

int main(object me, string arg)
{
	object ob, *inv;
	int i, count;

	if( !arg ) return notify_fail("ÄãÒª´©´÷Ê²÷á£¿\n");

	if(arg=="all") {
		inv = all_inventory(me);
		for(count=0, i=0; i<sizeof(inv); i++) {
			if( inv[i]->query("equipped") ) continue;
			if(do_wear(me, inv[i]) ) count ++;
		}
	if (!count)
		write("ÄÜ´©µÄ¶¼´©ÉÏÁË¡£¡£¡£¡£\n");
		return 1;
	}

	if( !objectp(ob = present(arg, me)) )
		return notify_fail("ÄãÉíÉÏÃ»ÓĞÕâÑù¶«Î÷¡£\n");

	if( ob->query("equipped") )
		return notify_fail("ÄãÒÑ¾­´©´÷×ÅÁË¡£\n");

	return do_wear(me, ob);
}

int do_wear(object me, object ob)
{
	string str;

	if( ob->query("female_only")
	&&	(string)me->query("gender") != "Å®ĞÔ" )
		return notify_fail("ÕâÊÇÅ®ÈËµÄÒÂÊÎ£¬ÄãÒ»¸ö´óÄĞÈËÒ²Ïë´©´÷£¬ĞßÒ²²»Ğß£¿\n");

	if( ob->query("male_only")
	&&	(string)me->query("gender") == "Å®ĞÔ" )
		return notify_fail("ÕâÊÇ´óÄĞÈËµÄÒÂÎï£¬ÄãÒ»¸öÅ®ÈËÒ²Ïë´©´÷£¿»¹ÊÇËãÁË°É£¡\n");

	if (userp(me)) {
		if (ob->query("level_required"))
		if (ob->query("level_required") > F_LEVEL->get_level(me->query("combat_exp")))
			return notify_fail("ÄãµÄÊµÕ½¾­ÑéµÈ¼¶Ì«µÍ£¬»¹²»ÄÜ´©´÷´ËÒÂÎï£¨Ğè"
				+ ob->query("level_required")+"¼¶£©\n");
		
		if (ob->query("strength"))
		if (ob->query("strength")>me->query("str"))
			return notify_fail("Äã²»¹»Ç¿×³£¬²»ÊÊºÏ´©Õâ¼ş»¤¼×¡£\n");
		
		if (ob->query("agility"))
		if (ob->query("agility")>me->query("agi"))
			return notify_fail("Äã²»¹»Ãô½İ£¬´©ÁËÕâ¼ş»¤¼×»á¾Ù²½Î¬¼èµÄ¡£\n");	
	}
		
	if( ob->wear() ) {
		if( !stringp(str = ob->query("wear_msg")) )
			switch( ob->query("armor_type") ) {
				case "cloth":
				case "armor":
				case "boots":
					str = YEL "$N´©ÉÏÒ»" + ob->query("unit") + "$n¡£\n" NOR;
					break;
				case "head":
				case "neck":
				case "wrists":
				case "finger":
				case "hands":
					str = YEL "$N´÷ÉÏÒ»" + ob->query("unit") + "$n¡£\n" NOR;
					break;
				case "waist":
					str = YEL "$N½«Ò»" + ob->query("unit") + "$n"YEL"°óÔÚÑü¼ä¡£\n" NOR;
					break;
				default:
					str = YEL "$N×°±¸$n¡£\n" NOR;
			}
//		message_vision(str, me, ob);
		me->set_temp("timer/switch_equip",time());
		F_EQUIP->selective_message(str,me,ob,"equip_msg");
		return 1;
	} else
		return 0;
}

int help(object me)
{
	write(@HELP
	
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ : 	wear all | <×°±¸Ãû³Æ>[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

Õâ¸öÖ¸ÁîÈÃÄã×°±¸Ä³¼ş·À¾ß¡£

×¢Òâ£º¼´Ê¹ÔÚÕ½¶·ÖĞÉõÖÁÃ¦ÂÒ×´Ì¬ÏÂÄã¶¼¿ÉÒÔÖ´ĞĞ´ËÖ¸Áî£¬µ«ÊÇÒ»ĞÄÄÑÒÔ
	¶şÓÃ£¬ÔÚÖ´ĞĞ´ËÖ¸ÁîµÄ»ØºÏÖĞÕĞ¼ÜºÍ¹¥»÷Á¦»áÓĞËùÏÂ½µ¡£
	
Äã¿ÉÒÔÊ¹ÓÃsetÀ´ÆÁ±Î×Ô¼º»òËûÈË×°±¸/ÍÑĞ¶µÄĞÅÏ¢
	set equip_msg <1£¬2 »òÕß 3>	
´Ë²ÎÊıµÄÄ¿µÄÊÇÎªÁË¼õÉÙÆµ·±µÄ´©´÷ÍÑĞ¶Ë¢ÆÁ¡£Èç¹ûÉèÎª£±£¬Äã½«¿´²»µ½
×Ô¼º×°±¸£¯È¥³ıÎäÆ÷µÄĞÅÏ¢£»Èç¹ûÊÇ£²£¬Äã½«¿´²»µ½±ğÈË×°±¸£¯È¥³ıÎäÆ÷
µÄĞÅÏ¢£»Èç¹ûÊÇ£³£¬ÔòÁ½¸ö¶¼¿´²»µ½¡£Îª½ÚÊ¡ÏµÍ³×ÊÔ´£¬ĞÂÈËµÇÂ½Ê±×Ô¶¯
ÉèÎª2¡£

ÆäËûÏà¹ØÖ¸Áî: remove | wield | unwield

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m    
HELP
    );
    return 1;
}
