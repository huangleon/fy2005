inherit ITEM;
#include <ansi.h>


void create()
{
        set_name("ֽ��", ({ "paper","ֽ��" }) );
	set_weight(20);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1);
		set("long","���������ֽ��ֽ��\n");
	}
	
	::init_item();
}


