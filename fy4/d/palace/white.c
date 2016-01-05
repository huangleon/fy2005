
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "��ʯ��·");
        set("long", @LONG
����һ����ֱ�ģ��ɾ�Ө�İ�ʯ�̳ɵĵ�·��·���������޼�����Ļ��ݣ�΢
�紵��������Ϯ�ˡ���ɫ�ľ�ʯ��������������˵�ɫ�ʡ�һ���Ե���������������
���������ȴ��һ�ֲ����Ԥ�С�
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"intersection",
]));
        set("objects", ([
        __DIR__"obj/huacao" : 1,
	__DIR__"obj/stone" : 1,
                        ]) );

        set("outdoors", "palace");
	set("coor/x",-90);
	set("coor/y",110);
	set("coor/z",10);
	setup();
}
int valid_leave(object me, string dir)
{
	message_vision( HIC "һ�󵭵��Ļ���Ʈ����$N���ɵ�������һ������\n\n\n"NOR,me);
	if(!me->query_condition("no_shadow"))
		me->apply_condition("no_shadow",random(10)+10);

	return 1;
}
void reset()
{
	object *inv;
	object con, item;
	::reset();
	con = present("huacao", this_object());
        inv = all_inventory(con);
        if(!sizeof(inv)) {
	item = new(__DIR__"obj/xuehama");
	item->move(con);
	}
	con = present("stone", this_object());
        inv = all_inventory(con);
        if( !sizeof(inv)) {
	item = new(__DIR__"obj/duancao");
	item->move(con);
	item =  new(__DIR__"obj/pearl1");
	item->move(con);
	}
}
