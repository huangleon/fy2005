#include <weapon.h>
#include <ansi.h>
inherit STAFF;

void create()
{
        set_name( "����" , ({ "changgao" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�������ĳ���\n");
                set("value", 4000);
                set("material", "steel");
                set("wield_msg", "$Nһ���ֳ���$n��\n");
                set("unwield_msg", "$N�����е�$n������¡�\n");
        }
        ::init_staff(6);
}
