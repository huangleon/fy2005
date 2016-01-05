inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "����ɽ");
        set("long", @LONG
����ɽ�ķ羰�����˵ģ����Ϲ۾�̨���������½���������Ϫ�����ߵ�Ȫ����
ï�ܵ����֣���ʱƮ���ļ�Ƭ���ơ�ÿ�����£���С�ž�ʢ�����졢�����ϡ��׽�
���ӳ��������ȥ�ĸ�ԭ�ʵ����еû�������Ѥ����ʡ�
LONG
        );
        set("exits", ([ 
		"south": __DIR__"wild1",
		"northdown": __DIR__"mroad1",
	]));
	set("item_desc", ([
		"flower": "ɽ�ϵĶž黨���������ã����̲�ס��ȥժ�ϣ�pick�����䡣\n",
		"�ž�":  "ɽ�ϵĶž黨���������ã����̲�ס��ȥժ�ϣ�pick�����䡣\n",
	
	]));
        set("objects", ([
        	__DIR__"npc/butterfly": 	1,
        	__DIR__"npc/butterfly2": 	1,
        	__DIR__"obj/scenery":		1,
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1300);
        set("coor/y",750);
        set("coor/z",0);
	set("map","zbeast");
	set("flower",2);
	setup();

}


void init() {
	add_action("do_pick","pick");
}


int do_pick(string arg) {
	
	object butterfly,flower;
	
	if ( arg!= "�ž�" && arg!="flower" && arg!="��" && arg!="azalea" )
		return notify_fail("����ժʲô��\n");
	if (!query("flower"))
		return notify_fail("�����Ѿ���ժ���ˡ�\n");
	if (butterfly=present("butterfly",this_object()))
		return notify_fail(butterfly->name()+"չ����裬�ƺ���Ը������ѻ���ժȥ��\n");
	flower=new(__DIR__"obj/flower1");
	flower->move(this_object());
	message_vision("$N����ժ����һ�仨����\n",this_player());
	add("flower",-1);
	return 1;
}

	
void reset(){
	::reset();
	set("flower",2);
}