#include <weapon.h>
inherit WHIP;

void create() {
	set_name("����", ({ "chain" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1000);
		set("material", "iron");
		set("long", "����һ�ѹ����ǳ��õ�������Լ�����߳���\n");
		set("wield_msg", "$N������������һ��$n�������С�\n");
		set("unequip_msg", "$N�����е�$n�������䡣\n");
	}
	::init_whip(10);
}
