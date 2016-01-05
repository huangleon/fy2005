// unwield.c

inherit F_CLEAN_UP;

int do_unwield(object me, object ob);

int main(object me, string arg)
{
	object ob, *inv;
	string str;
	int i, count;

	if( !arg ) return notify_fail("ÄãÒª·ÅÏÂÊ²÷á£¿\n");

	if (me->is_busy())
		me->set_temp("timer/switch_inbusy",time());

	if(arg=="all") {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
			if (do_unwield(me, inv[i])) count++;
		if (!count)
			write("ÄãÃ»ÓÐ×°±¸ÈÎºÎÎäÆ÷¡£\n");
		return 1;
	}

	if( !objectp(ob = present(arg, me)) )
		return notify_fail("ÄãÉíÉÏÃ»ÓÐÕâÑù¶«Î÷¡£\n");
	return do_unwield(me, ob);
}

int do_unwield(object me, object ob){
	string str;

	if( (string)ob->query("equipped")!="wielded" )
		return notify_fail("Äã²¢Ã»ÓÐ×°±¸ÕâÑù¶«Î÷×÷ÎªÎäÆ÷¡£\n");

	if( ob->unequip() ) {
		if( !stringp(str = ob->query("unwield_msg")) )
			str = "$N·ÅÏÂÊÖÖÐµÄ$n¡£\n";
		me->set_temp("timer/switch_equip",time());
//		message_vision(str, me, ob);
		F_EQUIP->selective_message(str,me,ob,"equip_msg");
		return 1;
	} else
		return 0;
}

int help(object me)
{
  write(@HELP

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ : 	unwield all | <ÎïÆ·Ãû>[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   
	
Õâ¸öÖ¸ÁîÈÃÄã·ÅÏÂÊÖÖÐµÄÎäÆ÷¡£

×¢Òâ£º¼´Ê¹ÔÚÕ½¶·ÖÐÉõÖÁÃ¦ÂÒ×´Ì¬ÏÂÄã¶¼¿ÉÒÔÖ´ÐÐ´ËÖ¸Áî£¬µ«ÊÇÒ»ÐÄÄÑÒÔ
	¶þÓÃ£¬ÔÚÖ´ÐÐ´ËÖ¸ÁîµÄ»ØºÏÖÐÕÐ¼ÜºÍ¹¥»÷Á¦»áÓÐËùÏÂ½µ¡£
	
Äã¿ÉÒÔÊ¹ÓÃsetÀ´ÆÁ±Î×Ô¼º»òËûÈË×°±¸/ÍÑÐ¶µÄÐÅÏ¢
	set equip_msg <1£¬2 »òÕß 3>	
´Ë²ÎÊýµÄÄ¿µÄÊÇÎªÁË¼õÉÙÆµ·±µÄ´©´÷ÍÑÐ¶Ë¢ÆÁ¡£Èç¹ûÉèÎª£±£¬Äã½«¿´²»µ½
×Ô¼º×°±¸£¯È¥³ýÎäÆ÷µÄÐÅÏ¢£»Èç¹ûÊÇ£²£¬Äã½«¿´²»µ½±ðÈË×°±¸£¯È¥³ýÎäÆ÷
µÄÐÅÏ¢£»Èç¹ûÊÇ£³£¬ÔòÁ½¸ö¶¼¿´²»µ½¡£Îª½ÚÊ¡ÏµÍ³×ÊÔ´£¬ÐÂÈËµÇÂ½Ê±×Ô¶¯
ÉèÎª2¡£

ÆäËûÏà¹ØÖ¸Áî: wield | wear | remove

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m    
HELP
    );
    return 1;
}
 
