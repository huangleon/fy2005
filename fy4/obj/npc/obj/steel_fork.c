// steel_fork.c

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("��ɸֲ�", ({ "steel fork" }) );
	set_weight(30000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 3400);
                set("no_get",1);
                set("no_drop",1);

		set("material", "steel");
	}
	::init_sword(40);
}
