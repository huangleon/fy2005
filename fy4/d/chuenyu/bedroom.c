#include <room.h>
inherit DOOR_ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���Ǵ��ڱ�����ӵĵط��������¥������ͨ����ɸ����������¥������
ͨ����ɸ�������������һ��СС����̨���������Ǳ������ŷ���
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
	  "north" : __DIR__"yiantai",
	  "south" : __DIR__"kitchen",
	  "westdown" : __DIR__"west_blackge",
	  "eastdown" : __DIR__"east_blackge",
	]));
        create_door("south", "door","������", "north", DOOR_CLOSED);


	set("coor/x",-10);
	set("coor/y",40);
	set("coor/z",30);
	setup();
}

