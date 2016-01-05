// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "¹íÃÅ¹Ø");
        set("long", @LONG
ÃÍÒ»¾ªĞÑ£¬²»¾õÉíÔÚ¹íÃÅ¹Ø£¬¸ß´óµÄ³ÇÇ½±ßÎ¼Ë®»·ÈÆ£¬ÒõÆøÉ­É­£¬¼¸¸öÃæÄ¿Õø
ÄüµÄÅ£Í·£¬ÂíÃæÊÖ³ÖÎäÆ÷°ÑÊØ³ÇÃÅ£¬¹´ËÀÈËÊÖ³ÖÌúÁ´ÕıÔÚÍÏ×§×Å¼¸¸öÈËÓ°×ßÁË½øÈ¥
£®£®£®£®£®£®£®£¬³ÇÃÅÂ¥ÉÏ¸ßĞüÒ»·ùÅÆØÒ£º
[31m

			¹íÃÅ¹Ø
[32m
LONG
        );
        set("no_fight",1);
        set("exits", ([
                "south" : __DIR__"naihe",
		"east" : __DIR__"aihe2",
        ]) );
        set("objects", ([
		__DIR__"npc/panguan" : 1,
        ]) );
	set("coor/x",0);
	set("coor/y",30);
	set("coor/z",0);
	setup();
}
