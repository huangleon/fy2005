// food.c

inherit ITEM;
inherit F_FOOD;

void create()
{
    set_name("ʳ��", ({"food"}));
    set_weight(40);
    if (clonep())
	set_default_object(__FILE__);
    else {
	set("long", "��ҩ\n");
	set("unit", "��");
	set("value", 0);
	set("food_remaining", 100);
	set("food_supply", 100);
    }
    ::init_item();
}

