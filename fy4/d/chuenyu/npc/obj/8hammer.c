// sixhammer.c

#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("����������", ({ "eighthammer" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�Ѱ����������������ġ�\n");
                set("value", 800);
                set("material", "blacksteel");
                set("wield_msg", "$N�ó�һ��$n��������������Ȼ���������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }

        ::init_hammer(17);
}
