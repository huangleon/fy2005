#include <room.h>
inherit DOOR_ROOM;

void create()
{
        set("short", "���ɸ�����");
        set("long", @LONG
���Ǻ��ɱ������ڻ�̫ӭ���������������������õ�Ӻ�ٵ��š����Ǻ��ɸ�
���������������򱱶��Ǿ����޼����Ļ�԰��¥�����Ǵ��ھ޴��˯����������һ
��СС�Ĵ����ҡ�
LONG
        );
        set("exits", ([ /* sizeof() == 5 */
  "eastup" : __DIR__"bedroom",
  "east" : __DIR__"center",
  "west" : __DIR__"west_garden",
  "south" : __DIR__"storage",
  "north" : __DIR__"north_garden",
]));
        set("objects", ([
                __DIR__"npc/guard" : 2,
        ]) );

        create_door("south", "door","ľ��", "north", DOOR_CLOSED);

	set("coor/x",-20);
	set("coor/y",40);
	set("coor/z",20);
	setup();
}

