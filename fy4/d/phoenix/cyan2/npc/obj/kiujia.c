#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("��ɽ�ټ�", ({ "zhanjia" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "steel");
        set("value", 10);
		set("armor_prop/armor", 1);
	}
	::init_cloth();
}
