
#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("����", ({ "perfume" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","����ض���������Ĳ��㡣\n");
		set("unit", "��");
		set("base_unit", "��");
		set("base_weight", 3);
		set("base_value", 2);
		set("volumn",5);
	}
	set_amount(5);
	::init_throwing(1);
}
