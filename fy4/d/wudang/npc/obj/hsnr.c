inherit F_FOOD;
inherit ITEM;

void create()
{
	set_name("����ţ��", ({ "fried beef", "beef" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ��װ��ţ��Ĵ�ˣ���ͨͨ��ţ�⣬��ͨͨ�Ľ�֭��\n");
		set("unit", "��");
		set("value", 1500);
		set("food_remaining", 5);
		set("food_supply", 60);
		set("material", "food");
	}
	::init_item();
}

int finish_eat()
{
        set_name("����", ({"panzi"}));
	set("value",20);
        set("long", "һֻ��ͨ�Ĵ����ӣ����ӱ�Ե������һ�顣\n");
        return 1;
}
