
#include <weapon.h>
inherit SWORD;

void create() {
	set_name("������", ({ "sword" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
//		set("long", "����һ�ѿ������൱��ͨ�ĳ�����������Լ��ʮ�������ҡ�\n");
		set("value", 2000);
		set("weapon_prop/attack",10);
		set("level_required",10);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��������Ľ��ʡ�\n");
	}
	::init_sword(20);
}
