// hammer.c

#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("������", ({ "mace" }) );
        set_weight(50000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�ѳ�����������,Ȯ������,�Ե��쳣.��\n");
                set("value", 0);
                set("material", "steel");
                set("wield_msg", "$N˫��ʹ��������һ�����������������Ī��֮�ƣ�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }

        ::init_staff(20);
}
