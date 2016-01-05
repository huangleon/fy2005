// Room: /d/chuenyu/gate_castle.c

#include <ansi.h>
#include <room.h>
inherit DOOR_ROOM;

void create()
{
	set("short", "���ɴ���");
	set("long", @LONG
��վ����һ����ΰ�ĳǱ�֮ǰ������֮�Ϲ���һ����ҡ����������ɷ����д
���ĸ����֡����ɴ��ڡ����������½Ǹվ�������
		�����ڻ�̫������������һ��ʮ���ա���
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		  "east" : __DIR__"east_castle",
		  "west" : __DIR__"west_castle",
		  "north" : __DIR__"trap_castle",
		  "down" : __DIR__"high_b_mtn2",
	]));
	set("outdoors", "chuenyu");

	create_door("north","door", "����", "south", DOOR_CLOSED);

	set("coor/x",0);
	set("coor/y",-10);
	set("coor/z",10);
	setup();
}