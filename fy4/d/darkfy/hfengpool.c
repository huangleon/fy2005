
inherit ROOM;
#include <room.h>

void create()
{
        set("short", "��ҶȪ");
        set("long", @LONG
���Ƴ��еķ�ҶȪ�Ƿ�Բ�������������һ����Ȫ����������˵����ǰˮ�����У�
Ȫˮ�ʵ���,�ʶ�������Ҷ����������ȥ����������Ч����˵�����������ٵ���
�á���ǰ�����ֵ�һ�������ɶ�ÿ�춼�Դ�Ȫˮ��棬���������绨�������ò��
�����Ա߷���һ�������������д�ţ��������䣬������ʱ�رա�
LONG
        );
        set("exits", ([
                "west" : __DIR__"hfenglang3",
        ]));
        set("objects", ([
                __DIR__"npc/": 2,
        ]) );
        set("outdoors", "fengyun");
        set("coor/x",45);
        set("coor/y",45);
        set("coor/z",-300);
        setup();
        create_door("west", "̴ľ��", "east", DOOR_CLOSED);

}


