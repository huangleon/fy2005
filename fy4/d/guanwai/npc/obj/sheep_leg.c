// chicken_leg.c

#include <weapon.h>

inherit HAMMER;
inherit F_FOOD;

void create()
{
	set_name("������", ({ "fried sheep leg", "sheep", "leg" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ֦�������������ȣ��㻹��ԥʲ�᣿׼��θҺ�ɡ�\n");
		set("unit", "��");
		set("value", 30);
		set("food_remaining", 5);
		set("food_supply", 50);
		set("wield_msg", "$Nץ��һ��$n���������е�������\n");
		set("material", "bone");
	}
	::init_hammer(1);
}

int finish_eat()
{
	if( !query("weapon_prop") ) return 0;
	set_name("�еþ�������ȹ�ͷ", ({ "bone" }) );
	set_weight(150);
	set("long", "һ���еþ�������ȹ�ͷ��\n");
	return 1;
}
