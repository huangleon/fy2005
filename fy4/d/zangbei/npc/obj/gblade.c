#include <weapon.h>
inherit BLADE;

void create() {
	set_name("��ͷ��", ({ "blade" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1000);
		set("material", "iron");
		set("long", "����һ��ǿ�����õĹ�ͷ�󵶣�������ĺ��ǳ��ء�\n");
		set("wield_msg", "$N���һ�����λε�$n�������С�\n");
		set("unequip_msg", "$N�����е�$n���뵶�ʡ�\n");
	}
	::init_blade(10);
}
