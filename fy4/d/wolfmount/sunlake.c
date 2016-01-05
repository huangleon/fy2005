#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "Ì«Ñôºş");

	set("long", @LONG
Ã¿ÌìÔçÉÏÌ«ÑôÉıÆğµÄÊ±ºò£¬µÚÒ»µÀÑô¹â×ÜÊÇÕÕÔÚÕâ[37mÌ«Ñôºş[32mÉÏ¡£Äş¾²µÄºşË®µ´Ñú
×ÅºÍìãµÄÑô¹â£¬ÏóÊÇÈ¼ÉÕ×ÅµÄ»ğÑæ£¬ËùÓĞµÄÒ»ÇĞÍêÃÀµÃÏñÔÚÃÎ¾³ÖĞÒ»°ã¡£ºş±ßÏÊ»¨
Å­·Å£¬Ò»ÈºÈçÍ¬ÏÊ»¨Ò»ÑùÄêÇá¶øÃÀÀöµÄÉÙÅ®³àÂã×ÅÉí×ÓÔÚºşÖĞæÒÏ·ÍæÄÖ£¬ºşĞÄÆ®µ´
×ÅÒ»Ò¶È÷ÂúÏÊ»¨µÄ[37mĞ¡ÖÛ[32m¡£
LONG);

	set("type","waterbody");
	set("exits",([
		"north":__DIR__"brook3",
	]) );
       set("outdoors", "wolfmount");
	set("item_desc", ([
            "boat": "Ò»Ò¶Ğ¡ÖÛ£¬È÷ÂúÏÊ»¨£¬ÔÚ[37mºşĞÄ[32mÆ®Æ®µ´µ´¡£\n",
      		"Ğ¡ÖÛ": "Ò»Ò¶Ğ¡ÖÛ£¬È÷ÂúÏÊ»¨£¬ÔÚ[37mºşĞÄ[32mÆ®Æ®µ´µ´¡£\n",
      		"lake": "ºşË®Çå³º£¬ÄãºÜÏëÌø½øºşÖĞ£¬Ï´µô¶àÄêµÄ½­ºş³¾°£(swim lake)¡£\n",
      		"Ì«Ñôºş": "ºşË®Çå³º£¬ÄãºÜÏëÌø½øºşÖĞ£¬Ï´µô¶àÄêµÄ½­ºş³¾°£(swim lake)¡£\n",
      		"ºşĞÄ": "ºşĞÄÀë°¶±ßÈıËÄÕÉ£¬Çá¹¦ºÃµÄ»°µ±¿ÉÒ»Ô¾¶øÖÁ(charge center)¡£\n",
      		"center": "ºşĞÄÀë°¶±ßÈıËÄÕÉ£¬Çá¹¦ºÃµÄ»°µ±¿ÉÒ»Ô¾¶øÖÁ(charge center)¡£\n",
        ]) );
	set("coor/x",-70);
	set("coor/y",-80);
	set("coor/z",0);
	setup();
}

void init(){

	add_action("do_swim", "swim");
	add_action("do_charge", "charge");

}



int do_charge(string arg)
{
        object room;
        object me;

        if(!arg || arg=="")
        {
                write("ÄãÒªÏòÄÄÀïÌø£¿\n");
                return 1;
        }
        if( arg == "ºşĞÄ" || arg == "center" )
        {
        	me = this_player();
        	if ( me->is_busy() )
        		return notify_fail("ÄãÏÖÔÚÃ¦µÃºÜ£¬²»ÄÜÒÆ¶¯¡£\n");
            if ( me->query_skill("dodge") >= 100 )
        	{
        		message_vision("$N½ÅÏÂÒ»µÅ£¬ÉíĞÎÈçÓ¥»÷³¤¿Õ£¬Èç·ÉÒ»°ãÔ¾ÏòºşĞÄĞ¡ÖÛ......\n", me);
        		room = find_object(__DIR__"flowerboat");
			if(!objectp(room)) room = load_object(__DIR__"flowerboat");
			me->move(room);
			message_vision("$NÇáÇÉµÄÂäÔÚĞ¡ÖÛÉÏ¡£\n", me);
        		return 1;
        	}
        	else
        	{
        		message_vision(HIY"$NÅÄÅÄÆ¨¹É£¬¹Ä×ãÓÂÆø£¬×¼±¸ÏòºşĞÄ·ÉÔ¾¡£\n"NOR, me);
        		message_vision(HIY"$NÖúÅÜ¼¸²½£¬Í»È»¡°°¡Ñ½£¡¡±Ò»Éù£¬Á³É«²Ô°×µÄÍ£ÔÚºş±ß¡£\n"NOR, me);
        		me->perform_busy(3);
        		return 1;
        	}        		
        }
        else
        {
                write("Äã²»¿ÉÒÔÔ¾Ïò"+arg+"\n");
                return 1;
        }
}

int do_swim(string arg)
{
        object room;
        object me;
        if(!arg || arg=="")
        {
                write("ÄãÒªÔÚÄÄÀïÓÎ£¿\n");
                return 1;
        }
        if( arg == "Ì«Ñôºş" || arg == "lake" )
        {
        	me = this_player();
        	if ( me->is_busy() )
        		return notify_fail("ÄãÏÖÔÚÃ¦µÃºÜ£¬²»ÄÜÒÆ¶¯¡£\n");
        	if ( random(100) > 5 )
        	{
        		message_vision(HIY"$NÈç²ÔğØÏ·Ë®£¬×ËÊÆÂüÃîµÄÔ¾ÈëºşÖĞ¡£\n"NOR, me);
        		message_vision(HIY"$NÍ»È»¾õµÃÓĞĞ©»¬»¬µÄ¶«Î÷×êÈë....£¬$NÊÖÃ¦½ÅÂÒÒ»ÕóÂÒ»®£¬ÓÎ»Ø°¶±ß¡£\n"NOR, me);
        		me->start_busy(2);
        		return 1;
        	}
        	else
        	{
        		message_vision(HIY"$N¸ß¸ßÔ¾Æğ£¬°ë¿ÕÖĞÒ»¸ö×ªÕÛ£¬×ö×ÔÓÉÂäÌå£¬Ö±ÂäºşÖĞ¡£\n"NOR, me);
        		message_vision(HIY"ºşË®Ë®Î»Í»È»ÏÂ½µ£¬$NÒ»Í·Ôúµ½ºşµ×ÑÒÊ¯ÉÏ¡£\n"NOR, me);
        		me->start_busy(3);
        		me->unconcious();
        		return 1;
        	}        		
        }
        else
        {
                write("Äã²»¿ÉÒÔÓÎ"+arg+"\n");
                return 1;
        }
}
