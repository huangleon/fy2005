// chicken_leg.c
#include <weapon.h>
inherit HAMMER;
inherit F_FOOD;

void create()
{
	set_name("������Ĵ��", ({ "fried turkey", "turkey"}) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һֻ����������Ĵ�𼦣�����ȫ����ʦף�ش�Ҹж��ڿ��֣���\n");
		set("unit", "ֻ");
		set("food_remaining", 40);
		set("value",1);
		set("food_supply", 20);
		set("wield_msg", "$Nץ��һֻ$n���������е�������\n");
	}
        ::init_hammer(100);

}

int finish_eat()
{
	object money;
        if( !query("weapon_prop") ) return 0;
        set_name("�еþ���Ļ𼦹�", ({ "bone" }) );
        set_weight(150);
        set("long", "һ�����Ž��Ļ𼦹�\n");
	set_max_encumbrance(100);
	money = new("/obj/money/gold");
	money->move(this_object());
        return 1;
}

int is_container()
{
        if(this_object()->query("name") == "�еþ���Ļ𼦹�" )
                        return 1;
        else  return 0;
}

