#include <armor.h>
#include <weapon.h>
inherit WRISTS;
void create()
{
    set_name( "≤ ÔÌ" , ({ "bangle"}) );
    set_weight(100);
    if( clonep() )
	set_default_object(__FILE__);
    else {
	set("unit", "÷ª");
	//    set("value", 800);
	set("material", "silver");
	set("female_only", 1);
    }
    ::init_wrists();
}
