// sword.c

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("����", ({ "liandao" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�ѷ�����������\n");
		set("value", 1000);
		set("material", "steel");
		set("rigidity", 30);
		set("wield_msg", "$N������γ�һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n�������䡣\n");
	}
	::init_blade(10);
}
