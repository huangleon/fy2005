#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
	set_name(RED"�������"NOR, ({ "witch clothes","clothes" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "cloth");
		set("armor_prop/armor", 0);
	}
	::init_cloth();
}
