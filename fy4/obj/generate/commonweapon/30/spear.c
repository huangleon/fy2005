#include <weapon.h>
inherit SPEAR;

void create() {
	set_name("�ػ���ǹ", ({ "spear" }) );
	set_weight(2500);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
//		set("long", "����һ�ѿ����൱��ͨ�ĳ�ì");
		set("value", 20000);
		set("weapon_prop/attack",15);
		set("level_required",20);
		set("material", "steel");
		set("wield_msg", "$N��$n�������������С�\n");
		set("unwield_msg", "$N�ɿ������е�$n��\n");
	}
    ::init_spear(30);
}
