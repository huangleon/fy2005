// maple_leaf

#include <weapon.h>
#include <ansi.h>

inherit ITEM;


void create()
{
	set_name(HIR"��Ƿ�Ҷ"NOR, ({ "maple leaf", "leaf" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"һƬѤ���ķ�Ҷ��\n");
		set("unit", "Ƭ");
		set("weight",1);
		set("value", 1);
	}
	set("castable",1);
	::init_item();
}
