// hammer.c

#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("��������", ({ "hammer" }) );
        set_weight(80000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�ݴ��������ɹ����ﳣ�õ�������������������ر߹��⡣\n");
                set("value", 600000);
                set("material", "iron");
                set("wield_msg", "$N�ó�һ��$n��������������Ȼ���������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }

        ::init_hammer(20);
}
