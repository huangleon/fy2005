// chicken_leg.c

#include <weapon.h>

inherit HAMMER;
inherit F_FOOD;

void create()
{
	set_name("������", ({ "fried chicken leg", "chicken", "leg" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ֦���ø�Ӳ�ļ��ȣ�����ճ�����̡�\n");
		set("unit", "��");

		set("value", 0);
		set("food_remaining", 4);
		set("food_supply", 40);
		set("wield_msg", "$Nץ��һ��$n���������е�������\n");
		set("material", "bone");
	}
	::init_hammer(1);
}

int finish_eat()
{
	if( !query("weapon_prop") ) return 0;
	set_name("�еþ������ѻ�ȹ�ͷ", ({ "bone" }) );
	set_weight(150);
	set("long", "һ���еþ������ѻ�ȹ�ͷ��\n");
	return 1;
}
