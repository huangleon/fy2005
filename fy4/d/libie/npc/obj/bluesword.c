#include <weapon.h>
inherit SWORD;

void create()
{
    set_name("��ɽ�Ž�", ({ "bluesword" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�����͹��ŵı��������������������⡣\n");
		set("value", 3);
		set("nodrop_weapon",1);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��������Ľ��ʡ�\n");
	}
	init_sword(10);
}

