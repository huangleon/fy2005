// spear.c
#include <ansi.h>
#include <weapon.h>
inherit SPEAR;

void create() {
	set_name(HIW"��ǹ"NOR, ({ "silver spear" }) );
	set_weight(20000);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "��ӧ��������ɫ�ĳ�ǹ�������Ķ�Ŀ��");
		set("value", 200);
		set("material", "steel");
		set("wield_msg", "$N��$n�������������С�\n");
		set("unwield_msg", "$N�ɿ������е�$n��\n");
	}
    ::init_spear(20);
}
