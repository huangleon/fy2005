// cyn_cloth.c
//
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
#include <ansi.h>
void create()
{
	set_name(CYN"�಼����"NOR, ({ "cyan robe" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ���������಼���ۡ�\n");
		set("material", "cloth");
		set("value", 100);
		set("armor_prop/armor", 6);
	}
	::init_cloth();
}
