// TIE@fy3
#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
	set_name(HIW"����"NOR, ({ "yinjia", "jia" }) );
	set_weight(50000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "silver");
		set("value", 90);
		set("armor_prop/armor", 1);
	}
	::init_cloth();
}
