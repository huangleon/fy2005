inherit ITEM;

#include <ansi.h>
void create()
{
        set_name(GRN"������"NOR, ({ "bamboo basket","basket"}) );
        set_weight(100);
        set_max_encumbrance(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�������̵Ĵ�����Ƶķ�����\n");
                set("value", 150);
        }
}

int is_container() { return 1; }

