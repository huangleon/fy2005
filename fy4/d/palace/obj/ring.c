
#include <armor.h>
#include <ansi.h>
inherit FINGER;

void create()
{
	set_name(CYN"�����ֻ�"NOR, ({ "shouhuan"}) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ��͸��ɭɭ�������ֻ�\n");
		set("unit", "��");
		set("value", 300);
		set("armor_prop/astral_vision", 1);
		set("wear_msg", "$N����ذ�һ��$n���������ϡ�\n");
		set("unwield_msg", "$N����ذ�$n�������ϳ���������\n");


	}
	::init_finger();
}

