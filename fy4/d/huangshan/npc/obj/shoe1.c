// shoe.c

#include <armor.h>

inherit BOOTS;

void create()
{
	set_name( "ÂÌ²¼Ð¬", ({"shoes", "green shoes" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "Ë«");
		set("value", 1);
		set("armor_prop/armor", 1);
		set("female_only", 1);
	}
	::init_boots();
}
