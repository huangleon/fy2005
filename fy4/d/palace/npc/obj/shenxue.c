
#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
	set_name(HIR"��Ӱ��ѥ"NOR, ({ "ghosty boots", "boots" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 8000);
		set("material", "cloth");
        	set("armor_prop/armor", 5);
	}
	::init_boots();
}
