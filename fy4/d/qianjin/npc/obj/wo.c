
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("������", ({ "wu grass" , "grass"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1);
	}
}



