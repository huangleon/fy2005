// sword.c

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("����", ({ "sword" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��������\n");
		set("value", 200);
		set("material", "steel");
		set("rigidity", 80);
		set("wield_msg", "$N�����г��һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n�������䡣\n");
	}
	::init_sword(20);
}
