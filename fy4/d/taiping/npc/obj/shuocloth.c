#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
	set_name(HIG"������"NOR, ({ "raincoat" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����һ�������˳����������¡�\n");
		set("material", "cloth");
		set("value",1000);
		set("armor_prop/armor", 10);
	}
	::init_cloth();
}
