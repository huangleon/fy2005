
inherit F_FOOD;
inherit ITEM;

void create()
{
	set_name("���", ({ "qing cai", "���"}) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ��û��һ���͵���ˡ�\n");
		set("unit", "��");
		set("value", 30);
		set("food_remaining", 3);
		set("food_supply", 30);
	}
	::init_item();
}

int finish_eat()
{
	set_name("�����", ({ "bowl" }) );
	set_weight(50);
	set("long", "һֻ����롣\n");
	return 1;
}
