// sinny/silencer@fy4 workgroup 

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
�����ǽ�Ǯ��ĵ������ڣ��Ϲ�����֮־�������е��켺���Ǳ�ɱ֮����죬
���ǰ��������ڴˡ����ս������ԣ��Ϲٵ�һ���ˣ������Ƹ��ָ�������ҩ����ɱ
�����Σ������˷�񣬻��������ǡ�����һʱ֮�䣬�������˽Ի̻̲������ա���
��˵����Ϊ��Ǯ����ĸ��־��ڵ����б���������֪�޾���ֻ��ɱ¾����ʬ���⡣ 
LONG
	);

	set("exits", ([ 
		"up" : 		__DIR__"jq1-entry",
		"east" : 	__DIR__"jq2-maze/entry",
	]));
	set("NONPC",1);
	set("coor/x",-40);
	set("coor/y",-15);
	set("coor/z",-20);
	setup();

}

//	�����ʾ refresh maze,������flush���˹�reset maze

void	init(){
	add_action("flush_maze","flush");
}


int	flush_maze(){
	object maze_room;
	string flush_msg;
	
	if (!wizardp(this_player()))
		return 0;
		
	maze_room=find_object(__DIR__"jq2-maze");
	if (!maze_room) return 1;
	flush_msg=HIB"һ�����紵�������˹��裬�·�һ�����Ρ�����\n"NOR,
	maze_room->remove_all_players(maze_room,this_object(),flush_msg);
	maze_room->refresh_maze();
	return 1;
}

