
#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("���䵶", ({ "blade" }) );
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�������⡢���˿ڶ����䵶");
                set("value", 5);
                set("material", "steel");
        set("wield_msg", "$N��������һ�������⡢���˿ڶ���$n�������С�\n");
        set("unwield_msg", "$N�����е�$n�������䡣\n");
        }
        ::init_blade(7);



}

