// TIE@FY3 ALL RIGHTS RESERVED
inherit DOOR_ROOM;
#include <room.h>

void create()
{
        set("short", "���в�");
        set("long", @LONG
���Ǻ�����ӵĳ��������Ӻܳ������ŷ������ų�ľ���������Ǳ�������ϯ��
һ�����������ڽ�ּ��Ҫ�������ж��֣��������ڵ����޲�ʱ���������С����϶�
��ϰ���գ����Լ����϶���Ҳ����˰��ޡ�
LONG
        );
        set("exits", ([ 
 "south" : __DIR__"heshang2",  
]));
        set("objects", ([
                __DIR__"obj/buobei" : 1,
		__DIR__"obj/zhuxi" : 1,
			__DIR__"npc/monk20b2" : 1,
       	__DIR__"npc/monk20c2" : 1,
       ]) );
		set("coor/x",10);
		set("coor/y",60);
		set("coor/z",10);
		setup();
		create_door("south", "door","ľ��", "north", DOOR_CLOSED);
}
