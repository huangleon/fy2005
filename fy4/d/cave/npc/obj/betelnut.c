// copyright c apstone, inc.

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
    set_name(YEL"����"NOR, ({"betelnut" }) );
    set_weight(20);
	if( clonep() )
		set_default_object(__FILE__);
	else {
            set("long", "һ�ֵز��Ϻ�������Ӳ��ˮ��������ζ�ǳ����������ܡ�\n");
        	set("unit", "��");
        	set("value", 500);
        set("food_remaining", 10);
		set("food_supply", 60);
	}
    ::init_item();
}
