inherit F_FOOD;
inherit ITEM;
#include <ansi.h>

void create()
{
    set_name( YEL"���⸬"NOR, ({ "wolf meat","meat" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�����Ƶ��ָ���Ӳ���ѽ������⡣\n");
		set("unit", "��");
		set("value", 300);
		set("food_remaining", 5);
		set("food_supply", 20);
		set("material", "food");
	}
	::init_item();
}
