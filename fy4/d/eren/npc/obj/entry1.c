#include <ansi.h>
inherit F_FOOD;
inherit ITEM;

void create()
{
	set_name(WHT"�ҹ�������˽�"NOR, ({ "entry"}) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "�����̵׵���һ���ɽ���⣬����߸ߵض�����ඹѿ��\n");
		set("unit", "��");
		set("value", 200);
		set("food_remaining", 5);
		set("food_supply", 60);
		set("material", "food");
	}
	::init_item();
}

int finish_eat()
{
        set_name("����", ({"panzi"}));
		set("value",200);
        set("long", "һֻ���׶��񻨵ľ�̩�������ӡ�\n");
        return 1;
}
