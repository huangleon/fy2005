#include <armor.h>

inherit CLOTH;

void create()
{
    set_name("˿����", ({"silk cloth", "cloth"}));
    set_weight(1000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long","һ��˿���ۣ��ʵغͲü�������\n");
        set("material", "cloth");
        set("unit", "��");
        set("value", 6);
        set("armor_prop/armor", 10);
    }
    ::init_cloth();
}
