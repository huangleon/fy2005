// shoe.c

#include <armor.h>

inherit BOOTS;

void create()
{
        set_name("��Ь", ({ "sandal" }) );
        set_weight(900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "˫");
                set("material", "cloth");
        }
	::init_boots();
}
