inherit F_FOOD;
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIR"�ϳ���"NOR, ({ "duancao", "cao" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",  "һ��" + HIR "�綾"NOR +"�Ķϳ���\n" );
		set("unit", "��");
		set("value", 200);
		set("food_remaining", 1);
		set("food_supply", 0);
		set("material", "food");
	}
	::init_item();
}
int finish_eat()
{
	object me;
	me = this_player();
	me->apply_condition("no_shadow",10);
	destruct(this_object());
        return 1;
}
