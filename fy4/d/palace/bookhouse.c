
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "�鷿");
        set("long", @LONG
�鷿С�ɾ��£���ɨ���˳���Ȼ����ǽ������ϰ����˸����鼮��һ�ź�ľ��
�����ڵ񻨴�ǰ���Ա߷��˸����������������������[33m����[32m�ϣ����ֱ���һյˮ��
�ƣ��Ա���һ���������ε���仨ƿ������ϡ��ز��˼�ֻ��ɫ��ɽ�軨��
LONG
        );
        set("exits", ([ 
  		"west" : __DIR__"jinghouse",
  		"south" : __DIR__"juhua",
	]));
        set("objects", ([
        	__DIR__"obj/desk" : 1,
        	__DIR__"npc/manfeng" : 1,
                      ]) );

	set("coor/x",60);
	set("coor/y",40);
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
	item = new(BOOKS"skill/iceheart_11");
	item->move(con);
	}
}
