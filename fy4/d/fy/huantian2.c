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
	"northeast" : __DIR__"nwind5",
	"south" : __DIR__"huantian1",
      ]));
    set("outdoors", "fengyun");
    set("objects", ([
	//        __DIR__"npc/mei": 1,
      ]) );

    set("coor/x",-50);
    set("coor/y",240);
    set("coor/z",0);
    set("map","fynorth");
    setup();
    //	replace_program(ROOM);
}


/*
void init() {
	  add_action("do_dazuo","dazuo");
	}

int do_dazuo(string arg) {
	object me;
	me=this_player();
	tell_object(me,"�˵ز��ܴ�����\n");
	return 1;
}*/

