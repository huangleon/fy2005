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
    set_name("������", ({ "chicken soup", "soup" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long", "һ���������ڵ������棬����Ư��һЩ�л��������������˱ǡ�\n");
		set("unit", "��");
		set("value", 800);
		set("food_remaining", 6);
		set("material", "food");
		set("food_supply", 90);
        set("liquid", ([
        	"type": "water",
        	"name": "��������",
        	"remaining": 10,
        	"drunk_apply": 6,
        ]) );	
	}
	 ::init_item();
}

int finish_eat()
{
	set_name("�໨����", ({"bowl"}) );
	set("value", 10);
	set("long", "һֻ�໨����롣\n");
	return 1;
}

	
