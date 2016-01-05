// chicken_leg.c

#include <weapon.h>

inherit HAMMER;
inherit F_FOOD;

void create()
{
	set_name("������", ({ "fried pig leg", "leg" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "˵������,�����ֳ���Щ,����Щ....��\n");
		set("unit", "��");
		set("value", 300);
		set("food_remaining", 4);
		set("food_supply", 40);
		set("wield_msg", "$Nץ��һ��$n���������е�������\n");
		set("material", "bone");
	}
	::init_hammer(10);
}

int finish_eat()
{
	if( !query("weapon_prop") ) return 0;
	set_name("�еþ�����ȹ�", ({ "bone" }) );
	set_weight(150);
	set("long", "һ���еþ�����ȹǡ�\n");
	return 1;
}
