// cloth.c
//
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(HIY"���"NOR, ({ "golden armor", "armor", "cloth" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "���ǽ�ɫ�Ŀ��ס�\n");
		set("value", 1000);
		set("material", "cloth");
		set("armor_prop/armor", 10);
	}
	::init_cloth();
}
