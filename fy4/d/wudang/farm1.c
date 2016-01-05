#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "ׯ�ڵ�");
	set("long", @LONG
һ�������͵�������а��˸ߵ���˶������������罭���е��㣬������
��֮����ӿ�Ĳ��Σ��Ĵ�Ʈҡ�����뵽�����е�����,������Ȼ���¡� 
LONG
	);
	set("exits", ([
		"north" : __DIR__"farm3",
		"south" : __DIR__"farm5",
		"east" : __DIR__"road1",
		"west" : __DIR__"farm3",
	]));
	set("objects", ([
		__DIR__"npc/farmer" : 1,
		__DIR__"npc/bull"   : 1,
	]));
	set("outdoors", "wudang");
	set("coor/x",-10);
	set("coor/y",60);
	set("coor/z",-50);
	setup();

}


void init(){
	add_action("do_search","search");
}


int do_search(){
	object ob, me = this_player();
	
	if (me->is_busy() || me->is_fighting())
		return notify_fail("��������æ��\n");
		
	message_vision("$N��˼Ƭ�̣������������˼������أ���ʱ�������Ӳ쿴��\n", me);
	me->perform_busy(1);
	
	if (random(5) || present("scorpion", this_object()))
		return notify_fail("����������������￴�˿���û����ʲô�쳣��\n");
		
	ob = new(__DIR__"npc/scorpion");
	message_vision(HIR"����������Ȼ�����������һֻ���糤�Ĵ�Ы�ӣ�������צ����$N��ȥ��\n"NOR, me);
	if (!ob ->move(this_object()))	destruct(ob);
	else
		ob->kill_ob(me);
	return 1;
}
	
		
		