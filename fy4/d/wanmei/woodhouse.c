inherit ROOM;
// Copyright (C) 2002, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

void create()
{
        set("short", "Ð¡Ä¾ÎÝ");
        set("long", @LONG
Ä¾ÎÝÖ»ÓÐ°ë±ß¶¥£¬Ò»¿ÃÀÏÃ·Ê÷¸Ç×¡ÁËÄÇ°ë±ß¡£Ç½ÉÏ¹Ò×Å¼¸ÌõÔ¡½í£¬Ñô¹âÍ¸¹ýÊ÷
Ö¦ÕÕÔÚÔ¡½íÉÏ¡£Ò»ÌõÖñ¹Ü´Ó·¿¶¥´¹ÏÂ£¬Öñ¹ÜµÄ¾¡Í·Èû×ÅÒ»¸ö[37mÄ¾Èû×Ó[32m£¬Å¼¶û»¹ÓÐË®Öé
µÎÏÂ¡£
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"frontyard",
]));
        set("objects", ([
        __DIR__"obj/towel": 1,
                        ]) );
        set("item_desc", ([
                "Ä¾Èû×Ó": "ÄãËÆºõ¿ÉÒÔ°ÑËü°Î£¨£ð£õ£ì£ì£©ÏÂÀ´£¡\n",

        ]) );
	set("coor/x",-30);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}
void init()
{
	add_action("do_pull","pull");
	add_action("do_climb","climb");
}


int do_pull(string arg)
{
	object me;
	if (arg == "Ä¾Èû×Ó" || arg == "Ä¾Èû" || arg == "cork" ) {
		if(query("resource/water"))
			return notify_fail("Ä¾Èû×ÓÒÑ¾­±»°ÎÏÂÀ´ÁË¡£\n");
		me = this_player();
		message_vision("$N£¢àÛ£¢µÄÒ»Éù½«Ä¾Èû×Ó°ÎÁËÏÂÀ´£¬Ã°×ÅÈÈÆøµÄË®ÂíÉÏÁ÷ÁËÏÂÀ´¡£\n",me);
		set("resource/water",1);
		set("liquid/name","ÈÈË®");
		call_out("remove_water",50);
		return 1;
	}
	return notify_fail("ÄãÒª°ÎÊ²Ã´£¿\n");
}

int remove_water()
{
	tell_object(this_object(),"ÈÈË®µÎÁË¼¸µÎ£¬¾ÍÁ÷¹âÁË¡£\n");
	delete("resource/water");
        delete("liquid/name");
	return 1;
}

int do_climb(string arg)
{
	object me,room;
	me = this_player();
	if (arg == "tree" || arg == "ÀÏÃ·Ê÷" || arg == "Ã·Ê÷") {
		message_vision("$N£¢à²£¢µÄÒ»Éù£¬Ë³×ÅÀÏÃ·Ê÷´ÜÉÏÎÝ¶¥¡£\n",me);
		room = find_object(__DIR__"roof");
		if (!room)
			room = load_object(__DIR__"roof");
		me->move(room);
		return 1;	
	}
	return notify_fail("ÄãÏëÅÀÊ²Ã´£¿\n");
}

void reset(){
	object obj;
	::reset();
	if(!present("towel", this_object())){
		obj = new(__DIR__"obj/towel");
		if(objectp(obj)){
			obj->move(this_object());
		}
	}
	return;
}