#include <ansi.h>
inherit F_FOOD;
inherit ITEM;

void create()
{
        set_name(YEL"�ʳ�"NOR, ({ "intestine" }) );
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "һ���ִ��ִ�ķʳ���\n");
		set("unit", "��");
       		set("food_remaining", 5);
		set("food_supply", 90);
       		set("material", "rib");
	}
        ::init_item();
}
