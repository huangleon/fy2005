// spear.c

#include <weapon.h>
inherit SPEAR;

void create() {
    set_name("����ǹ", ({ "spear" }) );
    set_weight(50000);
	if(clonep())
		set_default_object(__FILE__);
	else {
        set("unit", "��");
        set("long", "����һ�˲ر������˱��ڲ��Զ��������ǹ��\n");
        set("value", 6000);
		set("material", "steel");
        set("wield_msg", "$N��$n���ε��������У�ˣ�˸�ǹ����\n");
        set("unwield_msg", "$N�������е�$n��\n");
	}
    ::init_spear(25);
}
