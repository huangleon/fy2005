// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("����ս��", ({ "zhanjia" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "steel");
                set("value", 80);
		set("armor_prop/armor", 10);
	}
	::init_cloth();
}
