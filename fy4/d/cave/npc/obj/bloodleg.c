// chicken_leg.c

#include <weapon.h>
#include <ansi.h>

inherit HAMMER;
inherit F_FOOD;

void create()
{
    set_name(HIR"��Ѫ���������"NOR, ({ "blood leg", "leg" }) );
    set_weight(3500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long", "һ���տ����������ڵĴ��ȣ�����ϸһ������Ȼ�ƺ����ˡ���\n");
		set("unit", "��");
        set("value", 10000);
		set("food_remaining", 4);
		set("food_supply", 40);
        set("wield_msg", "$N����һ��$n������������\n");
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
