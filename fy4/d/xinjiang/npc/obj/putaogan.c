// copyright c apstone, inc.

inherit COMBINED_ITEM;
inherit F_FOOD;
void create()
{
	set_name("���Ѹ�", ({ "putaogan" }) );
	set_weight(30);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�������������Ǻ�˵����Ѹɡ�\n");
		set("unit", "��");
		set("base_unit", "��");
                set("base_weight", 40);
                set("base_value", 30);
		set("food_remaining", 4);
		set("food_supply", 50);
	}
	set_amount(1);
}
