// shoe.c

#include <armor.h>

inherit BOOTS;

void create()
{
        set_name("����ɮЬ", ({ "shoes" }) );
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "˫");
                set("material", "cloth");
				set("value",15);
        }
	::init_boots();
}
