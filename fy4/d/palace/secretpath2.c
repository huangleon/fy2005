inherit DOOR_ROOM;
#include <room.h>
void create()
{
        set("short", "�ص���");
        set("long", @LONG
��������ת�˼���������ƺ������΢����Щ�����Ե�ͭ��������ɫ�Ĺ⣬
����ӰͶӡ��ʯ���ϡ�ӭ��һ��΢�紵���������ƺ����������㣬�����Ŀ����ơ�
��ǰ����������ͷ��һ��ͭ�Ű뿪��
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"garden",
  "west" : __DIR__"secretpath1",
]));
	set("outdoors","palace");

	set("coor/x",0);
	set("coor/y",50);
	set("coor/z",0);
	setup();
    create_door("east", "door","ͭ��", "west", DOOR_CLOSED);
}

