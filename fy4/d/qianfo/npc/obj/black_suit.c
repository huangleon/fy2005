// black_suit.c

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("ҹ����", ({ "black suit", "suit" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 100);
                set("material", "cloth");
                set("armor_prop/armor", 1);
                set("armor_prop/id", ({"figure"}) );
                set("armor_prop/name", ({"������"}) );
                set("armor_prop/short", ({"������(figure)"}) );
                set("armor_prop/long", ({
                        "һ������ɫҹ���£���������������ļһ\n"
                }) );
        }
        ::init_cloth();
}
