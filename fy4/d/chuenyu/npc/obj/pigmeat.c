#include <weapon.h>
inherit HAMMER;
inherit F_FOOD;

void create()
{
        set_name("��ɽ����", ({ "pork" }) );
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "��! ����Ŀ�ɽ����! ���Ի���ʲô?\n");
		set("unit", "��");
		set("value", 60);
        	set("food_remaining", 6);
		set("food_supply", 90);
        	set("material", "rib");
	}
        ::init_hammer(4);
}

int finish_eat()
{
        set_name("ɽ���ͷ", ({ "rib" }) );
        set_weight(250);
        set("long", "�еþ����ɽ���ͷ��\n");
        return 1;
}

	
