#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()
{
        set_name( "����Ƥ��", ({ "snakewhip" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 500);
                set("material", "skin");
				set("rigidity", 100);
        		set("wield_msg", "$N����������һ��$n�������С�\n");
        		set("unwield_msg", "$N�����е�$n�������䡣\n");
        }

        ::init_whip(10);
}


