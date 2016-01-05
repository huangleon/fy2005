// icy_girth.c

#include <ansi.h>
#include <armor.h>

inherit WAIST;

void create()
{
	set_name(  "´µÑ©²ÐÔÆ´ø" , ({ "icy girth", "girth" }) );
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "Ìõ");
		set("value", 700);
		set("material", "cloth");
		set("male_only", 1);
	}
	::init_waist();
}
