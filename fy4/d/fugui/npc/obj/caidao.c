#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("�˵�", ({ "caidao","cai dao","dao" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 0);
		set("material", "iron");
		set("long", "����һѰ���Ĳ˵���ũ�ҳ���������\n");
		set("wield_msg", "$N���һ�����λε�$n�������С�\n");
		set("unequip_msg", "$N�����е�$n�������䡣\n");
	}
	::init_blade(5);
}
