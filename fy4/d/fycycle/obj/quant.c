#include <weapon.h>
inherit STAFF;
void create()
{
        set_name( "����", ({ "quant" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("value", 100);
                set("material", "wood");
	        set("wield_msg", "$N�ó�һ��$n�������У�����������\n");
       		set("unwield_msg", "$N�����е�$n����������\n");
        }
        ::init_staff(10);

}

