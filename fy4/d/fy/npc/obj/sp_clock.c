// annie 07.2003
// dancing_faery@hotmail.com

#include <weapon.h>
inherit HAMMER;

void create()
{
	set_name("��ʱ����", ({ "clock" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1000);
		set("material", "steel");
		set("long", "һ���������������������СԲ���顣\n");
		set("desc_ext","����(settime)");

	}
	::init_hammer(3);
}

void init()
{
	if (environment(this_object()) == this_player())
		add_action("do_set","settime");
}


int do_set(string arg)
{
	int time;
	object me;
	me = this_player();
	if (!arg)
		return notify_fail("��Ҫ��ʲô��\n");

	if( sscanf(arg, "%d", time)!=1 || time < 0 || time > 43200)
		return notify_fail("��settime [����]����������ʱ�䣬ʱ�䲻�ܳ�������ʱ����\n");
	message_vision("$Nȡ��һ����ʱ���ӣ�һ��һ�۵�š������\n",me);
	remove_call_out("do_beep");
	call_out("do_beep",time,me);
	return 1;
}

void do_beep(object me)
{
	if (environment() == me)
	{
		message_vision("$N����ͻȻ��ʲô�����������٣��Ľл�������\n",me);
		tell_object(me,"\n��ʱ���ӷ�����һ���������С�\n\n����ʱ���ǣ�\n");
		me->ccommand("uptime");
	}
}