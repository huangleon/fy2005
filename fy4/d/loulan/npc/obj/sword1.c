// sword.c : an example weapon

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
    	set_name(HIG"∂œ√≈Ω£"NOR, ({ "duanmen sword","sword" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "∞—");
        	set("long", "±¶Ω£∂œ√≈,“˚—™∑ΩπÈ°£\n");
        	set("value", 90);
		set("material", "steel");
	}
    	init_sword(20);

}
