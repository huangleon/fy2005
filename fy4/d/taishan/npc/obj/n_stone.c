// pearl.c

#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("����", ({ "needle" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"һ��ϸ��˿�ߵ����롣\n");
		set("unit", "��");
		set("base_unit", "��");
		set("base_weight", 1);
		set("base_value", 0);
		set("stone",1);
		set("volumn",500);
	}
	set_amount(500);
	::init_throwing(11);
}
