#include <ansi.h>
inherit ROOM;
inherit F_LEVEL;

void create()
{
        set("short", "Сɽ����");
        set("long", @LONG
ԭ���һ�Դ������������ôһ��СС��ɽ���������ش��������ܣ�����ɽ��
���߳�����ˮ�飬�ƺ��������һ�������ķ�������ͼ����ɽ�������ȥ��ֻ
�ɼ�һ��ͻأ����ʯ����·�ϣ���ס����ǰ���ĽŲ���
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
  	"south" : __DIR__"fenghuo",
  	"north" : __DIR__"treasureroom",
	]) );

	set("objects", ([
//		"/obj/treasure/npc/rock" : 1,
	]) );


	set("item_desc", ([
		"north" : "��ʯͷ��������·�ϡ�\n",
	]) );

	set("no_fly", 1);

	set("max_lv",15);	// ��ֹ15�����Ͻ�ɫ����
	set("min_lv",5);	// ��ֹ5�����½�ɫ����
	set("coor/x",-20);
	set("coor/y",20);
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
	if (exp_to_level(me->query("combat_exp"))["level"] >= query("max_lv") 
		|| exp_to_level(me->query("combat_exp"))["level"] <= query("min_lv"))
	{
		me->add_temp("block_msg/all",1);
		me->move(exitroom);
		me->add_temp("block_msg/all",-1);
		tell_object(me,MAG"���߽�ɽ�������ҿ�����ʲôҲû���֣���ͷɥ�������˳�����\n"NOR);
	}
}


int	valid_leave(object who, string dir)
{
	if (dir == "north" && present("giant rock",this_object()))
		return notify_fail("��ʯ��ƫ���еغ��ڶ���֮�䣬��ס����ĽŲ���\n");
	return ::valid_leave(who,dir);
}
