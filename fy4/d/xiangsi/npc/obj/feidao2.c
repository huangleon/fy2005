// throwing_knife.c

#include <weapon.h>

inherit THROWING;

void create()
{
        set_name("����м", ({ "bamboo shard","shard" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Щ");
                set("base_unit", "Ƭ");
                set("base_weight", 1);
                set("base_value", 0);
                set("material", "wood");
                set("long",     "һ��������ץ�µ���м��\n");
                set("volumn",50);
        }
        set_amount(50);
		::init_throwing(15);
}

