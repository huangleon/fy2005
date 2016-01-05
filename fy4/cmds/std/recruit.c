// recruit.c

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob, old_rec;
	mapping family;
	int i, score_cost;

	if( !arg ) return notify_fail("Ö¸Áî¸ñÊ½£ºrecruit [cancel]|<¶ÔÏó>\n");

	if( arg=="cancel" ) {
		old_rec = me->query_temp("pending/recruit");
		if( !objectp(old_rec) )
			return notify_fail("ÄãÏÖÔÚ²¢Ã»ÓĞÊÕÂ¼ÈÎºÎÈËÎªµÜ×ÓµÄÒâË¼¡£\n");
		write("Äã¸Ä±äÖ÷Òâ²»ÏëÊÕ" + old_rec->name() + "ÎªµÜ×ÓÁË¡£\n");
		tell_object(old_rec, me->name() + "¸Ä±äÖ÷Òâ²»ÏëÊÕÄãÎªµÜ×ÓÁË¡£\n");
		me->delete_temp("pending/recruit");
		return 1;
	}

	if( !(ob = present(arg, environment(me))) )
		return notify_fail("ÄãÏëÊÕË­×÷µÜ×Ó£¿\n");

	if( ob==me ) return notify_fail("ÊÕ×Ô¼ºÎªµÜ×Ó£¿ºÃÖ÷Òâ....²»¹ıÃ»ÓĞÓÃ¡£\n");

	if( ob->is_apprentice_of(me) ) {
		message_vision("$NÅÄÅÄ$nµÄÍ·£¬ËµµÀ£º¡¸ºÃÍ½¶ù£¡¡¹\n", me, ob);
		return 1;
	}

	if( !me->query("family") )
		return notify_fail("Äã²¢²»Êôì¶ÈÎºÎÃÅÅÉ£¬Äã±ØĞëÏÈ¼ÓÈëÒ»¸öÃÅÅÉ£¬»ò×Ô¼º´´Ò»¸ö²ÅÄÜÊÕÍ½¡£\n");
        if( userp(me) && (int) me->query("family/privs")!= -1 )
                return notify_fail("²»ÊÇÕÆÃÅÈË²»¿ÉÊÕÍ½£®\n");
        if((string)me->query("family/family_name") ==
           (string)ob->query("family/family_name"))
        if((int)me->query("family/generation") >=
           (int)ob->query("family/generation"))
                return notify_fail(ob->name()+"µÄ±²·Ö²¢²»±ÈÄãµÍ£¡\n");
                
	// If the target is willing to apprentice us already, we do it.
	if( (object)ob->query_temp("pending/apprentice") == me ) {

		if( !living(ob) ) {
			message_vision(
				"$N¾ö¶¨ÊÕ$nÎªµÜ×Ó¡£\n\n"
				"²»¹ı¿´Ñù×Ó$nÏÔÈ»Ã»ÓĞ°ì·¨ĞĞ°İÊ¦Ö®Àñ¡£\n\n",
				me, ob);
			return 1;
		}
		if(mapp(ob->query("family")) &&
                   (string)me->query("family/family_name") !=
                   (string)ob->query("family/family_name") &&
                   (string)ob->query("family/title") !="ÆúÍ½")
        {
            message_vision(
                "$N¾ö¶¨±³ÅÑÊ¦ÃÅ£¬¸ÄÍ¶Èë$nÃÅÏÂ£¡£¡\n\n"
                "$N¹òÁËÏÂÀ´Ïò$n¹§¹§¾´¾´µØ¿ÄÁËËÄ¸öÏìÍ·£¬½ĞµÀ£º¡¸Ê¦¸¸£¡¡¹\n\n",
                ob, me);
            score_cost = me->query("score_cost") ? me->query("score_cost") : 1000;
			if (!ob->query("family")) score_cost = 0;
            if(ob->query("score") > score_cost) 
               	ob->add("score", -score_cost);
            else 
              	ob->set("score",0);
			ob->add("betrayer", 1);
		} else
			message_vision(
				"$N¾ö¶¨ÊÕ$nÎªµÜ×Ó¡£\n\n"
				"$n¹òÁËÏÂÀ´Ïò$N¹§¹§¾´¾´µØ¿ÄÁËËÄ¸öÏìÍ·£¬½ĞµÀ£º¡¸Ê¦¸¸£¡¡¹\n",
				me, ob);

		me->recruit_apprentice(ob);
		ob->delete_temp("pending/apprentice");
		ob->delete_temp("marks/apprentice_others");
		write("¹§Ï²ÄãĞÂÊÕÁËÒ»ÃûµÜ×Ó£¡\n");
		family = ob->query("family");
		tell_object( ob, sprintf("¹§Ï²Äú³ÉÎª%sµÄµÚ%s´úµÜ×Ó¡£\n", family["family_name"],
				chinese_number(family["generation"]) ));
		return 1;
		
	} else {

		old_rec = me->query_temp("pending/recruit");
		if( ob==old_rec )
			return notify_fail("ÄãÏëÊÕ" + ob->name() + "ÎªµÜ×Ó£¬µ«ÊÇ¶Ô·½»¹Ã»ÓĞ´ğÓ¦¡£\n");
		else if( objectp(old_rec) ) {
			write("Äã¸Ä±äÖ÷Òâ²»ÏëÊÕ" + old_rec->name() + "ÎªµÜ×ÓÁË¡£\n");
			tell_object(old_rec, me->name() + "¸Ä±äÖ÷Òâ²»ÏëÊÕÄãÎªµÜ×ÓÁË¡£\n");
		}

		me->set_temp("pending/recruit", ob );
		message_vision("\n$NÏëÒªÊÕ$nÎªµÜ×Ó¡£\n", me, ob);
		tell_object(ob, YEL "Èç¹ûÄãÔ¸Òâ°İ" + me->name() + "ÎªÊ¦¸¸£¬ÓÃ apprentice Ö¸Áî¡£\n" NOR);
		return 1;
	}
}


int help(object me)
{
        write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ : 	recruit [cancel]|<¶ÔÏó>[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   
 
Õâ¸öÖ¸ÁîÄÜÈÃÄãÊÕÄ³ÈËÎªµÜ×Ó, Èç¹û¶Ô·½Ò²´ğÓ¦Òª°İÄãÎªÊ¦µÄ»°.

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   
 
HELP
        );
        return 1;
}
