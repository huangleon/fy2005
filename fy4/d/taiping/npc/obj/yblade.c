#include <weapon.h>
inherit BLADE;

void create() {
	set_name("����", ({ "ruler" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1000);
		set("material", "iron");
		set("long", "����һ�ѹ����ǳ��õ����ߣ��п�ĥ�������\n");
		set("wield_msg", "$N���һ�����λε�$n�������С�\n");
		set("unequip_msg", "$N�����е�$n����ڴ��\n");
	}
	::init_blade(10);
}
