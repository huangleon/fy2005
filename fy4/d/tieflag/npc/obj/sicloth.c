// cloth.c

#include <armor.h>

inherit CLOTH;

void create()
{
    set_name("˿��", ({"cloth"}) );
    set("long","��˿�������Ừ���Ļ�����\n");
    set_weight(500);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("material", "cloth");
        set("armor_prop/armor", 5);
    set("value",20);
    }
    ::init_cloth();
}
