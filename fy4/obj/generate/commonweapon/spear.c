#include <weapon.h>
inherit SPEAR;

void create() {
	set_name("��ì", ({ "spear" }) );
	set_weight(2000);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ѿ����൱��ͨ�ĳ�ì");
		set("value", 200);
		set("material", "steel");
		set("wield_msg", "$N��$n�������������С�\n");
		set("unwield_msg", "$N�ɿ������е�$n��\n");
	}
    ::init_spear(10);
}
