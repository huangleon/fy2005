// tea_leaf.c

#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("�軨", ({ "teaflower", "flower" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"��׵�ɽ�軨������һ�ɵ�����������\n");
		set("unit", "��");
		set("base_unit", "��");
		set("base_weight", 1);
		set("base_value", 1);
	}
	set_amount(2);
	init_throwing(2);
	setup();
}
