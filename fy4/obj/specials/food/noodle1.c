// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void do_eatflower();

void create(){
	set_name(HIR BLK"ţ����"NOR, ({"beef noodles", "noodles" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�����ţ���档\n");
		set("unit", "��");
		set("value", 100);
		set("finish_msg",CYN"$N��������ؽ�"+this_object()->query("name")+"���˸����⣬����������һ�ģ��е����ϰ壬����һ�룡\n"NOR);
		set("food_remaining", 1);
		set("food_supply", 1);
		set("eat_func", (: do_eatflower :) );
	}
    ::init_item();
}

void do_eatflower()
{
	object me;
	me = this_player();
	me->set("food",me->max_food_capacity()*2);
	return;
}
// ���p��dancing_faery@hotmail.com

