inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "ɽ��С·");
        set("long", @LONG
һ�����������С·ͨ��ɽ�����Ѱ����ɽ��Ѱ����·����Ѱ������·����
���������ʻ���õ�塢�ҽ�������ӡ���ͷ�̡�ˮ���Լ�������ʽ�����Ļ�����
����ŭ�����ޣ�����������ɽ�أ��׵������飬�����ɺ���������������̵Ȳ���
����ɫ�����ŷҷ��Ļ��㡢���������ˬ�ĺͷ硢���ȵ��������������׺��
һ���˼���԰��
LONG
        );
        set("exits", ([ 
		"southwest" :   __DIR__"mroad2",
		"north" : 	__DIR__"garden1",
	]));
        set("objects", ([
        
        	__DIR__"npc/butterfly3":	1,
	]) );
	set("item_desc", ([
        	"flower": "ɽ�ϵĻ������������ã����̲�ס��ȥժ�ϣ�pick�����䡣\n",
		"����":  "ɽ�ϵĻ������������ã����̲�ס��ȥժ�ϣ�pick�����䡣\n",
	]));
	set("outdoors", "zangbei");
        set("coor/x",-1300);
        set("coor/y",900);
        set("coor/z",-50);
	set("map","zbeast");
        set("flower",2);
	setup();
}


void init() {
	add_action("do_pick","pick");
}


int do_pick(string arg) {
	
	object butterfly,flower;
	
	if ( arg!="flower" && arg!="��" )
		return notify_fail("����ժʲô��\n");
	if (!query("flower"))
		return notify_fail("�����Ѿ���ժ���ˡ�\n");
	if (butterfly=present("butterfly",this_object()))
		return notify_fail(butterfly->name()+"չ����裬�ƺ���Ը������ѻ���ժȥ��\n");
	flower=new(__DIR__"obj/flower2");
	flower->move(this_player());
	message_vision("$N����ժ����һ�仨����\n",this_player());
	add("flower",-1);
	return 1;
}

	
void reset(){
	::reset();
	set("flower",2);
}