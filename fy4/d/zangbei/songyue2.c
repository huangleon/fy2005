inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "����");
        set("long", @LONG
�����ߣ��������Ͼ�����ɲ����ɲ�Ϻ�����������̦������һ��С�ľ����׻�
��ȥ��վ�����棬��Χ�龰�����۵ף��������������ڵ����֣�Զ������ͭϿ�ͺ�
�ٺӵĹ�����ˮ����ϸ��ȥ�������ǻ��м����������̵İ�����������
LONG
        );
        set("exits", ([ 
		"down" : __DIR__"songyue",
	]));
        set("objects", ([
        	
	]) );
	set("item_desc", ([
		"����": "��ϸ���ϣ����ƺ�����ţ���ȼ��Ĵ��̣�������ô�������˼��أ�\n",
		]));
	set("outdoors", "zangbei");
        set("coor/x",-550);
        set("coor/y",650);
        set("coor/z",10);
	set("map","zbeast");
	setup();

}

void init(){
	int i;
	object me;
	me = this_player();
	if (query("bird_out") && !me->query_temp("parrot/�ټ�Ѫū")) call_out("do_bird", 1, me);
}

int do_bird(object ob) {

	if(interactive(ob) && environment(ob) != this_object()){
		return 1;
	}	
	message_vision(HIR"��Ȼ�䣬һ����������ɲ�Ϸ�������������һֻ��һֻ�����Ϲ����������
����������أ��ͷ·�Ҫ���˵Ļ��ǡ�ת˲�䣬���Զ�ˣ�����ҲԶ�ˡ�\n"NOR,ob);
	ob->set_temp("parrot/�ټ�Ѫū",1);
	set("bird_out",0);
}


void reset()
{
	object item, coffin;
	object *inv, *players;
	
	::reset();
	set("bird_out",1);
	return;
} 
