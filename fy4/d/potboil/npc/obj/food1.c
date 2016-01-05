#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(CYN"¶«º£ÕäâÊ"NOR, ({ "food"}) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "Íë");
		set("value", 1000);
		set("food_remaining", 25);
		set("food_supply", 250);
	}
	::init_item();
}
