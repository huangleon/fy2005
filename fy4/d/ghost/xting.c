#include <ansi.h>
inherit ROOM;
inherit F_LEVEL;

void create()
{
	set("short", "С��");
	set("long", @LONG
����С��������������ɽׯ�Ĳ񷿣������жѻ�����ľ��ͳ���������ȥ˿��
û�б���֮���������ݵ�ľ���м侹Ȼվ�˸�������ˣ����˾�����һ��������
�����ס��Ͳ񷿸����ĵ������������������ź����·������˻���������
������ÿһ�������һ�ѳ������ͦ������

LONG
	);
	set("exits", ([
                "north" : __DIR__"groad2",
	]));
	set("coor/x",-50);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
	set("no_fly", 1);
	set("max_lv",30);	
}


int init()
{
	object me = this_player();
	object exitroom = find_object(__DIR__"groad2");
	if (!exitroom)
		exitroom = load_object(__DIR__"groad2");
	if (exp_to_level(me->query("combat_exp"))["level"] >= query("max_lv") && userp(me))
	{
		me->add_temp("block_msg/all",1);
		me->move(exitroom);
		me->add_temp("block_msg/all",-1);
		tell_object(me,MAG"СС����ֻ��һ������������ˣ���Ȼ��Ȥ��\n"NOR);
	}
}
