// blade.c

#include <weapon.h>

inherit BLADE;

void create()
{
    set_name("���˵�", ({ "carver" }) );
    set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 300);
                set("material", "iron");
        set("long", "һ�Ѳ������Ĳ˵�, ���������в˿��⻹�Ǵ´����ŵġ�\n");
                set("wield_msg", "$N���һ�����λε�$n�������С�\n");
        set("unwield_msg", "$N�����е�$n���������ţƤ�����С�\n");
        }
    ::init_blade(5);
}
