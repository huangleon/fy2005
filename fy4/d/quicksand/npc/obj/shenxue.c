
#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
	set_name(BLK"��ѥ"NOR, ({ "black boots", "boots" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "˫");
		set("value", 800);
		set("material", "cloth");
		set("armor_prop/armor", 5);
	}
	::init_boots();
}
