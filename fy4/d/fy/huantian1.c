#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", YEL"�����"NOR);
    set("long", @LONG
����ֻ��Ͻ��Ƕ�����һ���峺���������ĳǺӾ��������ʣ�����һƬ���£�
ż������������Ҳ��ɫ���ţ��첽���У�����������������С�Ľ���������һ����
���⣬��ר����裬��Ѫ��ɱ�Ĺ��г���ײ��������ûʲô���³���
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"southeast" : __DIR__"nwind3",
	"north" : __DIR__"huantian2",

      ]));
    set("outdoors", "fengyun");
    set("objects", ([
	//        __DIR__"npc/mei": 1,
      ]) );

    set("coor/x",-50);
    set("coor/y",200);
    set("coor/z",0);
    set("map","fynorth");
    setup();
    //	replace_program(ROOM);
}

