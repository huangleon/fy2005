
#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("����", ({ "hu-blade" }) );
        set_weight(6500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�������������ĺ���\n");
                set("value", 200);
                set("material", "steel");
	        set("wield_msg", "$N��������һ����������$n�������С�\n");
	        set("unwield_msg", "$N�����е�$n�������䡣\n");
        }
        ::init_blade(5);

}

