// dumpling.c

inherit ITEM;
#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name(RED"�����"NOR, ({ "renroubao" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long", "һ�������硢�����ڵ��������ӡ�\n");
		set("unit", "��");
        set("value", 30000);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
	::init_item();
}
