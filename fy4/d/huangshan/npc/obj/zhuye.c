#include <weapon.h>
inherit BLADE;

void create() {
        set_name("ϸ������Ҷ", ({ "zhuye" }) );
        set_weight(400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 10);
                set("material", "bamboo");
                set("long", "����һ��ϸ������Ҷ��ҶԵ�����絶��\n");
                set("wield_msg", "$N��$n�������֡�\n");
                set("unequip_msg", "$N��$n�Ƶ����֡�\n");
        }
        ::init_blade(25);
}


int init()
{
        set("weapon_wielded","��");
}

