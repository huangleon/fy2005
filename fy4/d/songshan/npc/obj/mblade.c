
#include <weapon.h>

inherit BLADE;

void create()
{
    set_name("����խ�е�", ({ "long blade" }) );
    set_weight(7000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("long", "����һ�Ѷ����ʿ���õĵ�");
        set("value", 300);
    set("rigidity", 2000);
        set("material", "steel");
    }
    ::init_blade(10);
}

