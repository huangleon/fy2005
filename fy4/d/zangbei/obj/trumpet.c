#include <weapon.h>
#include <ansi.h>

inherit ITEM;
void create()
{
	set_name("С��", ({ "trumpet","С��" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 5);
		set("material", "wood");
		set("long", "һ�����ź�˿����С�ţ������������ţ�play trumpet��\n");
	}
	::init_item();
}

void init()
{
   	if( this_player()==environment())
   		add_action("do_play","play");
}


int do_play(string arg)
{
   	object me, guard;
   	me = this_player();

   	if (!arg || (arg != "trumpet" && arg != "С��")) {
      		return 0;
   	}
   	
	guard = present("guard",environment(me));
	if (guard && guard->query("group")=="baiyunzhuang") {
		message_vision(HIG"$N����С�ţ������������ཱུش�������������һ�����������ҡ���\n"NOR,me);
		if (!me->query_temp("baiyunzhuang")) {
			me->set_temp("baiyunzhuang",1);
		}
		message_vision(CYN"ׯ����$N˵������ô��ô����������ȥ�ɣ����Ͼ�Ҫ������ˣ���\n"NOR,me);
	} else
		message_vision("$N����С�ţ������������ཱུش���������\n",me);
   	return 1;
}