#include <weapon.h>
inherit HAMMER;
inherit F_FOOD;

void create()
{
        set_name("�ռ�", ({ "meat" }) );
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "һֻ������Ŀ��ռ�!\n");
		set("unit", "ֻ");
        set("value", 800);
        set("food_remaining", 6);
		set("food_supply", 50);
        set("material", "rib");
	}
        ::init_hammer(2);
}

int finish_eat()
{
        set_name("�ռ���ͷ", ({ "rib" }) );
        set_weight(250);
        set("long", "�еþ�����ټ���ͷ��\n");
        return 1;
}

	
