#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()
{
        set_name(HIR"�λ���"NOR, ({ "youhun whip","whip" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 100);
                set("material", "iron");
		set("rigidity", 60);
        set("wield_msg", "$N����������һ��$n�������С�\n");
        set("unwield_msg", "$N�����е�$n�������䡣\n");
        }
        ::init_whip(20);

}


