#include <room.h>
inherit DOOR_ROOM;

void create()
{
        set("short", "��԰");
        set("long", @LONG
����һ������Ļ�԰������ȺɽΧ�ƣ�԰���򻨾��ޡ�ĵ����ҩ���ƾպ�õ��
�ļ��㻨������ؾ�ͬʱ���ţ�̧����ȥ����������һƬ���λ���֮�С���ʯС����
������ʼ䣬���ҵ�վ��ʮ���������Ů�����ڼ��ݹ໨������һ��ͭ�š�
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"garden3",
  "north" : __DIR__"garden1",
  "south" : __DIR__"garden2",
  "west" : __DIR__"secretpath2",
]));
        set("objects", ([
        __DIR__"npc/dagu" : 1,
                        ]) );

	set("outdoors","palace");
    
	set("coor/x",10);
	set("coor/y",50);
	set("coor/z",0);
	setup();
    create_door("west", "door","ͭ��", "east", DOOR_CLOSED);
}

