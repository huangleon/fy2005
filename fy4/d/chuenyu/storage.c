#include <room.h>
inherit DOOR_ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
һ��СС�Ĵ����ҡ��ı��ϲ����˻ҳ���
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"west_blackge",
]));
        set("objects", ([
                "/obj/weapon/sword" : 5,
        ]) );

        create_door("north", "door","ľ��", "south", DOOR_CLOSED);
	set("coor/x",-20);
	set("coor/y",30);
	set("coor/z",20);
	setup();
}

