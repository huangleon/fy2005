#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("���Ҷ�װ", ({ "cloth" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "cloth");
        set("value", 10);
		set("no_get",1);
		set("armor_prop/armor", 1);
	}
	::init_cloth();
}
