// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "��ľ��");
    set("long", @LONG
���ý����룬���Ѿ��߽��˽�������Ϊ���صĽ��أ�С��ɽ��û����֪���Ǵ�
ʲôʱ��ʼ������һ��ټ��ķ�߱�һȺ��ݲ����Ĺ�����ռ�ݣ�ֻ���ԴӰٶ�
��ǰ�ųƷ���ѧ�������µ�һ�����ֽ���Ժ����������ʦĪ��ɥ���ڴ˵���ǰ֮
���������˶���ԶԶ�ıܿ�С��ɽ���ܿ����ȷ��类����ʮ�صĶ�ħ������ĺ�
ľ�š�
LONG
    );
    set("exits",([
	"east" : "/d/xiangsi/jieyu",
	"west" : __DIR__"maze1/entry",
      ]) );

    set("objects", ([
	"/d/xiangsi/npc/gongsun2" : 1,
      ]));
    set("outdoors", "bashan");

    set("coor/x",5);
    set("coor/y",0);
    set("coor/z",0);
    setup();
}

void generate_maze()
{
    object icecave;
    object maze_room;
    string flush_msg;
    int boss_x,boss_y;

    if (query("maze1/maze"))
	return;
    set("maze1/maze",1);

    maze_room=find_object(__DIR__"maze1");
    if (!maze_room)
	maze_room=load_object(__DIR__"maze1");
    flush_msg=HIR BLK"\n������\n\n"NOR,
    maze_room->remove_all_players(maze_room,this_object(),flush_msg);
    maze_room->refresh_maze();

    icecave = this_object();
    boss_x = random(6);
    boss_y = random(6);
    icecave->set("maze1/boss_x",boss_x);
    icecave->set("maze1/boss_y",boss_y);

}
