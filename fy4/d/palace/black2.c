
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "��ʯ��·");
        set("long", @LONG
��ǰ������ǰ��Ȼ���ʡ�������յ��ɽ�ƽ��͡�һ����ʯ��·����ֱͨ����
�档ͨ·���ԣ�������һ��������ʯ��ֻ����Щʯ���е�����ᵶ���е��¼׾�
ȫ���㶼���ܵ�������������ü��Ȼ��
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"stonelin",
  "north" : __DIR__"black",
]));
        set("objects", ([
	__DIR__"obj/stonexiang" : 1,
	__DIR__"npc/ghost" : 3,
                        ]) );

        set("outdoors", "palace");
	set("coor/x",-90);
	set("coor/y",80);
	set("coor/z",10);
	set("coor/x",-90);
	set("coor/y",80);
	set("coor/z",10);
	set("coor/x",-90);
	set("coor/y",80);
	set("coor/z",10);
	set("coor/x",-90);
	set("coor/y",80);
	set("coor/z",10);
	setup();
}
void reset()
{
	object *inv;
	object con, item;
	::reset();
	con = present("shixiang", this_object());
	inv = all_inventory(con);
	if( !sizeof(inv)) {
	item = new(__DIR__"obj/guistaff");
	item->move(con); }
}
