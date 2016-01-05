// summon command..

# include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string str)
{
	object ob;
	int i;
	if (!str) return notify_fail("<Syntax>: Summon <player id>\n");
	ob = LOGIN_D->find_body(str);
	if (!ob) return notify_fail("ß×... ÓĞÕâ¸öÈËÂğ?\n");
	
	if (environment(ob)== environment(me))
		return notify_fail("Õâ¸öÈË¾ÍÔÚÄãµÄÃæÇ°¡£\n");
	
	// moving
	message_vision("\n\nºöÈ»$NÉíºóÌø³öÒ»ÈË½ĞµÀ£º¼±¡¢¼±£¬¶ñÈË¹ÈÀÏ´óÕÒ$N£¬ËÀµÄ»îµÄ¶¼Òª¡£
Ëµ°Õ¾¹À­×Å$NÌøÉÏÔÆ¶ËÒ»ÁïÑÌµØÏûÊ§ÁË¡£¡£\n\n", ob);
	tell_object(ob,"Äã¾õµÃ×Ô¼ºµÄÉí×ÓÒ»Çá£¬²»ÓÉ×ÔÖ÷µØ·ÉÉÏÁËÌì£¬Ò»×¼ÊÇÄÄÎ»ÇëÄãÈ¥ÁË°É£¿\n\n");
	
	ob->move(environment(me));
        tell_object(me, "Äã°Ñ"+(string)ob->query("name")+"×ªÒÆµ½ÄãµÄÃæÇ°.\n");
	tell_object(ob,"....Ô­À´ÊÇ"+(string)me->query("name")+"ÕÒÄãÓĞ¼±ÊÂ¶ù¡£\n");
	tell_room(environment(ob),(string)ob->query("name")+"´Ó°ë¿ÕÖĞÆ®Æ®ÓÆÓÆµØµôµ½µØÉÏ¡£\n",({me,ob}));
	
	 if( !wizardp(ob) ) 
     /*	log_file("static/SUMMON", sprintf("%s(%s) summoned %s(%s) to %s at %s¡£\n", me->name(1),
              me->query("id"), ob->name(1), ob->query("id"), base_name(environment(me)), ctime(time()) ) );*/
	
	return 1;
}

int help(object me)
{
write(@HELP

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÎ×Ê¦Ö¸Áî¸ñÊ½ : 	summon <Ä³ÈË>[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

´ËÖ¸Áî¿ÉÈÃÄã½«Ä³ÈËÒÆµ½ÄãÃæÇ°¡£

×¢Òâ£º´ËÖ¸Áî¿ÉÄÜÔì³ÉÍæ¼ÒµÄ½âÃÜÖĞ¶Ï£¬´ò¶··ÇÕı³£ÍË³öµÈ£¬
£¨no_fly, no_move, busyµÈµÈµÈµÈ£©
ËùÒÔ½¨ÒéÊ¹ÓÃ£ç£ï£ô£ï£¬»òÕßÔÚÊ¹ÓÃ´ËÖ¸ÁîÇ°Õ÷ÇóÍæ¼ÒÒâ¼û¡£


[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   
HELP
    );
    return 1;
}
