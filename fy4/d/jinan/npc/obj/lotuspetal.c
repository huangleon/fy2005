// dumpling.c

inherit ITEM;
#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name(GRN"����"NOR, ({ "lotus petal","petal" }) );
    set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long", "һ�����ʵ�������ⰻȻ�����滹�м��κ�ˮ��\n");
        set("unit", "��");
		set("value", 1000);
		set("food_remaining", 3);
		set("food_supply", 6);
	}
}
