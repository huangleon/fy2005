#include <weapon.h>
inherit SWORD;

void create()
{
    set_name("̴ľ��", ({ "sword", }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 100);
                set("material", "bamboo");
        set("long", "����һ�����Ϻõ�̴ľ���ɵĽ����ֹ�ϸ����¡�\n");
        set("wield_msg", "$N�ó�һ�ѱ��µ�$n���������С�\n");
                set("unequip_msg", "$N�������е�$n��\n");
        }
    init_sword(27);
}
