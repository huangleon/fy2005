// dumpling.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("±��", ({ "egg" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ����±��\n");
		set("unit", "��");
		set("value", 10);
		set("food_remaining", 3);
		set("food_supply", 6);
	}
}
