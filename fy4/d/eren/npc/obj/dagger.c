// sword.c : an example weapon

#include <weapon.h>

inherit DAGGER;

void create()
{
    set_name("��", ({ "dagger" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        set("long", "һ������һ��ϸ��ذ�ס�\n");
        set("value", 9000);
		set("material", "steel");
	}
    init_dagger(50);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N��ৡ���һ������һ��$n�������С�\n");
	set("unwield_msg", "$N�����е�$n���뻳�ڡ�\n");


}
