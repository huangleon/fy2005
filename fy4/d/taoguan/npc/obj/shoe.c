// shoe.c
#include <armor.h>

inherit BOOTS;

void create()
{
	set_name("���Ƿ���ѥ", ({ "cloudy shoes", "shoes" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "˫");
		set("value", 6000);
		set("material", "cloth");
		set("armor_prop/armor", 2);
	}
	::init_boots();
}
