#include <armor.h>
inherit CLOTH;

void create()
{
    set_name("�̿�ͷ", ({"shorts"}));
    set_weight(200);
    if( clonep() )
        set_default_object(__FILE__);
    else 
    {
        set("unit", "��");
        set("value", 2);
        set("long", "һ���̿㣬���������м仹�и�С�����ƺ������⹦�ܣ�\n");
        set("material", "cloth");
        set("armor_prop/armor", 1);
    }
    ::init_cloth();
}

