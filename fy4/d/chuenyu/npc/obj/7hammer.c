// sixhammer.c

#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("���Ǵ�", ({ "sevenhammer" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����������������ġ�\n");
                set("value", 600);
                set("material", "steel");
                set("wield_msg", "$N�ó�һ��$n��������������Ȼ���������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }

        ::init_hammer(15);
}
