#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create() {
	set_name("ɱ��", ({ "blade" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1);
		set("long","һ�����λε�ɱ����\n");
		set("material", "iron");
		set("wield_msg", "$N���һ�����λε�$n�������С�\n");
		set("unequip_msg", "$N�����е�$n����ڴ��\n");
	}
	::init_blade(10);
}
