inherit F_FOOD;
inherit ITEM;

void create()
{
	set_name("�������ڵ����", ({ "hot greens" ,"greens"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ���������ڵĴ��׷���\n");
		set("unit", "��");
		set("value", 45);
		set("food_remaining", 10);
		set("food_supply", 40);
		set("material", "food");
	}
	::init_item();
}
int finish_eat()
{
        set_name("����", ({"bowl"}));
	set("value",10);
        set("long", "һֻ�ִɴ��롣\n");
        return 1;
}
void init()
{
	::init();
	call_out("cold",100+random(100));
	
}

void cold()
{
	set_name("��������", ({ "cold greens" ,"greens"}) );
	set("long", "һ���Ѿ����˵���ˡ�\n");
}
