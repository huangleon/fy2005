
#include <armor.h>

inherit WRISTS;

void create()
{
	set_name("������", ({ "jade piece"}) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ���������ε�������\n");
		set("unit", "��");
		set("value", 1500);
		set("wear_msg", "$N����ذ�һ��$n���������ϡ�\n");
		set("unwield_msg", "$N����ذ�$n�������ϳ���������\n");


	}
	::init_wrists();
}

