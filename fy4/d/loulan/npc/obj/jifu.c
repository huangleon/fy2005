#include <armor.h>
inherit CLOTH;
#include <ansi.h>

void create()
{
	set_name(HIR"��켪��"NOR, ({ "wedding dress" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�����ɫ�Ļ��񼪷���\n");
		set("material", "cloth");
		set("value", 5);
		set("armor_prop/armor", 3);
	}
	::init_cloth();
}