#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "����·");
        set("long", @LONG
̫ƽ�����һƬ�ܴ������ء�����ԭ����һ��С���������ɺ��ˣ��ͳ�����
���������쵽�ķ��кü���Զ������ȫ�ǳ�ʪ�Ĳݵغ�һƬ����������̿�ӣ���
�泤�������Ӻ����ҵİ���������в�����궼��һ�㱡������������
LONG
        );
        set("exits", ([ 
		"east": __DIR__"mroad9",
		"west": __DIR__"swamp2",
	]));
        set("outdoors", "taiping");
	set("item_desc", ([
		    
	]));
	set("toad",3);
	set("coor/x",-20);
	set("coor/y",-90);
	set("coor/z",0);
	set("map","taiping");
	setup();

}

void init()
{
	object me, here;

	me = this_player();
	here = this_object();

	if( random(query("toad"))> 0 && userp(me) && time() - query("last_comeout") > 180
		&& !present("toad",this_object())) {
		set("last_comeout", time() );
		remove_call_out("toad_out");
		call_out("toad_out", 6+random(3)); 
		tell_object(me, "����ý�����������ƺ��ȵ���ʲô���\n");
	}
}

void toad_out()
{
	object toad, here;
	here = this_object();

	add("toad", -1);
	toad = new("/obj/animal/toad");
	toad->move(here);
	message("vision", YEL"�ݴ����Ȼ������һֻ��󡡣\n"NOR, here);
	return;
}


