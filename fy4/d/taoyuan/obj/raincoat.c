// raincoat.c

#include <armor.h>

inherit SURCOAT;

void create()
{
	set_name("����", ({ "raincoat" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "plant");
		set("unit", "��");
		set("value", 30);
		set("armor_prop/armor", 2);
	}
	::init_surcoat();
}
