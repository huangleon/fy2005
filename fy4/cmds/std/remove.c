// remove.c

#include <ansi.h>
inherit F_CLEAN_UP;

int 	do_remove(object me, object ob);

int main(object me, string arg)
{
	object ob, *inv;
	int i, count;

	if( !arg ) return notify_fail("ÄãÒªÍÑµôÊ²÷á£¿\n");

	if(arg=="all") {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
			if (do_remove(me, inv[i])) count++;
		if (!count)
			write("ÄãÃ»ÓĞ×°±¸ÈÎºÎÒÂÎï¡£\n");
		return 1;
	}

	if( !objectp(ob = present(arg, me)) )
		return notify_fail("ÄãÉíÉÏÃ»ÓĞÕâÑù¶«Î÷¡£\n");
	return do_remove(me, ob);
}

int do_remove(object me, object ob)
{
	string str;

	if( (string)ob->query("equipped")!="worn" )
		return notify_fail("Äã²¢Ã»ÓĞ×°±¸ÕâÑù¶«Î÷¡£\n");

	if( ob->unequip() ) {
		str = ob->query("unequip_msg")? ob->query("unequip_msg") : ob->query("unwield_msg");
		if( !stringp(str) )
			switch(ob->query("armor_type")) {
				case "cloth":
				case "armor":
				case "surcoat":
				case "boots":
					str = YEL "$N½«$n"YEL"ÍÑÁËÏÂÀ´¡£\n" NOR;
					break;
				case "bandage":
					str = YEL "$N½«$n"YEL"´ÓÉË¿Ú´¦²ğÁËÏÂÀ´¡£\n" NOR;
					break;
				default:
					str = YEL "$NĞ¶³ı$n"YEL"µÄ×°±¸¡£\n" NOR;
			}
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
[0;1;36mÖ¸Áî¸ñÊ½ : 	remove all | <ÎïÆ·Ãû³Æ>[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   
	
Õâ¸öÖ¸ÁîÈÃÄãÍÑµôÉíÉÏÄ³¼ş·À¾ß¡£

×¢Òâ£º¼´Ê¹ÔÚÕ½¶·ÖĞÉõÖÁÃ¦ÂÒ×´Ì¬ÏÂÄã¶¼¿ÉÒÔÖ´ĞĞ´ËÖ¸Áî£¬µ«ÊÇÒ»ĞÄÄÑÒÔ
	¶şÓÃ£¬ÔÚÖ´ĞĞ´ËÖ¸ÁîµÄ»ØºÏÖĞÕĞ¼ÜºÍ¹¥»÷Á¦»áÓĞËùÏÂ½µ¡£
	
Äã¿ÉÒÔÊ¹ÓÃsetÀ´ÆÁ±Î×Ô¼º»òËûÈË×°±¸/ÍÑĞ¶µÄĞÅÏ¢
	set equip_msg <1£¬2 »òÕß 3>	
´Ë²ÎÊıµÄÄ¿µÄÊÇÎªÁË¼õÉÙÆµ·±µÄ´©´÷ÍÑĞ¶Ë¢ÆÁ¡£Èç¹ûÉèÎª£±£¬Äã½«¿´²»µ½
×Ô¼º×°±¸£¯È¥³ıÎäÆ÷µÄĞÅÏ¢£»Èç¹ûÊÇ£²£¬Äã½«¿´²»µ½±ğÈË×°±¸£¯È¥³ıÎäÆ÷
µÄĞÅÏ¢£»Èç¹ûÊÇ£³£¬ÔòÁ½¸ö¶¼¿´²»µ½¡£Îª½ÚÊ¡ÏµÍ³×ÊÔ´£¬ĞÂÈËµÇÂ½Ê±×Ô¶¯
ÉèÎª2¡£

ÆäËûÏà¹ØÖ¸Áî: wear | wield | unwield

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   
 
HELP
    );
    return 1;
}
 
