// lumber_axe.c

#include <weapon.h>

inherit AXE;

void create()
{
	set_name("����", ({ "lumber axe", "axe" }) );
	set_weight(22000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����ص���������������\n");
		set("value", 11);
		set("wield_msg", "$N�ó�һ�ѿ����õ�$n���������е���������\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}
	::init_axe(11, TWO_HANDED);
}
