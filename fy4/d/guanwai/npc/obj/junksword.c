
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("�ƽ�", ({ "sword" }) );
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�������⡢��������ƽ�");
                set("value", 5);
                set("material", "steel");

        set("wield_msg", "$N��������һ�������⡢���˿ڶ���$n�������С�\n");
        set("unwield_msg", "$N�����е�$n�������䡣\n");
        }
        ::init_sword(8);
}

