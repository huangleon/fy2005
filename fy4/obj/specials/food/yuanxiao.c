// dumpling.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	string *order = ({"��ɳ", "����", "����", "����", "�ٹ�", "����"});
	set_name(order[random(6)]+"Ԫ��", ({ "yuan xiao", "yuanxiao" }) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ���������ڵ�Ԫ����\n");
		set("unit", "��");
		set("value", 100);
		set("food_remaining", 3);
		set("material", "food");
		set("food_supply", 60);
		set("holiday", "Ԫ����");
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

	