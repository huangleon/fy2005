
#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("��ש", ({ "teablock" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","��������Ĳ�ש��\n");
		set("unit", "��");
		set("base_unit", "��");
		set("base_weight", 5);
		set("base_value", 10);
		set("volumn",7);
	}
	set_amount(7);
	::init_throwing(1);
}
