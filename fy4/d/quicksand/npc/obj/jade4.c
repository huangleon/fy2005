
#include <armor.h>

inherit WRISTS;

void create()
{
	set_name("������", ({ "jade"}) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ���������ε�������\n");
		set("unit", "��");
		set("value", 300000);
		set("wear_msg", "$N����ذ�һ��$n���������ϡ�\n");
		set("unequip_msg", "$N����ذ�$n�������ϳ���������\n");
		set("female_only", 1);

	}
	::init_wrists();
}

