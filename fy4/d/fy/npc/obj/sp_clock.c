// annie 07.2003
// dancing_faery@hotmail.com

#include <weapon.h>
inherit HAMMER;

void create()
{
	set_name("定时闹钟", ({ "clock" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("value", 1000);
		set("material", "steel");
		set("long", "一个从西洋国度流传过来的小圆铁块。\n");
		set("desc_ext","闹铃(settime)");

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
		return notify_fail("你要弹什么？\n");

	if( sscanf(arg, "%d", time)!=1 || time < 0 || time > 43200)
		return notify_fail("用settime [秒数]来设置闹铃时间，时间不能超过六个时辰。\n");
	message_vision("$N取出一个定时闹钟，一板一眼的拧起发条。\n",me);
	remove_call_out("do_beep");
	call_out("do_beep",time,me);
	return 1;
}

void do_beep(object me)
{
	if (environment() == me)
	{
		message_vision("$N身上突然有什么东西＂哔哔哔＂的叫唤起来。\n",me);
		tell_object(me,"\n定时闹钟发出了一阵尖锐的鸣叫。\n\n现在时间是：\n");
		me->ccommand("uptime");
	}
}