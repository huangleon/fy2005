// hammer.c

#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("ת��Ͳ", ({ "jingtong","tong" }) );
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ��СС��ԲͲ��������������ؿ��ž��ġ�\n");
                set("value", 60000);
                set("material", "iron");
                set("wield_msg", "$N�ó�һ��$n�������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }

        ::init_hammer(1);
}
