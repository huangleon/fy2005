// golden_sword.c

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("��潣", ({ "golden sword" }) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�������������ĳ�����\n");
		set("value", 3400);
                set("no_get",1);
                set("no_drop",1);

		set("material", "gold");
	set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
	set("unwield_msg", "$N�����е�$n��������Ľ��ʡ�\n");
	}
	::init_sword(30);
}
