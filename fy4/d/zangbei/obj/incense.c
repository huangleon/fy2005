#include <ansi.h>
#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("����", ({ "incense" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�ض���������Ĳ��㡣\n");
		set("unit", "��");
		set("base_unit", "֧");
		set("base_weight", 3);
		set("base_value", 200);
		set("volumn",2);
	}
	set_amount(2);
	::init_throwing(1);
}
