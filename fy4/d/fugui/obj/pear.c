// copyright c apstone, inc.

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
    set_name(HIG"����"NOR, ({ "pear" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        	set("long", "һ������ȥ��������ˮ�Ĵ����档\n");
        	set("unit", "��");
        	set("value", 500);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
	::init_item();
}
