// hammer.c

#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("��ĸ˫��", ({ "dual_ring" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����ص���ĸ˫����������൱��ʵ��\n");
                set("value", 1200);
                set("material", "iron");
                set("wield_msg", "$N�ó�һ˫$n��������������Ȼ���������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }

        ::init_hammer(15);
}
