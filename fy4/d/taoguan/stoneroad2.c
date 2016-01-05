// ; annie 07.2003
// dancing_faery@hotmail.com
#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
    seteuid(getuid());
        set("short", "ÇàÊ¯Ğ¡¾¶");
        set("long", @LONG
Ğ¡¾¶µÄÒ»²àÊÇÒ»¶°Ä¾ÔìÁ½²ã¸ßµÄÎİ×Ó¡£Îİ×ÓËÄÖÜµÄÃÅ´°¶¼½ô½ôµÄ¹ØÖø, ÃÅ¿ÚÉÏ
·½¹ÒÖøÒ»·½À¶É«ÁğÁ§ØÒ¶î, ÉÏÊé[33m¡ºÌ«Çåµî¡»[32mÈı¸ö½ğ×Ö£¬ÃÅÅÔÁ¢ÖøÒ»¸öÊ¯±®¡£Ğ¡¾¶ÔÙ
ÍùÇ°Í¨ÏòÒ»¸ö¼Å¾²µÄÔºÂä£¬ÔºÃÅ°ë¿ª×Å¡£
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
            "southeast" : __DIR__"stoneroad",
            "north" : __DIR__"book_room1",
            "northwest": __DIR__"bieyuan",
	]));
        set("outdoors", "taoguan");
        set("item_desc", ([
            "bei" : "Ê¯±®ÉÏĞ´Öø : \n\n"
                     "    ·Ç\n"
                     "    Èı  ²»\n"
                     "    Çå  µÃ\n"
                     "    µÜ  ½ø\n"
                     "    ×Ó  Èë\n\nÊ¯±®ÉÏµÄÒ»Ğ©ÇàÌ¦ÓĞ±»ÈË²Á¹ıµÄºÛ¼££¬ÄãÒ²Ğí¿ÉÒÔÊÔ×ÅÍÆÍÆ¿´£¨push£©¡£\n\n",
            "Ê¯±®" : "Ê¯±®ÉÏĞ´Öø : \n\n"
                     "    ·Ç\n"
                     "    Èı  ²»\n"
                     "    Çå  µÃ\n"
                     "    µÜ  ½ø\n"
                     "    ×Ó  Èë\n\nÊ¯±®ÉÏµÄÒ»Ğ©ÇàÌ¦ÓĞ±»ÈË²Á¹ıµÄºÛ¼££¬ÄãÒ²Ğí¿ÉÒÔÊÔ×ÅÍÆÍÆ¿´£¨push£©¡£\n\n"
           ]) );

	set("coor/x",-20);
	set("coor/y",20);
	set("coor/z",0);
	setup();
}


void init()
{
	add_action("do_push", "push");
}

