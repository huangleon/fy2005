// hat.c
#include <armor.h>
inherit HEAD;

void create()
{
    set_name("����", ({ "bighat" }) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 100);
		set("material", "wood");
		set("armor_prop/armor", 4);
	}
    ::init_head();
}
