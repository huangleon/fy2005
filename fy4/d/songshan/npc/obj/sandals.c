// sandals.c

#include <armor.h>

inherit BOOTS;

void create()
{
	set_name("��Ь", ({ "sandals" }) );
	set_weight(900);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "wood");
		set("unit", "˫");
		set("value", 10);
	}
	::init_boots();
}
