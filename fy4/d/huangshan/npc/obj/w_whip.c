#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()
{
        set_name(HIY"����Ϸ���"NOR, ({ "dragon whip","whip" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 150);
                set("long", "һ��������ʯ��������Ƥ�Ƴɵı��ӡ�\n");
                set("material", "skin");
		set("rigidity", 10000);
        	set("wield_msg", "$N����������һ��$n�������С�\n");
        	set("unwield_msg", "$N�����е�$n�������䡣\n");
        }

        ::init_whip(20);
}


