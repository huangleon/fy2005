
#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("����", ({ "gupai" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"һ�ž�����͸����������\n");
		set("unit", "��");
		set("value", 100);
		set("base_unit", "��");
		set("base_weight", 1);
		set("base_value", 1);
		set("volumn",48);
	}
	set_amount(48);
	init_throwing(1);
}
