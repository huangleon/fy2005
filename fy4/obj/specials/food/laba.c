//

inherit ITEM;
inherit F_FOOD;
inherit F_LIQUID;

void init()
{
	if(environment()==this_player())
	add_action("do_eat", "eat");
	add_action("do_drink", "drink");
}

void create()
{
	set_name("������", ({ "laba zhou", "laba" }) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һֻ�໨�����,����װ���������ڵ������ࡣ\n");
		set("unit", "��");
		set("value", 200);
		set("food_remaining", 6);
		set("material", "food");
		set("food_supply", 90);
		set("max_liquid", 15);
		set("holiday", "���˽�");
		set("liquid", ([
                "type": "water",
                "name": "��������",
                "remaining": 15,
                "drunk_apply": 6,
        ]) );


	}
	 ::init_item();
}

int finish_eat()
{
	if (!query("liquid/remaining"))
	{
		set_name("�໨����", ({"bowl"}) );
		set("value", 10);
		set("long", "һֻ�໨����롣\n");
		return 1;
	}
}

	