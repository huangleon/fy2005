#include <room.h>
inherit DOOR_ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
С���а˽ǣ������ͤ��ֻ�������Ŵ����ա��񻨴����䣬���е���ɫ���
ɴ���˽Ƿ����£����лƽ�����壬���������������Ȫ���������ݡ����ɡ���
�١����ܼ䣬���������������磬�ƽ�Ϊ��������Ϊ�׵�СС¥����֮��������
�����˼䡣
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"sriver",
  "south" : __DIR__"dating",
]));
        set("objects", ([
        __DIR__"npc/feiyu" : 1,
        __DIR__"npc/s_wushi" : 2,
                        ]) );

	set("outdoors","palace");
	set("coor/x",0);
	set("coor/y",20);
	set("coor/z",0);
	setup();
    create_door("south", "door","�ƽ���", "north", DOOR_CLOSED);
}

