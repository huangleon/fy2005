// fighting_suit.c
#include <armor.h>
inherit CLOTH;

void create()
{
    set_name("˿�����", ({ "silk cloth", "cloth" }) );
    set_weight(1000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("armor_type", "cloth");
        set("value", 25);
        set("armor_prop/armor", 1);
    }
    ::init_cloth();
}
