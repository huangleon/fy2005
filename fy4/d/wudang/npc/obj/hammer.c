
#include <weapon.h>

inherit HAMMER;

void create()
{
	set_name("������", ({ "hammer" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ���޴��������\n");
		set("value", 400);
		set("material", "steel");
		set("rigidity", 200);
		set("wield_msg", "$N������γ�һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n�������䡣\n");
	}
	::init_hammer(10);
}
