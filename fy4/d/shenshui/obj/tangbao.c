inherit F_FOOD;
inherit ITEM;

void create()
{
	set_name("�ǰ���", ({ "tangbao", "dish" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ����������С���ǰ�����Ө��͸���������ζ���ɵ�����ʳ���󷢡�\n");
		set("unit", "��");
		set("value", 2);
		set("food_remaining", 5);
		set("food_supply", 60);
		set("material", "food");
	}
	::init_item();
}
int finish_eat()
{
        set_name("����", ({"panzi"}));
		set("value",2);
        set("long", "һֻ�׵׶������Ĵ����ӡ�\n");
        return 1;
}
