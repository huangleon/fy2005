#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
    set_name("����", ({"bird tongue","tongue"}) );
    set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            	set("long", "�������ͷ�������ޱȡ�\n");
                set("unit", "��");
                set("value", 3);
                set("tongue",1);
        		set("food_remaining", 1);
                set("food_supply", 60);
        }
    ::init_item();
}
