
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "É½ÑÂ±ß");
	set("long", @LONG
ÑÛÇ°ÃÍÈ»Ò»ÁÁ£¬ÄãÖÕÓÚ×ß³öÁËÄÇ¿ÉÅÂµÄÔ­Ê¼´ÔÁÖ£¬µ«ÊÇ£¬Ç°ÃæÂÒ[37mÊ¯[32m´ÔÉú£¬ÑÂ±ßÊÇ
Ò»µÀÉî²»¼ûµ×µÄÍòÕÉÉîÔ¨¡£ÏÂÃæ°×ÔÆçÔÈÆ£¬Ê²Ã´¶¼¿´²»¼û£¬¾ÍÁ¬ËÀÈËµÄÓÄÁé¶¼¿´²»¼û¡£
ÄÑµÀÄÇÓÄÁéÉ½×¯¾ÍÔÚÕâÍòÕÉÉîÔ¨Ö®ÏÂ£¿
LONG
	);
	set("exits", ([
                "west" : __DIR__"forest7",
                "south" : __DIR__"forest6",
	]));
	set("objects", ([
                __DIR__"obj/rock" : 1,
	]));
	set("outdoors", "ghost");
	set("coor/x",-90);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}

void init()
{
	object me;
	object          *inv;
        object          con, item;
        int             i;
        
        con = present("rock", this_object());
        if (!living(con)) 
	if (!present("pipe",con)) {
	         item = new(__DIR__"obj/pipe");
	         item->move(con);
	}
    	
	me = this_player();
	if(me->query_temp("marks/know_ghost")){
		tell_object(me, HIG"ÑÛÇ°¾°É«ËÆºõÓĞĞ©ÊìÏ¤£¬ÄãÒÀÏ¡¼ÇµÃÍù±±·½µÄµÍ´¦×ß¿ÉÒÔ³öÈ¥¡£\n\n"NOR);
		add_action("do_northdown", "go");
	}
	if(this_object()->query("exits/east"))
		delete("exits/east");
}

void reset()
{
        object          *inv;
        object          con, item;
        int             i;
        ::reset();
        con = present("rock", this_object());
        if (!living(con)) 
		if (!present("pipe",con)) {
		         item = new(__DIR__"obj/pipe");
		         item->move(con);
		}
        if(query("exits/east"))	
        	delete("exits/east");
	
}

void pipe_notify()
{
        object ob;
        message("vision", WHT "\n°×ÔÆÖ®¼äºöÈ»³öÏÖÁËÒ»¸öÈË£¬Ê²Ã´ÈËÄÜÁè¿ÕÕ¾ÔÚ°×ÔÆÀï£¿\n"NOR, this_object() );
        message("vision", WHT "Äã×ßµ½ÑÂ±ß²Å·¢ÏÖ£¬°×ÔÆÀïÓĞÌõºÜ´ÖµÄ¸ÖË÷£¬ºá¹áÁËÁ½ÅÔµÄÉ½ÑÂ¡£\n"NOR, this_object() );
        set("exits/east", __DIR__"bridge" );
}


int do_northdown(string arg){
	object room;
	object me=this_player();
	
	if (arg == "northdown")
	if(me->query_temp("marks/know_ghost")) {
		message("vision", me->name()+"Î¢Ò»¶¨Éñ±æ±ğÁËÒ»ÏÂ·½Ïò£¬ÉíĞÎÔÚÉ½ÁÖÖ®ÖĞÉÁÁË¼¸ÏÂ¾Í²»¼ûÁË¡£\n", 
				environment(me), me);	
		room = find_object(__DIR__"lroad3");
		if(!objectp(room)){
			room = load_object(__DIR__"lroad3");
		}
		me->move(room);
		message("vision", me->name()+"´Ó´ÔÁÖÖ®ÖĞ×êÁË³öÀ´¡£\n", environment(me), me);
		return 1;
	}
	return 0;
}
