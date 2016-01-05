// icy_boot.c

#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
	set_name(  "��Ӱ��ѥ" , ({ "ghosty boots", "boots" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 8000);
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
	::init_boots();
}
