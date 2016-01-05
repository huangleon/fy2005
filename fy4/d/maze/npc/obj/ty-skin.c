#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
	set_name("¾ÅÎ²»ğõõÆ¤", ({ "hide"}) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "¼ş");
		set("material", "leather");
		set("long", "Ò»ÕÅ¾ÅÎ²»ğõõµÄõõÆ¤¡£\n");
		set("value", 200);
		set("armor_prop/armor", 10);
	}
	::init_cloth();
}
