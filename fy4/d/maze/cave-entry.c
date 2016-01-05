// silencer@fy4 workgroup 
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
���ԭ��ֻ�Ǹ�����ͨ��ɽ�������ڵش�ƫƧ�������˼�������۵ĵ����Ǿ�
���������������������������һ����������������֪Ϊ��ʲô��������Ҳ�����ˣ�
����ȴʱ������һЩ��ֵ��춯����������ĵ����˴��Ż�ѽ����鿴���������
����Ψһ��һ����ȴ�Ѿ��ŷ��ˣ��Ӵ�������ͱ���������ߡ��� 
LONG
	);

	set("outdoors", "shaolin");

	set("exits", ([ 
		"out" : AREA_DAOGUAN"ping_tai",
		"south" : __DIR__"cave-maze/entry",
	]));
	set("NONPC",1);
	set("coor/x",0);
	set("coor/y",-80);
	set("coor/z",-10);
	setup();

}

//	�����ʾ refresh maze

void	init(){
	add_action("flush_maze","flush");
}


int	flush_maze(){
	object maze_room;
	string flush_msg;
	
	if (!wizardp(this_player()))
		return 0;
		
	maze_room=find_object(__DIR__"cave-maze");
	if (!maze_room) return 1;
	flush_msg=HIB"��Ȼ��һ�����紵������Χ�Ķ��ں�Ȼ�ƶ�������������
һ����ҡ��ת���㷢���Լ��ֻص��˹�ߵĽ��ڡ�\n"NOR,
	maze_room->remove_all_players(maze_room,this_object(),flush_msg);
	maze_room->refresh_maze();
	return 1;
}

/*
̫��������������������ȹ�â�����ڵ��档
    ���û��һƬ�ƣ�������Ҳû��һ������
    ��һ�ԴԿݻ��Ҷ�̵�Ұ�������洦�ɼ���ȴ�������
��ζ��
    �˴�����һ����ʮ����ǻ�������Сɽ�𼰻��ξ�ʯ
�������ܣ����޼�ϡ�
*/