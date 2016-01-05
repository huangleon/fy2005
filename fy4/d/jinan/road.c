inherit ROOM;
void create()
{
        set("short", "ÇàÊ¯Â·");
        set("long", @LONG
Ì©É½½ÅÏÂÏò¶«Ò»Ìõ³¤¶øÕ­µÄÇàÊ¯Â·£¬Â·µÄ¾¡Í·±ãÊÇºÕºÕÓĞÃûµÄ[33m¡ºÇåÆ½É½×¯¡»[32m£¬
Â·ÉÏĞĞÈË²»¶à£¬À´ÍùµÄ¶à°ëÊÇÎäÁÖºÀ½Ü£¬ÒòÎªÇåÆ½½£¿Í°×Èı¿ÕÕıÊÇÖĞÔ­ÎäÁÖµÄµÚÒ»
½£ÊÖ£¬Ò»ÊÖÇåÆ½½£·¨ÔçÒÑÎŞµĞÌìÏÂ£¬Ä½Ãû¶øÀ´ÕßÉõ¶à¡£
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : AREA_QINGPING"gate",
  "southwest" : __DIR__"road2",
  "north" : __DIR__"road3",
]));

   	set("outdoors","jinan");
	set("coor/x",70);
	set("coor/y",130);
	set("coor/z",0);
	setup();
	
	replace_program(ROOM);
}
