#include <ansi.h>
inherit ROOM;
inherit F_LEVEL;
void create()
{
        set("short", "Сɽ���");
        set("long", @LONG
СС��ɽ���������
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
  	"south" : __DIR__"treasure",
	]) );

	set("objects", ([

	]) );

	set("no_fly", 1);

	set("max_lv",15);	// ��ֹ15�����Ͻ�ɫ����

	set("coor/x",-20);
	set("coor/y",40);
	set("coor/z",0);
	setup();
}

int init()
{
	object me = this_player();
	object exitroom = find_object(__DIR__"fenghuo");
	if (!exitroom)
		exitroom = load_object(__DIR__"fenghuo");
	if (userp(me))
	if (exp_to_level(me->query("combat_exp"))["level"] >= query("max_lv"))
	{
		me->add_temp("block_msg/all",1);
		me->move(exitroom);
		me->add_temp("block_msg/all",-1);
		tell_object(me,MAG"���߽�ɽ�������ҿ�����ʲôҲû���֣���ͷɥ�������˳�����\n"NOR);
	}
}
