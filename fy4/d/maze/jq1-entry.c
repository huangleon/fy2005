// sinny/silencer@fy4 workgroup 

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "�������");
    set("long", @LONG
�Զ�Թ�õ��ܵ����£����������խ��ֻ�ݵ��˲�����У��������������� 
����Ȼ���ʣ�����Ӥ�������ţ�ͻ����յ�ͨ��������磬��������������ǹһ 
���ֱվ�ڽ���ͭ�����࣬һ������������ܡ���������Ϲٽ��ľ��ʽ���� 
������������Ϊ���ã�ʵΪѵ����Ǯ��ʿ�Ӵ�����ܽ��ء�
LONG
    );

    set("exits", ([ 
	"eastup" :   	AREA_FY"tang2",
	"down" : 	__DIR__"jq2-entry",
	"east": 	__DIR__"jq1-maze/entry",
      ]));
    set("objects", ([
	__DIR__"npc/jq1-guard4": 2,
      ]) );

	set("NONPC",1);
    set("coor/x",-210);
    set("coor/y",100);
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

    maze_room=find_object(__DIR__"jq1-maze");
    if (!maze_room) return 1;
    flush_msg=HIW"��������Ȼ�ι�һ���磬һ���ƺ��ָֻ��ղŵ�ģ����\n"NOR,
    maze_room->remove_all_players(maze_room,this_object(),flush_msg);
    maze_room->refresh_maze();
    return 1;
}

/*
int valid_leave(object who, string dir) {
    object guard;
    if (dir == "down") {
	if (guard = present("jinqian tiewei",this_object())) 
	    return notify_fail("����������ǹһ�ᣬ��ס�����ȥ·��\n");
    }
    return ::valid_leave(who,dir);
}
*/