int do_push(string arg)
{
   	object me, room;
	int i,flag=0;
	string *msg = ({
"·Ç","Èı","Çå","µÜ","×Ó","²»","µÃ","½ø","Èë",
});

   	me = this_player();


	if (!arg || (arg != "bei" && arg != "Ê¯±®"
		&& member_array(arg, msg) == -1 ))
		return notify_fail("ÄãÒªÍÆÊ²Ã´£¿\n");

	if (REWARD_D->riddle_check(me,"ÎŞ×ÖÌìÊé") != 5 
		&& !REWARD_D->check_m_success(me,"·çÁÖ»ğÉ½")) // ÓĞÁËÈıµÜËæÊ±¶¼¿ÉÒÔÀ´ÍÆ
		return notify_fail("
Ê¯±®Ò¡ÁËÒ¡£¬ÉÏÃæµÄ×ÖËÆºõ¶¯ÁË¼¸ÏÂ£¬Äã¸Ï½ôÈàÁËÈàÑÛ¾¦£¬
Ê¯±®»¹ÊÇÕ¾ÔÚÄÇÀï£¬ÀäÀäµØ¶¢×ÅÄã£¬ÖÜÎ§»¹ÊÇËÀ¼ÅÒ»Æ¬¡£\n");

	if (arg == "bei" || arg == "Ê¯±®") 
		return notify_fail("
Ê¯±®Ò¡ÁËÒ¡£¬ÉÏÃæµÄ×ÖËÆºõ¶¯ÁË¼¸ÏÂ£¬Äã¸Ï½ôÈàÁËÈàÑÛ¾¦£¬
Ê¯±®»¹ÊÇÕ¾ÔÚÄÇÀï£¬ÀäÀäµØ¶¢×ÅÄã£¬ÖÜÎ§»¹ÊÇËÀ¼ÅÒ»Æ¬¡£\n");

	for (i=0;i<9 ;i++ )
	{
		if (arg == msg[i])
		{
			if (query(("flag/"+(i+1))) == 1)
			{
				tell_object(me,"Ğ´ÓĞ£¢"+arg+"£¢×ÖµÄÊ¯¿éÒÑ¾­Ïİ½øÈ¥ÁË¡£\n");
				return 1;
			}
/*			else
				tell_object(me,"Ğ´ÓĞ£¢"+query("flag/"+i+1)+"£¢×ÖµÄÊ¯¿éÒÑ¾­Ïİ½øÈ¥ÁË¡£"+"flag/"+(i+1));
*/
			if (i != 1 && i != 3)
			{
				me->set_temp("annie/demon_taoguanstone",0);
			}
			else if (i == 1)
			{
				if (me->query_temp("annie/demon_taoguanstone") !=1)
					me->set_temp("annie/demon_taoguanstone",0);
				else
					me->set_temp("annie/demon_taoguanstone",2);
			}
			else if (i == 3)
			{
				if (me->query_temp("annie/demon_taoguanstone") !=0)
					me->set_temp("annie/demon_taoguanstone",0);
				else
					me->set_temp("annie/demon_taoguanstone",1);
			}
			message_vision(CYN"$NÉì³öÊÖ£¬ÔÚÊ¯±®µÄ£¢"+arg+"£¢×ÖÉÏÍÆÁËÒ»ÏÂ¡£\nĞ´ÓĞ£¢"+arg+"£¢×ÖµÄÊ¯¿é»º»ºµÄËõÁË½øÈ¥¡£\n"NOR,me);
			flag = i+1;
		}
	}
	if (flag)
	{
		set("flag/"+flag,1);
		call_out("do_eject",2,me,flag);
		return 1;
	}
		return notify_fail("ÄãÒªÍÆÊ²Ã´£¿");
}


void do_eject(object me,int flag)
{
	string *msg = ({
"·Ç","Èı","Çå","µÜ","×Ó","²»","µÃ","½ø","Èë",
});
	set("flag/"+flag,0);
	if (me->query_temp("annie/demon_taoguanstone") == 2 && environment(me) == this_object())
	{
		tell_object(me,CYN"Ê¯±®ÉÏĞ´ÓĞ£¢Èı£¢×ÖµÄÊ¯¿é»º»ºµÄ»¬ÁË³öÀ´¡£\n"NOR);
		tell_object(me,CYN"Ê¯±®ÉÏĞ´ÓĞ£¢µÜ£¢×ÖµÄÊ¯¿é»º»ºµÄ»¬ÁË³öÀ´¡£\n"NOR);
		me->set_temp("annie/demon_taoguanstone",0);
		message_vision(CYN"\nÖ»Ìı£¢¿©À²£¢Ò»Ïì£¬Ê¯±®ºöÈ»Õû¸öÏòÅÔ±ß»¬¿ªÈı³ß¡£\n"NOR,me);
		message_vision(CYN"$N´ëÊÖ²»¼°£¬Õû¸öÈËË¤ÁËÏÂÈ¥¡£\n"NOR,me);
		me->move(load_object(__DIR__"secretpath1"));
		if (me->query("kee") > 300)
			me->receive_wound("kee",300);
		else me->unconcious();
		message_vision(CYN"$N£¢Å¾àª£¢Ò»ÉùµôÁËÏÂÀ´¡£\n"NOR,me);
		tell_room(this_object(),"Ê¯±®»º»ºµÄ»¬»ØÔ­Î»£¬·Â·ğÊ²Ã´Ò²Ã»ÓĞ·¢Éú¹ı¡£\n");
		tell_room(this_object(),CYN"Ê¯±®ÉÏĞ´ÓĞ£¢Èı£¢×ÖµÄÊ¯¿é»º»ºµÄ»¬ÁË³öÀ´¡£\n"NOR);
		return;		
	}
	me->set_temp("annie/demon_taoguanstone",0);
	tell_room(this_object(),CYN"Ê¯±®ÉÏĞ´ÓĞ£¢"+msg[flag-1]+"£¢×ÖµÄÊ¯¿é»º»ºµÄ»¬ÁË³öÀ´¡£\n"NOR);
	return;
}


/*
 
               (\~~~/)            
               ( £®£®)        

               (_____)~£®      
   
¡¡¡¡¡¡¡¡¡¡¡¡¡¡- FengYun - ¡¡¡¡¡¡
¡¡¡¡¡¡¡¡¡¡¡¡annie 10.2003
¡¡¡¡¡¡dancing_faery@hotmail.com
*/

