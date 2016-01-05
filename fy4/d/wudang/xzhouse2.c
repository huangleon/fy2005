
inherit ROOM;

void create()
{
	object con, item;

	set("short", "Å©¼Ò");
	set("long", @LONG
Õâ¼þÎÝ×ÓÃ÷ÏÔ±ÈÖÜÎ§µÄÒªÆÆ¾ÉÒ»Ð©£¬ÃÅÐéÑÚÖø£¬ÎÝÄÚ°ÚÉè·Ç³£¼òÆÓ£¬Ö»ÓÐ¼¸Ñù
Éú»î±ØÐèÆ·£¬ÎÝ½Ç¶Ñ×ÅµÄÅ©¾ßÉÏ»ýÂúÁË»Ò³¾£¬ËÆºõÒÑ¾­ºÜ¾ÃÃ»ÈË¶¯¹ýÁË¡£[33mÇ½[32mÉÏ¹ÒÖø
Ò»±úÌú½£·ÖÍâÐÑÄ¿£¬Ê¹ÈËÈÌ²»×¡¿ªÊ¼²ÂÏë´ËÎÝÖ÷ÈËµÄÀ´Àú¡£
LONG
	);
	set("exits", ([
		"east" : __DIR__"xzroad3",
	]));
	set("objects", ([
		__DIR__"obj/wall": 1,
		__DIR__"npc/dahanwife": 1,
	]));
	set("coor/x",-10);
	set("coor/y",70);
	set("coor/z",-50);
	setup();
}

void reset()
{
        object          *inv;
        object          con, item;
        int             i;

        ::reset();
        con = present("wall", this_object());
        inv = all_inventory(con);
        if( sizeof(inv) != 1) {
                for(i=sizeof(inv)-1; i>=0; i--) destruct(inv[i]);
                item = new(__DIR__"obj/sword2");
                item->move(con);
	}
}
