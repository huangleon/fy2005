// pearl.c

#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("������", ({ "piece", "go piece" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"���������ɵ����Ӷ�\n");
		set("unit", "��");
		set("base_unit", "��");
		set("base_weight", 1);
		set("base_value", 1);
	}
	set_amount(50);
	init_throwing(1);
}
