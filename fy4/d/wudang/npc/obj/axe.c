
#include <weapon.h>

inherit AXE;

void create()
{
	set_name("����", ({ "axe" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�������Ŀ��񸫡�\n");
		set("value", 200);
		set("material", "steel");
		set("rigidity", 200);
		set("wield_msg", "$N������γ�һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n�������䡣\n");
	}
	::init_axe(10);
}
