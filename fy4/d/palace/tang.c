inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "����");
        set("long", @LONG
������һ����Ⱦ�������������ıڶ�������ܣ��ݽ�һ���ټ�������һ�����ҡ�
���м���δ��ɵĻ���ɢ�ҵض�����һ�ǵ�[33m����[32m�ϡ����Ϲ�����������͵��������
���Կ�����һ��ʢ���ľջ���
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"juhua",
]));
        set("objects", ([
        __DIR__"obj/desk" : 1,
	__DIR__"npc/laofuren" : 1,
	__DIR__"npc/maid" : 1,
                        ]) );

	set("coor/x",60);
	set("coor/y",20);
	set("coor/z",0);
	setup();
}
void reset()
{
	object *inv;
	object con, item;
	::reset();
	con = present("desk", this_object());
        inv = all_inventory(con);
        if( !sizeof(inv)) {
		item = new(BOOKS"skill/zuixian-step_50");
		item->move(con);
	}
}
