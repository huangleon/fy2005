
inherit ROOM;
#include <room.h>

void create()
{
        set("short", "����ԡ��");
        set("long", @LONG
һ���ţ��������棬�װ׵�ˮ�����̰�Χ���㡣����ϡ����һ���޴��̴ľˮ��,
ˮ�ʱ��̣�ɢ����һ�����ص�ҩ�㣬ˮ���ϻ�Ư��һƬƬ���Ļ������������һ��
�����������𣩽�ȥ�������۾��úõķ���һ�¡�
LONG
        );
        set("exits", ([
                "east" : __DIR__"jlonglang3",
        ]));
        set("objects", ([
                __DIR__"npc/": 2,
        ]) );
        set("coor/x",-40);
        set("coor/y",40);
        set("coor/z",-300);
        setup();
        create_door("east", "̴ľ��", "west", DOOR_CLOSED);

}


