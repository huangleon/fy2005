// cloth.c
//

#include <armor.h>

inherit CLOTH;
#include <ansi.h>
void create()
{
	set_name(HIW"ѩ�׳���"NOR, ({ "white cloth" }) );
	set_weight(3500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ��һ����Ⱦ��ѩ�׳���\n");
		set("material", "cloth");
		set("value", 4);
		set("armor_prop/armor", 5);
	}
	::init_cloth();
}
