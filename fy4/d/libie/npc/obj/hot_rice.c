inherit F_FOOD;
inherit ITEM;

void create()
{
	set_name("�������ڵĴ��׷�", ({ "hot rice" ,"rice"}) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ���������ڵĴ��׷���\n");
		set("unit", "��");
		set("value", 20);
		set("food_remaining", 20);
		set("food_supply", 60);
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
	set_name("����Ĵ��׷�", ({ "cold rice" ,"rice"}) );
	set("long", "һ���Ѿ����˵Ĵ��׷���\n");
}
