#include <weapon.h>
inherit SPEAR;

void create() {
	set_name("����ǹ", ({ "spear" }) );
	set_weight(2500);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
//		set("long", "����һ�ѿ����൱��ͨ�ĳ�ì");
		set("value", 100000);
		set("weapon_prop/attack",20);
		set("level_required",30);
		set("material", "steel");
		set("wield_msg", "$N��$n�������������С�\n");
		set("unwield_msg", "$N�ɿ������е�$n��\n");
	}
    ::init_spear(40);
}
