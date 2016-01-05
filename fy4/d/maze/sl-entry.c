// sinny/silencer@fy4 workgroup 

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "ҹ���");
	set("long", @LONG
��������һ������޺��õ����á�ҹ���ߣ�ά���������ߣ�����ʳ����άĦ 
����ע��ҹ�����ࣺ�ڵأ��ڿ��飬��ҹ��Ҳ�������ıڿ���ҹ��˴󽫣������ 
�棬����������������ҹ�����վ��ͨ�����ߣ�ŭĿ���򣬸ֲ�ָ�죬������¾� 
�ţ��ƺ�һ˿�綼û�С�
LONG
	);

	set("exits", ([ 
		"out" : 	AREA_SONGSHAN"houmen",
		"east" : 	__DIR__"sl-maze/entry",
	]));
	set("NONPC",1);
	set("coor/x",70);
	set("coor/y",30);
	set("coor/z",10);
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
		
	maze_room=find_object(__DIR__"sl-maze");
	if (!maze_room) return 1;
	flush_msg=HIB"ͻȻ�ĵ��һ���¡¡��������������ƽϢ��������\n"NOR,
	maze_room->remove_all_players(maze_room,this_object(),flush_msg);
	maze_room->refresh_maze();
	return 1;
}

