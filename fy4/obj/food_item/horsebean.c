//

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("�����϶�", ({ "horsebean", "bean" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һС��ը���ִ�Ĳ϶���\n");
		set("unit", "��");
		set("value", 100);
		set("food_remaining", 6);
		set("material", "food");
		set("food_supply", 20);

	}
	 ::init_item();
}

int finish_eat()
{
	set_name("С����", ({"plate"}) );
	set("value", 10);
	set("long", "һֻСС�Ĵִŵ��ӡ�\n");
	return 1;
}

	