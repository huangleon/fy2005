// chicken_leg.c

#include <weapon.h>

inherit THROWING;
inherit F_FOOD;

void create()
{
	set_name("ӣ��", ({ "peach" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ��̩ɽ�ϵ�ӣ��,��ɫ������\n");
		set("unit", "��");
		set("base_unit","��");
		set("base_value", 30);
		set("food_remaining", 4);
		set("food_supply", 40);
		set("wield_msg", "$N��$n�������е�������\n");
		set("material", "bone");
	}
	set_amount(1);
	::init_throwing(4);
}

int finish_eat()
{
	return 0;
}
