#include <ansi.h>
#include <weapon.h>

inherit AXE;

void create()
{
        set_name( "�ָ�", ({ "handaxe" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","������С��ȴ�쳣������\n");
                set("value", 500);
                set("material", "skin");

        }
        ::init_axe(20);
}


