inherit F_FOOD;
inherit ITEM;
#include <ansi.h>

void create()
{
    set_name(RED"б���д������"NOR, ({ "food" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long", "һ�̾������Ƶ���ζ���ȣ��������磬�컨��Ҷ��б����ʮ�־������ˡ�\n");
		set("unit", "��");
		set("value", 2000);
		set("food_remaining", 10);
		set("food_supply", 50);
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
