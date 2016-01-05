inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "ÐùÌÃ");
        set("long", @LONG
ÐùÌÃÖÐÒ»³¾²»È¾£¬´°Ã÷¼¸¾»£¬ËÄ±Ú¶ÑÂúÁËÊé¼Ü£¬ÎÝ½ÇÒ»ÕÅÇÙ¼¸£¬ÇÙÅÔÒ»·½ÆåèÒ¡£
»¹ÓÐ¼¸ÕÅÎ´Íê³ÉµÄ»­£¬É¢ÂÒµØ¶ÑÔÚÁíÒ»½ÇµÄ[33m»­×À[32mÉÏ¡£ÃÅÉÏ¹ÒÖøÏæåúÁ±£¬Íµ¹ýÖñÁ±£¬
¿ÉÒÔ¿´¼ûÄÇÒ»ÍÝÊ¢¿ªµÄ¾Õ»¨¡£
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"juhua",
]));
        set("objects", ([
        __DIR__"obj/desk" : 1,
	__DIR__"npc/laofuren" : 1,
	__DIR__"npc/maid" : 1,
                        ]) );

	set("coor/x",60);
	set("coor/y",20);
	set("coor/z",0);
	setup();
}
void reset()
{
	object *inv;
	object con, item;
	::reset();
	con = present("desk", this_object());
        inv = all_inventory(con);
        if( !sizeof(inv)) {
		item = new(BOOKS"skill/zuixian-step_50");
		item->move(con);
	}
}
