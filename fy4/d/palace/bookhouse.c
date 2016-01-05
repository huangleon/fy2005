
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "Êé·¿");
        set("long", @LONG
Êé·¿Ð¡ÇÉ¾«ÖÂ£¬´òÉ¨µÄÏË³¾²»È»¡£¿¿Ç½µÄÊé¼ÜÉÏ°ÚÂúÁË¸÷ÀàÊé¼®£¬Ò»ÕÅºìÄ¾Êé
×ÀºáÔÚµñ»¨´°Ç°£¬ÅÔ±ß·ÅÁË¸öÐåËú¡£¼¸±¾·­¿ªµÄÊé·ÅÔÚ[33mÊé×À[32mÉÏ£¬×óÊÖ±ßÊÇÒ»ÕµË®¾§
µÆ£¬ÅÔ±ßÊÇÒ»¸ö´äÂÌÓûµÎµÄôä´ä»¨Æ¿£¬ÀïÃæÏ¡ÊèµØ²åÁË¼¸Ö»°×É«µÄÉ½²è»¨¡£
LONG
        );
        set("exits", ([ 
  		"west" : __DIR__"jinghouse",
  		"south" : __DIR__"juhua",
	]));
        set("objects", ([
        	__DIR__"obj/desk" : 1,
        	__DIR__"npc/manfeng" : 1,
                      ]) );

	set("coor/x",60);
	set("coor/y",40);
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
	item = new(BOOKS"skill/iceheart_11");
	item->move(con);
	}
}
