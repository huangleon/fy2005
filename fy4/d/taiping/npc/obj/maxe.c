#include <ansi.h>
#include <weapon.h>
inherit AXE;

void create() {
	set_name(HIR"ħ��"NOR, ({ "axe" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1000);
		set("no_get",1);
		set("material", "iron");
		set("wield_msg", "$N���һ�����λε�$n�������С�\n");
		set("unequip_msg", "$N�����е�$n����ڴ��\n");
	}
	::init_axe(30);
}
