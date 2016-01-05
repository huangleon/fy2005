// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "������");
        set("long", @LONG
��������ɽ�ϵı���һ�棬���겻������ֱ�䣬���еı���Ȯ�������
�������˺ϱ�����ϸ��Ҳֻ����Сָ�����ƹ����ڵı��⣬���Լ���������
�����һ��ϸխ��С�ڣ����Ƕ���֮��������һƬī�ڡ�
LONG
        );
	set("objects", ([
		__DIR__"npc/iceguardian" : 1,
	]));
	set("item_desc",	([
		"����": "���еı���Ȯ������ֵ������˺ϱ���ϸ��ֻ����Сָ����pick����\n",
		"icicle":"���еı���Ȯ������ֵ������˺ϱ���ϸ��ֻ����Сָ����pick����\n",
		"С��":	"�������һ��ϸխ��С�ڣ����Ƕ���֮��������һƬī�ڡ�\n",
	]));
	
	set("exits",([
		"up":	__DIR__"narcissus_place",
  		"out" : __DIR__"huxian",
  		"enter" : __DIR__"icecave-maze/entry",
	]) );

	set("indoors", "xiangsi");

	set("iceblade",3);

	set("NONPC", 1);
	set("coor/x",-20);
	set("coor/y",-10);
	set("coor/z",40);
	setup();
}

void generate_maze()
{
	object icecave;
	object maze_room;
	string flush_msg;
	int boss_x,boss_y;

	if (query("icecave/maze"))
		return;
	set("icecave/maze",1);

	maze_room=find_object(__DIR__"icecave-maze");
	if (!maze_room)
		maze_room=load_object(__DIR__"icecave-maze");
	flush_msg=HIR BLK"\n�����ﴫ�������ѵ����������ֲ����䣬����µı���ͻȻ��\n�飬�����Ա�����������ȥ������\n\n"NOR;
	maze_room->remove_all_players(maze_room,this_object(),flush_msg);
	maze_room->refresh_maze();

	icecave = this_object();
	boss_x = random(8);
	boss_y = random(10);
	icecave->set("icecave/boss_x",boss_x);
	icecave->set("icecave/boss_y",boss_y);

}

void generate_maze2()
{
	object icecave;
	object maze_room;
	string flush_msg;
	int boss_x,boss_y;

	if (query("icecave2/maze"))
		return;
	set("icecave2/maze",1);

	maze_room=find_object(__DIR__"icecave2-maze");
	if (!maze_room)
		maze_room=load_object(__DIR__"icecave-maze");
	flush_msg=HIR BLK"\n�����ﴫ�������ѵ����������ֲ����䣬����µı���ͻȻ��\n�飬�����Ա�����������ȥ������\n\n"NOR;
	maze_room->remove_all_players(maze_room,this_object(),flush_msg);
	maze_room->refresh_maze();

	icecave = this_object();
	boss_x = random(8);
	boss_y = random(10);
	icecave->set("icecave2/boss_x",boss_x);
	icecave->set("icecave2/boss_y",boss_y);

}

void init()
{
	add_action("do_pick", "pick");
	generate_maze();
}

int do_pick(string arg)
{
	object me = this_player(),iceblade;
	if (!arg)
		return notify_fail(WHT"��Ҫժʲô��\n"NOR);
	if (arg != "����" && arg != "ice" && arg != "iceblade" && arg!="icicle")
		return notify_fail(WHT"��Ҫժʲô��\n"NOR);
	if (!query("iceblade"))
		return notify_fail(WHT"�����Ϲ�ͺͺ�ģ����Ѷ�������û�ˡ�\n"NOR);
	if (me->query("class") != "moon" && present("ice guardian"))
		return notify_fail(WHT"��������ȥ��һ�ɺ������ֽ�����¾���˳�ż����»�������\n�����һ��������й�Ү�������������˰ɣ�\n"NOR);
	message_vision(HIW"\n$N�������ڱ����ϣ�����һ����һ�ر���Ӧ�ֶ��䡣\n\n"NOR,me);
	iceblade = new(__DIR__"obj/iceblade");
	iceblade->move(me);
	add("iceblade",-1);
	return 1;	
}

void reset()
{
	::reset();
	set("iceblade",3);
}

