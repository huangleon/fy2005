#include <ansi.h>
inherit ROOM;
inherit F_LEVEL;

void create()
{
	set("short", "�����ջ");

	set("long", @LONG
��ջ��һ¥��˯���������￴�����ɸɾ�����Ψһ�İ������һ�źܴ�
�ܴ�Ĵ�������ȥǰ���û��б�ʹ�ù��ĺۼ��������и���ͷ��������ˣ�
����ȥ�����ˡ�
LONG);

	set("type","house");
	set("exits",([
		"east":__DIR__"kezhan",
	]) );
	
	set("coor/x",-10);
	set("coor/y",110);
	set("coor/z",0);
	setup();
	set("no_fly", 1);
	set("max_lv",40);
}

int init()
{
	object me = this_player();
	object exitroom = find_object(__DIR__"kezhan");
	if (!exitroom)
		exitroom = load_object(__DIR__"kezhan");
	if (exp_to_level(me->query("combat_exp"))["level"] >= query("max_lv") && userp(me))
	{
		me->add_temp("block_msg/all",1);
		me->move(exitroom);
		me->add_temp("block_msg/all",-1);
		tell_object(me,MAG"��ջ�ϰ���Ц�����Ǽ䷿�Ѿ���λ�͹ٶ����ˡ�\n"NOR);
	}
}

