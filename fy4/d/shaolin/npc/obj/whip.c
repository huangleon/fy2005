// TIE@FY3

#include <ansi.h>
#include <weapon.h>
inherit WHIP;
void create()
{
        set_name( "�ȱ���", ({ "whip" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 500);
                set("material", "skin");
        }
        init_whip(30);

        set("wield_msg", "$N����������һ��$n�������С�\n");
        set("unwield_msg", "$N�����е�$n�������䡣\n");

}

