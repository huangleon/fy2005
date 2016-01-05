#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIW"·çÌ³"NOR);
        set("long", @LONG
		
      	       .
              /=\\		
             /===\ \	            ·çÌ³ÄË½ğÇ®°ïËù½¨£¬Ì³ÖĞÁ÷¹âÒç²Ê£¬½ğ±Ì
            /=[0;1;37m·ç[0m==\' \	   	»Ô»Í£¬¹©·îµÄ·çÉñ°µÖĞµÀ³öÉÏ¹ÙÒâÓûºô·ç»½Óê
           /=======\'' \	È¨Çã³¯Ò°µÄÒ°ĞÄ¡£¼´Ê¹ÔÚ·çÔÆ³ÇÈç´ËÁú»¢»ã¾Û¡¢
          /=========\ '  \	ÆæÈË±²³öµÄµØ·½£¬ÉÏ¹Ù½ğºçÒÀ¾É¿ÉÒÔËµµÃÉÏ¹Ù
         /====[0;1;37mÌ³[0m=====\' /	½ğºçÒÀ¾É¿ÉÒÔËµµÃÉÏÊÇÎäÁÖÖĞµÄ°ÔÖ÷£¬½­ºşÖĞ
        /=============\/	µÄ»ÊµÛ¡£
                   
LONG);
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"wcloud1",
  "east" : __DIR__"fysquare",
  "north" : __DIR__"qcyzdian",
  "south" : __DIR__"pxhdian",
]));
        set("outdoors", "fengyun");
        set("objects", ([
//        __DIR__"npc/mei": 1,
                        ]) );

	set("coor/x",0);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
//	replace_program(ROOM);
}


/*
void init() {
	  add_action("do_dazuo","dazuo");
	}
	
int do_dazuo(string arg) {
	object me;
	me=this_player();
	tell_object(me,"´ËµØ²»ÄÜ´ò×ø¡£\n");
	return 1;
}*/

