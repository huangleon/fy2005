#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(HIW"�µ���"NOR, ({ "cloth" }) );
	set_weight(1000);
	set("long", "һ��ո�µ����������\n");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "cloth");
		set("armor_prop/armor", 5);
		set("value", 100);
	}
	::init_cloth();
}
