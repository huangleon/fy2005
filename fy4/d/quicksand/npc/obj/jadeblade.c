#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
        set_name(HIG"�������"NOR, ({ "jadeblade" }) );
        set_weight(100000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����������������������ĺ�����");
                set("value", 900);
		set("rigidity", 200);
                set("material", "steel");
	        set("wield_msg", "$N��������һ����������$n�������С�\n");
	        set("unwield_msg", "$N�����е�$n�������䡣\n");
        }
        ::init_blade(15);

}

