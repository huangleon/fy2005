inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "�س�����");
        set("long", @LONG
���Ҳҵ�ҹɫ�����������ҲҵĴ�أ���������������ʮ�׼����ķ�ڣ����
����ʯ��ʯ����Ȼ�����Ǹ����ĸ��𡣵�������ʯ��ʯ���Ѿ�ȱͷ���ȣ���ͷ��
�����˻Ĳݣ������߽�����ֻ��ѻ���ɵ�һ���ɢ�������пÿ�����
LONG
        );
        set("outdoors", "biancheng");
        set("coor/x",-110);
		set("coor/y",10);
		set("coor/z",0);
		set("no_lu_letter",1);
	
		set("objects", ([
               	__DIR__"obj/tree":	1,
         ]) );		
		set("exits", ([
			"east" : __DIR__"cemetery10",
		]));
		set("bird_out",1);
		setup();
}

void init(){
	int i;
	object me;
	me = this_player();
	if (query("bird_out")) call_out("do_bird", 4, me);
}

int do_bird(object ob) {

	if(!ob || !userp(ob) || environment(ob) != this_object()){
		return 1;
	}	
	if (!REWARD_D->riddle_check(ob,"�Ѫ����") && !REWARD_D->check_m_success(ob,"�Ѫ����"))
	{
		tell_object(ob, HIR"
��Ȼ�䣬һ�������ӷضѼ��������������һֻ��һֻ�����Ϲ����������
����������أ��ͷ·�Ҫ���˵Ļ��ǡ�ת˲�䣬���Զ�ˣ�����ҲԶ�ˡ�\n"NOR);
		REWARD_D->riddle_set(ob,"�Ѫ����",1);
	}
	return 1;	
}


void reset()
{
	object item, coffin;
	object *inv, *players;
	
	::reset();
	set("bird_out",1);
	if (!objectp(coffin=present("tree",this_object()))) return;
	inv=all_inventory(this_object());
	players=filter_array(inv,(: userp($1) :));
	if (sizeof(players)) return;
	
	if (!present("ribbon",coffin)) {
		item=new(__DIR__"obj/ribbon");
		item->move(coffin);
	}
	return;
} 

