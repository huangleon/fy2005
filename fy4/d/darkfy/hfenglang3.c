
inherit ROOM;
#include <room.h>
void create()
{
        set("short", "����");
        set("long", @LONG
�����Ǹ��������С���Ǹ�����ԡ�ģ����������ʮɫ�Ĳʴ�����ζ�˱ǵĻ���,
������������ض��ǣ�͸������ˮ������Կ���������������޳��Ĵ��ȣ���ͦ��
���ţ����ںڵĳ���������������
LONG
        );
        set("exits", ([
                "west" : __DIR__"hfenglang2",
		"east" : __DIR__"hfengpool",
        ]));
        set("coor/x",31);
        set("coor/y",40);
        set("coor/z",-300);
        setup();
        create_door("east", "̴ľ��", "west", DOOR_CLOSED);

}


