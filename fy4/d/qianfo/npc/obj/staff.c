#include <weapon.h>
inherit STAFF;
void create()
{
        set_name("�����", ({ "staff","�����" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 300);
                set("material", "gold");
        	set("wield_msg", "$N��$n�������������С�\n");
        	set("unwield_msg", "$N�ɿ������е�$n��\n");
        }
        ::init_staff(10);

}
