// TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit DOOR_ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
һ��޴�����ӣ��������ų�����������Ÿ����߲ˣ�ʳƷ��ÿ�쳿��ĺ��֮
��ɮ�˱�������ۼ�������ʳ�һ�㰴�ȼ��ߵ����ν�ʳ���������Ȳ�ͬ����
���ȼ���֮�ϡ���������ͷ��
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"neiyuan",
  "west" : __DIR__"qianzao",
]));
        set("objects", ([
                __DIR__"npc/monk9" : 1,
       ]) );
	set("coor/x",-10);
	set("coor/y",40);
	set("coor/z",10);
	setup();
	create_door("west", "door","ľ��", "east", DOOR_CLOSED);

}
