inherit F_FOOD;
inherit ITEM;

void create()
{
	set_name("±ζ��", ({ "luwei", "lu" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ���Ϻõ�±ζ����\n");
		set("unit", "��");
		set("value", 0);
		set("food_remaining", 5);
		set("food_supply", 60);
		set("material", "food");
	}
	::init_item();
}


int finish_eat()
{
        set_name("С����", ({"panzi"}));
	set("no_stack",1);
	set("value",0);
        set("long", "һֻ���׶��񻨵����ӡ�\n");
        return 1;
}
