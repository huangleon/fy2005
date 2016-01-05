// sinny/silencer@fy4 workgroup 

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����ɢ�����㷢���Լ���������һ�����ڡ���Ǯ�︻�����£�Ȩ���������
�治�Ƿ��Ƴ����Ǽ������ӿ������ɵ��µģ���ʵ�ϣ��Ǽ����լֻ���Ϲٽ��
���Ļ��ǣ����˶�Ŀ�Ļ��ӣ�������ǽ�Ǯ��Ĳر�֮�ء��Ӹ��������ÿһ
���������˽�Ǯ���Ӷ�����ĲƱ������ȻҲ�������Ľ�Ǯ��ʿ�����š�
LONG
	);

	set("exits", ([ 
		"east" : 	__DIR__"jq3-maze/entry",
		"exit" : AREA_FY"tang3",
	]));
	set("NONPC",1);
	set("coor/x",-20);
	set("coor/y",-9);
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
		
	maze_room=find_object(__DIR__"jq3-maze");
	if (!maze_room) return 1;
	flush_msg=HIR"��Ӱҡ�죬��������ز�������֨һ������һ��ľ���������\n"NOR,
	maze_room->remove_all_players(maze_room,this_object(),flush_msg);
	maze_room->refresh_maze();
	return 1;
}

