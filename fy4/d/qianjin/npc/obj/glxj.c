inherit F_FOOD;
inherit ITEM;

void create()
{
	set_name("�����㽶", ({ "glxj", "dish" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ������������Ϻô�ˡ�\n");
		set("unit", "��");
		set("value", 2000);
		set("food_remaining", 3);
		set("food_supply", 10);
		set("material", "food");
	}
	::init_item();
}
int finish_eat()
{
        set_name("С����", ({"xiaodie"}));
	set("value",20);
        set("long", "һֻ���׶��񻨵ľ�̩��С������\n");
        return 1;
}
