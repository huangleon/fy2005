
#include <armor.h>

inherit WRISTS;

void create()
{
	set_name("����", ({ "jade piece"}) );
	set_weight(58);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ���������ε�������\n");
		set("unit", "��");
		set("value", 300);
		set("wear_msg", "$N����ذ�һ��$n���������ϡ�\n");
		set("unwield_msg", "$N����ذ�$n�������ϳ���������\n");


	}
	::init_wrists();
}

