// tea_leaf.c

#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("��ë", ({ "feather" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","��������ҳ��ļ�ë��\n");
		set("unit", "��");
		set("base_unit", "Ƭ");
		set("base_weight", 1);
		set("base_value", 1);
		set("volumn",30);
	}
	set_amount(30);
	::init_throwing(1);
}
