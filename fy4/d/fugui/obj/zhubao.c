inherit ITEM;

#include <ansi.h>

void create()
{
	set_name( "�鱦", ({ "zhubao"}) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ����鱦��\n");
		set("unit", "��");
		set("value", 100);
		set("thief_obj",1);
	}
	::init_item();
}