
#include <armor.h>

inherit CLOTH;

void create()
{
    set_name("����", ({ "dark cloth","cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "cloth");
		set("long", "һ���ںڵ����¡�\n");
		set("armor_prop/armor", 5);
	}
	::init_cloth();
}
