// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "³ÁÏã³ÇÄÏ½Ö");
        set("long", @LONG
³ÁÏãÒÀÉ½¶ø½¨£¬ÏòÎ÷±ãÊÇ·ç¾°ĞãÀöµÄ[33m»ÆÉ½[32m¡£ÕòÖĞ´ó²¿·Ö¾ÓÃñÊÇÒÔ¸ûÖÖË®µ¾ÎªÉú£¬
Ã¿µ½°øÍí£¬Å©·òÃÇÍÏ×Å³ÁÖØµÄ²½·¥£¬´ø×ÅÂúÉíµÄº¹Ë®´ÓÌïÖĞ»ØÀ´£¬»Øµ½ÕâÀïÒ»×ù×ù
Ã°×ÅÅ¨Å¨µÄ´¶ÑÌ£¬É¢·¢×ÅÓÕÈËµÄµ¾Ã×ÏãÆøµÄ¼Ò¡£
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"cxcenter",
  "south" : __DIR__"cxcenter1",
  "west" : AREA_HUANGSHAN"shanmen",
]));
        set("objects", ([
	__DIR__"npc/farmer": 2,
                        ]) );
        set("outdoors", "chenxiang");
	set("coor/x",0);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
