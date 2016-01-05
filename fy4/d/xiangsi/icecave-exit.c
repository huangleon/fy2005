// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", WHT"����С��"NOR);
	set("long", @LONG
С��������н������߳߸��µı����ϣ���Ҫ��ʱ����ĵ��������µı��⣬
���Ǳ����ϰ�͹��ƽ�ı��ӱ���������ʱ���ű����ı����ѿɿ������ڣ�ǰ��ȴ
����ټ��ı�ʯ��סȥ·����Խ��ǰ�У�����ľ���������Խ���������е�������
���������������𲻶���΢����â֮�ϡ�
LONG
	);
	set("no_clean_up", 0);
	set("no_fly",1);

	set("valid_startroom",1);

	set("exits",([
		"north" : __DIR__"icecave-maze/exit",
		"south":  __DIR__"icecave2-maze/entry",
	]));
	set("objects",([				
			__DIR__"mazenpc/trader":		1,	// ghost trader
		]));
	set("NONPC", 1);
	set("coor/x",-20);
	set("coor/y",-110);
	set("coor/z",30);
	setup();

}

void init()
{
	object room;
	if (!(room = find_object(__DIR__"icecave")))
		room = load_object(__DIR__"icecave");
	room->generate_maze();
	room->generate_maze2();
}


/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/
