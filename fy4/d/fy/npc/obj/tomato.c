// by tie@fengyun

inherit ITEM;
#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name(RED"����"NOR, ({ "tomato" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long", "һ�������˵Ĵ���.\n");
		set("unit", "��");
        set("value", 50);
        set("food_remaining", 5);
		set("food_supply", 60);
	}
	::init_item();
}
