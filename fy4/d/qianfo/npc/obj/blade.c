// blade.c

#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("�䵶", ({ "blade" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 300);
                set("material", "iron");
                set("long", "����һ��ɮ�������õĽ䵶��������Լ�ġ�����ء�\n");
                set("wield_msg", "$N���һ�����λε�$n�������С�\n");
        set("unwield_msg", "$N�����е�$n��������ĵ��ʡ�\n");
        }
        ::init_blade(5);
}


