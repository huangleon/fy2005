// dumpling.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	string *order = ({"��ɳ", "����", "����", "����", "�ٹ�"});
    set_name( order[random(5)] + "�±�", ({ "mooncake", "moon cake" }) );
	set_weight(250);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ��Ƥ���ڶ������˱ǵ��±���\n");
		set("unit", "��");
		set("value", 200);
		set("food_remaining", 3);
		set("material", "food");
		set("food_supply", 60);
		set("holiday", "�����");
	}
	 ::init_item();
}

	