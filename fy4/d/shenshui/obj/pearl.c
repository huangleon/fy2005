// pearl.c

#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("������", ({ "big pearl", "pearl" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"��ֵ���ǵ�ҹ���飬����һ�������ĵĹ���\n");
		set("unit", "��");
		set("base_unit", "��");
		set("base_weight", 1);
		set("base_value", 10000);
	}
	set_amount(3);
	::init_throwing(7);
}
