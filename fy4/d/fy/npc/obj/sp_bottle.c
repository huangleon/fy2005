// annie 07.2003
// dancing_faery@hotmail.com

#include <weapon.h>
#include <ansi.h>
inherit HAMMER;

void create()
{
	set_name(CYN"����ƿ"NOR, ({ "bottle" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1000);
		set("material", "jade");
		set("long", "һ����ɫ��С��ƿ��ƿ�ڷ�����ľ����������\n����ʢ�ľ�˵��������ɽǧ���������������֮Ч��\n");
		set("desc_ext","����(smell)");

	}
	::init_hammer(1);
}

void init()
{
	if (environment(this_object()) == this_player())
		add_action("do_smell","smell");
}


int do_smell(string arg)
{
	int time;
	object me;
	me = this_player();
	if (!arg || arg != "bottle")
		return notify_fail("��Ҫ��ʲô��\n");

	message_vision("$Nȡ��һ��СС��"CYN"����ƿ"NOR"���ο���ľ�������ᡣ\n",me);
	if (random(10))
	{
		tell_object(me,HIG"һ�����˵�ܰ��������������У�����\n"NOR);
		me->receive_heal("sen",20);
	}
	else
	{
		tell_object(me,HIG"һ�����˵�ܰ����������ıǶˣ�����\n��ı���ͻȻ��Щ�����������������磡\n"YEL"��⣬�����ˣ�\n"NOR);
		me->unconcious();
	}
	return 1;
}
