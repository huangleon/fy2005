// TIE@FY3
#include <ansi.h>
#include <weapon.h>
inherit WHIP;
void create()
{
        set_name(HIR"����"NOR, ({ "tiesuo" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 500);
		set("rigidity",1000);
                set("material", "skin");
        set("wield_msg", "$N����������һ��$n�������С�\n");
        set("unwield_msg", "$N�����е�$n�������䡣\n");
        }
        ::init_whip(15);
}

