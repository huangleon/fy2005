#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name(RED"������խ��"NOR, ({ "ao" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","һ��������խ����\n");
		set("material", "cloth");
		set("armor_prop/armor", 5);
		set("value",100);
	}
	::init_cloth();
}
