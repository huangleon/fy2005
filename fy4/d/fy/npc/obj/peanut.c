inherit F_FOOD;
inherit ITEM;

void create()
{
	set_name("������", ({ "peanut"}) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�������ס�\n");
		set("unit", "��");
		set("value", 100);
		set("food_remaining", 5);
		set("food_supply", 60);
		set("material", "food");
	}
	::init_item();
}
