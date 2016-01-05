inherit ROOM;
void create()
{
        set("short", "ºóÃÅ");
        set("long", @LONG
»¨Ô°µÄ¶«Ç½ÓÐÒ»¸öÐ¡[37mÄ¾ÃÅ[32m£¬Ä¾ÃÅÕý¶Ô×ÅÒ»×ùÐ¡¹°ÇÅ£¬Ò»ÌõÆÌÂú¶ìÂÑÊ¯µÄÐ¡Â·òê
ÑÑµØ´ÓÄ¾ÃÅÇ°´©¹ý£¬ÏûÊ§ÔÚ»¨´ÔÖÐ¡£ÒòÎªÕâÀïÆ½Ê±ÉÙÓÐÈËÐÐ×ß£¬µØÉÏµÄÊ¯·ìÖÐ²»Öª
ºÎÊ±³¤³öÐ©²»ÖªÃûµÄ»¨²Ý£¬ËäÊÇÎÞÃûÒ°»¨£¬È´Ò²¿ªµÄ·Ò·¼ÑÞÀö¡£
LONG
        );
   set("exits", ([ /* sizeof() == 4 */
   "westup" : __DIR__"bridge",
   "northwest" : __DIR__"northpond.c",	
   "south" : __DIR__"southpond1.c",	
   ]));

   set("objects", ([
      __DIR__"obj/cao": 1,
   ]) );
	set("item_desc", ([
		"door" : "Ð¡ÃÅ½ô±Õ×Å£¬²»ÖªµÀºóÃæÍ¨ÏòÄÇÀï¡£\n",
		"Ä¾ÃÅ" : "Ð¡ÃÅ½ô±Õ×Å£¬²»ÖªµÀºóÃæÍ¨ÏòÄÇÀï ¡£\n",
	]));
   set("outdoors","qingping");
	set("coor/x",20);
	set("coor/y",0);
	set("coor/z",0);
	setup();
	
}

void init(){
	add_action("do_push", "push");
}

int do_push(string arg){
	object me, room;
	
	me = this_player();
	if(!arg || (arg != "door" && arg != "Ð¡Ä¾ÃÅ" && arg != "Ä¾ÃÅ")){
		return notify_fail("ÄãÒªÍÆÊ²Ã´£¿\n");
	}
	if(query("exits/east")) {
		return notify_fail("ÃÅÒÑ¾­ÊÇ¿ª×ÅµÄÁË¡£\n");
	}
	message_vision("$NÌ½ÊÖÍùÐ¡Ä¾ÃÅÉÏÒ»ÍÆ£¬¿©Ö¨Ö¨¡£¡£Ð¡ÃÅËæÊÖ´ò¿ª£¬Â¶³öÒ»Ìõ»ÄÁ¹µÄÐ¡¾¶¡£\n", me);
	set("exits/east", __DIR__"path");
	room = find_object(__DIR__"path");
	if(!objectp(room)){
		room = load_object(__DIR__"path");
	}
	message("vision", "Ð¡ÃÅ±»ÈË´ÓÀïÃæ´ò¿ª¡£\n", room);
	room->set("exits/west", __DIR__"backdoor");
	call_out("close_path", 5);
	return 1;
}

void close_path(){
	if( query("exits/east") ) {
		message("vision","¿©Ö¨Ö¨¡£¡£Ð¡ÃÅÑÚÉÏÓÖÕÚ×¡ÁËÐ¡¾¶¡£\n",this_object() );
		delete("exits/east");
	}
}

void reset()
{
   object *inv;
   object item1, cao;
   ::reset();

   cao = present("cao", this_object());
   inv = all_inventory(cao);
   if( !sizeof(inv)) {
      item1 = new(__DIR__"obj/paper");
      item1->move(cao);
   }
}

