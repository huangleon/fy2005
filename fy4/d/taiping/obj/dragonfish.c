#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
    	set_name(HIY"������"NOR, ({ "dragon fish", "fish" }) );
    	set_weight(120);
    	if( clonep() )
        	set_default_object(__FILE__);
    	else {
        	set("long", "һ����������������㣬��������������\n");
        	set("unit", "��");
        	set("value", 5);
        	set("food_remaining", 3);
        	set("food_supply", 60);
    		set("marks/catfood", 1);
    	}
    	::init_item();
}

