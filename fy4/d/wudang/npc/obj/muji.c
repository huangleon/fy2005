// shoe.c

#include <armor.h>
#include <ansi.h>

inherit BOOTS;

void create()
{
	set_name(YEL"ľ��"NOR, ({ "wood shoes","shoes" }) );
	set_weight(2000);
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	    set("unit", "˫");
	    set("material", "wood");
	    set("value", 1000);
	    set("long", "һ˫�߳���ľ��ľ�졣\n");
	}
	::init_boots();
}
