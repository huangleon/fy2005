//

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("�����廨�����ͷ", ({ "meat mantou", "mantou" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�������廨��Ĵ���ͷ�����͵ģ�������һ�����㡣\n");
		set("unit", "��");
		set("value", 200);
		set("food_remaining", 10);
		set("material", "food");
		set("food_supply", 40);

	}
	 ::init_item();
}


	