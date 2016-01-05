inherit DOOR_ROOM;
#include <ansi.h>
#include <room.h>

void create()

{
        set("short", "ÊØÍûÈû");
        set("long", @LONG
Õâ¼¸¼äÄ¾Îİ±¾ÊÇÎôÈÕÑ²±ßÊù×äµÄÊØÍûÈû£¬ÒÑÊ®·Ö³Â¾É£¬ÓĞ¼¸ÉÈ´°×ÓÃ»ÓĞ¹Ø£¬Îİ
×ÓÀïºÃÏñÒÑÓĞÁËµÆ¹â£¬ÏëÀ´Îİ×ÓÀïÒ»Ö±¶¼ÓĞÈËµÄ¡£Ê®ÊıÕÉÍâÓĞÈı¿Ã´óÊ÷£¬ÔçÒÑ¿İËÀ
¶àÄêÁË¡£[37mÄ¾Îİ[32mÀïÒşÔ¼ÓĞÒ»ÕóµÍÃÔµÄÀÖÉù´«³ö£¬Íñ×ªÏú»ê£¬ÓûÏÉÓûËÀ¡£
LONG
        );
        set("exits", ([ 
		"north":	__DIR__"desert_cabin2",
		"south" : __DIR__"yangguan1c",
	]));
        set("objects", ([
        	
	]) );
	set("item_desc", ([
		"Ä¾Îİ": "Ò»ÉÈÄ¾ÃÅÍ¨ÏòÄ¾Îİ¡£\n",
		"cabin": "Ò»ÉÈÄ¾ÃÅÍ¨ÏòÄ¾Îİ¡£\n",
	]));
	set("outdoors", "zangbei");
        set("coor/x",-90);
        set("coor/y",310);
        set("coor/z",0);
        set("map","zbeast");
	setup();
	create_door("north", "door","Ä¾ÃÅ", "south", DOOR_CLOSED);

}
