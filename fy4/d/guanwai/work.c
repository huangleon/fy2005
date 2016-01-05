// work.c
//#include "/feature/damage.c"

inherit ROOM;

void create()
{
        set("short", "Ê¯³¡");
        set("long", @LONG
Ç¡¿Ë²·ÀïÉ½Ê¢²ú¸÷ÖÖÉÏµÈÊ¯ÁÏ¡£ÕâÀïÏõÑÌÃÖÂþ£¬ºÜ¶àÈË¶¼ÔÚÐÁ¿àµÄÀÍ¶¯×Å¡£ÓÃ
×Ô¼ºµÄº¹Ë®È¥»»È¡Ò»Ð©ÊÕÈë¡£Ã¿¸öµ½ÕâÀï¹¤×÷µÄÈË¶¼¿ÉÒÔÄÃµ½Ò»·ÝºÜ¹«Æ½µÄ±¨³ê¡£
Ðí¶àÈËÕýÔÚÃ¦Ã¦ÂµÂµµÄ¹¤×÷×Å£¬ÃÅ¿Ú¹ÒÖøÒ»¿éÅÆ×Ó[37m(sign)[32m¡£
LONG
        );

    set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"stoneroad",
		"north" : __DIR__"octo5",
		"south" : __DIR__"birdroad",
	]));
        set("outdoors", "guanwai");

        set("item_desc", ([
                "sign": @TEXT
ÏÖÔÚÕý½ôÈ±ÈËÊÖ£¬¼±Ðè¹ÍÓ¶Ò»Åú¶Ì¹¤À´¸É»î¡£

work     ¿ªÊ¼¹¤×÷¡£

TEXT
		
        ]) );
	set("coor/x",0);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
}


void init()
{
        add_action("do_work", "work");
}

void	reset() {
		set("worked",0);
		::reset();
}

int do_work(string arg)
{
        object ob;
        object me;

		if (query("worked")> 20)
			return notify_fail("ÕâÅúÊ¯Í·°áÍêÁË£¬µÈÏÂÅú°É¡£\n");
			
        me = this_player();
		if(me->is_busy()) return notify_fail("ÄãµÄ¶¯×÷»¹Ã»ÓÐÍê³É£¬²»ÄÜ¹¤×÷¡£\n");
		message_vision("$NÐÁ¿àµÄ¹¤×÷ÖÕÓÚ½áÊøÁË£¬¿ÉÈËÒ²ÀÛµÄÒªËÀ¡£\n", me);
		add("worked",1);
		me->receive_wound("gin",30,me);
		me->receive_wound("sen",30, me);
//		me->status_msg("all");
		me->set_temp("last_damage_from","ÔÚÇ¡¿Ë²·ÀïÉ½¾ÖÊ¯³¡¸É»îÀÍÀÛ¹ý¶È¶øËÀ¡£\n");
		ob = new("/obj/money/silver");
		if (!ob->move(me))
			ob->move(environment(me));
		message_vision("ÀÏ°å¶Ô$NËµ£ºÕâÊÇÄãµÄ¹¤Ç®¡£\n", me);
		me->perform_busy(2);
		return 1;
}
