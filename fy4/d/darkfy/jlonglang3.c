
inherit ROOM;
#include <room.h>
void create()
{
        set("short", "����");
        set("long", @LONG
һ�˶�ߣ�ֻ�����˲��е�̴��ľ���ȣ����е����������һЩ�滨��ݡ�����
���������ȵ�һͷð������̴ľ�ذ�����ʪ�ֻ����㼸��Ҫ�������˲Ų��Ử����
LONG
        );
        set("exits", ([
                "east" : __DIR__"jlonglang2",
		"west" : __DIR__"jlongpool",
        ]));
        set("coor/x",-30);
        set("coor/y",40);
        set("coor/z",-300);
        setup();
        create_door("west", "̴ľ��", "east", DOOR_CLOSED);

}


