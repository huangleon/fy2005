#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
	set_name(HIW"������"NOR, ({ "silver chainarmor","chainarmor" }) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "silver");
		set("long", "һ����������İ������ס�\n");
		set("value", 2000);
		set("armor_prop/armor", 6);
	}
	::init_cloth();
}
