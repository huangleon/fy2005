#include <ansi.h>
inherit F_FOOD;
inherit ITEM;

void create()
{
    set_name(HIG"����"NOR, ({ "qing tuan","tuan"}) );
	set_weight(35);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long", "�����ѽ���Ҫʳ��֮һ.\n");
		set("unit", "��");
        set("value", 100);
        set("food_remaining", 60);
		set("food_supply", 200);
		set("material", "food");
	}
	::init_item();
}
