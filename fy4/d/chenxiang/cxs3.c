// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "ĞşÎäÃÅ");
        set("long", @LONG
ĞşÎäÃÅÊµ¼ÊÖ»ÊÇ³ÁÏãÕòÄÏÃæÁÙ½ü¶«Î÷ÃÅ´¦µÄÒ»¸öÅÆ·»£¬ÕòÉÏµÄ¸»ÉğÃÇºÃ´óÏ²¹¦£¬
°ÑÔ­À´µÄ³ÇÇ½ÍÆµ¹ÖØ½¨£¬¶«Ê×Í¨Ïò[33m·çÔÆµÀ[32m£¬Î÷Ãæ³ö³Çºó±ãÊÇÖøÃûµÄ[33mÀÇÉ½[32m¡£ĞşÎäÃÅ·É
éÜïÎ×©£¬¿ÉÏ§ÉÙÓĞÓÎ¿Í£¬Ö»ÊÇÅ¼¶ûÓĞĞ¡ÇÉµÄÄñ¶ùÔÚ´Ë×¤×ã¡£
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"cxs2",
  "west" : __DIR__"mw",
  "east" : __DIR__"me",
  "south" : __DIR__"cxs4",
]));
        set("outdoors", "chenxiang");
	set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
