#include <ansi.h>
inherit ROOM;
inherit F_LEVEL;
void create()
{
        set("short", "����");
        set("long", @LONG
�����й�ľ���죬�������գ�����ɱ�����󣬿�����ӿ�������ʵ�Ѫ��ζ
����Ȼ�����������ı��н���֮����Ȼ��ʧ��ֻ�����Ϻ������˵����ż�����
�����µ�ʬ�壬һ������̴���Ѫ�����걳�����һ��Ⱦ��ĳ���վ��ʬ����
�䣬���ݼ��̡�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
		  "northwest" : __DIR__"sroad5",
	]));
        set("outdoors", "fengyun");
	set("coor/x",300);
	set("coor/y",-320);
	set("coor/z",0);
	setup();
	set("no_fly", 1);
	set("max_lv",60);	
}

int init()
{
	object me = this_player();
	object exitroom = find_object(__DIR__"sroad5");
	if (!exitroom)
		exitroom = load_object(__DIR__"sroad5");
	if (exp_to_level(me->query("combat_exp"))["level"] >= query("max_lv") && userp(me))
	{
		me->add_temp("block_msg/all",1);
		me->move(exitroom);
		me->add_temp("block_msg/all",-1);
		tell_object(me,MAG"������ɱ�����أ���Ľ������������㲻Ҫ�������ڡ�\n"NOR);
	}
}

