#include <weapon.h>
inherit SPEAR;

void create() {
	set_name("���᳤ǹ", ({ "spear" }) );
	set_weight(2500);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
//		set("long", "����һ�ѿ����൱��ͨ�ĳ�ì");
		set("value", 200000);
		set("weapon_prop/attack",25);
		set("level_required",40);
		set("material", "steel");
		set("wield_msg", "$N��$n�������������С�\n");
		set("unwield_msg", "$N�ɿ������е�$n��\n");
	}
    ::init_spear(50);
}
