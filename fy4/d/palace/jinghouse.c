#include <room.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
С������ľ��ᣬ�����ڴ���֮�䡣ѩ�׵�ǽ�ڳ��������̣�����һ��������
�о�������Ѿ�������ڷ������塣���еĲ�����Ȼ�򵥣�ȴ�쳣�ľ��¡�΢��͸��
ɴ�����촵���������������㡣
LONG
        );
        set("exits", ([ 
  			"east" : __DIR__"bookhouse",
 			 "west" : __DIR__"bamboo",
		]));
        set("objects", ([
        __DIR__"npc/playinggirl1" : 2,
        __DIR__"npc/playinggirl2" : 2,
        __DIR__"npc/playinggirl3" : 2,
        __DIR__"npc/playinggirl4" : 2,
        __DIR__"npc/playinggirl5" : 4,
                        ]) );

	set("coor/x",50);
	set("coor/y",40);
	set("coor/z",0);
	setup();
        replace_program(ROOM);

}

