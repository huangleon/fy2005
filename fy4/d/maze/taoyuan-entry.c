// sinny/silencer@fy4 workgroup 

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�Ȿ��һƬï�ܷ�ʢ���һ��֣�ԭ��������������Ӣ�ͷף���ʱ��������һ�� 
�����ı�����Ҳ������ͣ�Ȼ����������������������һ������һ��Σ�����
ǰ·�ѱ棬�������Ǿô����У�������л������������ϰ�������������������� 
һ��ʯ�����ʺ���Ѫ��׭�ָ��������οͣ�[0;1;31m�һ������޻��ˣ����룡[0m
LONG
	);

	set("outdoors", "taoyuan");

	set("exits", ([ 
		"north" : AREA_TAOYUAN"taolin2",
		"south" : __DIR__"taoyuan-maze/entry",
	]));
	set("NONPC", 1);
	set("coor/x",-60);
	set("coor/y",0);
	set("coor/z",-10);
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
		
	maze_room=find_object(__DIR__"taoyuan-maze");
	if (!maze_room) return 1;
	flush_msg=MAG"\n��Ȼ��һ��紵������Χ���һ�֦��Ȼ�ƶ�������������
һ����ҡ��ת���㷢���Լ��ֻص����һ��ֵĽ��ڡ�\n\n"NOR,
	maze_room->remove_all_players(maze_room,this_object(),flush_msg);
	maze_room->refresh_maze();
	return 1;
}

int	valid_leave(object who, string dir) {
	if (dir == "south")
	{
		if (!who->query_temp("maze/�һ�������ɢ"))
		{
			message("vision",who->name()+"���������һ�������ٲ���������ȥ��\n",this_object(),who);
			message("vision",MAG"һ�ɵ�����������һ�����Ʈɢ����������������\n"NOR,this_object(),who);
			tell_object(who,MAG"������̤���һ��֣�ͻ���ڱ�֮����ζ��ɢ������һ���ʹ����Ѫ���ڣ�
����ͨ��һ����ˤ���ڵء�\n"NOR);
			who->unconcious();
			return notify_fail ("");
		}
	}		
	return 1;
}