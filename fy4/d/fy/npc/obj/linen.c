// linen.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("�ֲ���", ({ "linen" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "��");
		set("value", 40);
		set("armor_prop/armor", 2);
	}
	::init_cloth();
}
