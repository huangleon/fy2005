// cloth.c
//

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("̫�����Ե���", ({ "cloth" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ������̫�����Ե���\n");
		set("value", 1000);
		set("material", "cloth");
		set("armor_prop/armor", 2);
	}
	::init_cloth();
}
