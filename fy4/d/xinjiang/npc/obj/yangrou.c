#include <weapon.h>
inherit THROWING;
inherit F_FOOD;
void create()
{
	set_name("�����⴮", ({ "fried sheep meat", "sheep", "meat" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�����������������������⴮���ó԰���\n");
		set("unit", "��");
                set("base_unit", "��");
                set("base_weight", 40);
                set("base_value", 25);
		set("food_remaining", 4);
		set("food_supply", 40);
		set("wield_msg", "$Nץ��һ��$n���������С�\n");
		set("material", "bamboo");
	}
	set_amount(1);
	::init_throwing(1);
}

int finish_eat()
{
	if( !query("weapon_prop") ) return 0;
	set_name("�����⴮������", ({ "bamboo stick" }) );
	set_weight(150);
	set("long", "һ�����������⴮������\n");
	return 1;
}
