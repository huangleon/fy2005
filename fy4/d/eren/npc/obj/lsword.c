#include <weapon.h>
inherit SWORD;

void create() {
	set_name("�彣", ({ "sword"}) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�ѷ���������ʵ�����ĳ�����\n");
		set_weight(6000);
		set("value", 300);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��������Ľ��ʡ�\n");
	}
	::init_sword(20);
}
