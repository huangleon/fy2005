// sword.c : an example weapon

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("����", ({ "blade" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ѿ����൱��ͨ�ĳ�����������Լ��ʮ�������ҡ�\n");
		set("value", 400);
		set("material", "steel");
	}
	init_blade(25);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
	set("unwield_msg", "$N�����е�$n��������ĵ��ʡ�\n");


}
