#include <room.h>
inherit DOOR_ROOM;

void create()
{
        set("short", "�ŷ�");
        set("long", @LONG
���Ǵ��ڱ��������ŷ�����������Ʈ�����ϵ���Ҷ��ľ�������˴������ε�
��ɽ������������ƺ�������Ķ����ڡ����������Ľ���������
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"bedroom",
]));
        set("objects", ([
                __DIR__"obj/pigmeat" : 3,
		__DIR__"obj/qiwine" : 3,
		__DIR__"npc/cook" : 1,
        ]) );


        create_door("north", "door","������", "south", DOOR_CLOSED);

	set("coor/x",-10);
	set("coor/y",30);
	set("coor/z",30);
	setup();
}

