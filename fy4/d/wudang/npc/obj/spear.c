#include <weapon.h>
inherit SPEAR;

void create()
{
	set_name("��ǹ", ({ "spear" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ѿ����൱��ͨ�ĳ�ǹ��������Լ��ʮ�������ҡ�\n");
		set("value", 1000);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ����$n�������С�\n");
		set("unwield_msg", "$N�����е�$n������¡�\n");
	}
	::init_spear(20);
}
