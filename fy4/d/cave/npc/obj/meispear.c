// spear.c
#include <ansi.h>
#include <weapon.h>
inherit SPEAR;

void create() {
	set_name(HIY"��÷����ì"NOR, ({ "mei spear", "spear" }) );
	set_weight(10000);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "ì��֪���úβ������ɵģ���Ӳ�����е��ԡ�");
		set("value", 300000);
		set("rigidity", 2000);
		set("material", "steel");
		set("wield_msg", "$N��$n�������������С�\n");
		set("unwield_msg", "$N�ɿ������е�$n��\n");
	}
    ::init_spear(10);
}
