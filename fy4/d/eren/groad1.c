inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "��������");
        set("long", @LONG
���⾰ɫ�ȼѣ�ʯ���ϵ�̦�ۣ�ԫǽ���Ұ�ݣ��ɵĹ�÷�����ĵ��񾶣�·
����һ������ĳ�������������������еİ����ѳ������ɴ��ɳ����������
����һ���������Щ������������ʳ����Ƥ�쵽ˮ���в���������������
��ͨͨ�����졣
LONG
        );
        set("exits", ([ 
	"southwest" : __DIR__"valley1",
	"northeast" : __DIR__"groad2a",
	]));
        set("objects", ([
        	__DIR__"obj/pond": 1,
	]) );
	set("outdoors", "eren");
        set("coor/x",20);
        set("coor/y",70);
        set("coor/z",0);
	set("map","eren");
	setup();
}

void reset()
{
        object *inv;
        object con, item;
        ::reset();
        con = present("pond", this_object());
        inv = all_inventory(con);
        if(!sizeof(inv)) {
        	item = new(__DIR__"obj/fish");
        	item->move(con);
        	item = new(__DIR__"obj/fish");
        	item->move(con);
        }
}