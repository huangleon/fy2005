#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create() {
	set_name("É´ÒÂ", ({ "cloth" }) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "¼þ");
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("long","Ò»¼þÉ´ÒÂ¡£\n");
	}
	::init_cloth();
}
