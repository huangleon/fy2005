// (C) 2000 Tie

#include <armor.h>

inherit CLOTH;
void create()
{
	set_name("��������", ({ "jiasha" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
	::init_cloth();
}
