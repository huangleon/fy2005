inherit F_FOOD;
inherit ITEM;
#include <ansi.h>
void create()
{
    	set_name(HIR"�黨"NOR , ({ "flower" }) );
	set_weight(5);
	if( clonep() )
		set_default_object(__FILE__);
	else {
  	set("long", HIR"һ���ʺ����εĻ��䡣\n"NOR);
        set("unit", "��");
        set("value", 0);
		set("food_remaining", 1);
		set("food_supply", 0);
		set("material", "food");
	}
	::init_item();
}


