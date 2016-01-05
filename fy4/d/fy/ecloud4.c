#include <ansi.h>
#include <room.h>

inherit DOOR_ROOM;

void create()
{
    set("short", HIG"������"NOR);
    set("long", @LONG
��·�����Һ��ģ�Զ���Ʒ��ƹ㳡�ķ�����ż���м���С���Ľ�����������
������һ��˵�����Ĺ�ζ��Ψ��Զ�����Կ���������������ɽ�ͣ�ɽɫ�ƺ�ҲŨ
����īһ����ʱ��ʱҲ�ᴵ���������£����������˲�ʱ�ᱻԶ������ϼ��������
�������㡣�쳾������˭˵��û�л�����ˡ�
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"east" : __DIR__"ecloud5",
	"west" : __DIR__"ecloud31",
	"north" : __DIR__"yulong3",
	"south" : __DIR__"backdoor",
      ]));
    set("objects", ([
	__DIR__"npc/drugseller" : 1,
      ]) );

    set("outdoors", "fengyun");
    set("coor/x",240);
    set("coor/y",0);
    set("coor/z",0);
    set("map","fyeast");
    setup();
    create_door("south", "door","����", "north", DOOR_CLOSED);
}


int valid_leave(object me, string arg) {
    if (arg == "south") {
	return notify_fail("��������ߺ���ţ����¶������š������㱻���˳�����\n");
    }
    return ::valid_leave(me, arg);
}
