
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
�����ܻ���ɽ��ܴ����������棬�����Ƿ��еĲ��򡣷�������ȥ�����涼
�ǰ��ƣ�ƮƮ���죬����������������ض������ڸ����С�Ҫ��ƽƽ���ȵ�������
�棬ʵ�ںܲ����ס�
LONG
	);
	set("exits", ([
                "west" : __DIR__"forest9",
                "east" : __DIR__"ghost",
	]));
	set("objects", ([
                __DIR__"npc/ghost1" : 1,
	]));
        set("NONPC",1);
	set("coor/x",-80);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}

int valid_leave(object me, string dir)
{
        object ob;

        if( dir != "east"  || !objectp(ob=present("ghost", this_object()))) return 1;

		if(!me->query_temp("marks/��Լ"))
        	return notify_fail(HIY "����ʹ�ߺȵ���û�к�Լ�������Խ�����ɽׯ���������ܽ���һ�У�(accept test)\n"NOR);
		else {
			me->set_temp("marks/��Լ", 0);
			return 1;
		}
}
