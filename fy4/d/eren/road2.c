inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "ɽ��");
        set("long", @LONG
ɽ·������᫣���ʯ���м���Ұ����ǿ�����ͷ����Ⱥɽ����Զ���������ڽ�
��������¼ŵ�ɽ���ȴ���˵ĵ��ϣ���¶���˼����İ�Ϣ��������ĺɫ��
���Ե������У�ͻȻ�ֳ�һϯ�ƻ�
LONG
        );
        set("exits", ([ 
	"northdown" : __DIR__"road1",
	"northup" : __DIR__"valleyentry",
	]));
        set("objects", ([
        	__DIR__"obj/grass": 1,
	]) );
	set("outdoors", "eren");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",40);
	set("map","eren");
	setup();
	replace_program(ROOM);
}

void reset()
{
        object *inv;
        object con, item;
        ::reset();
        con = present("grass", this_object());
        inv = all_inventory(con);
        if(!sizeof(inv)) {
        	item = new(__DIR__"obj/duancao");
        item->move(con);
        }
}
