#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()
{
        set_name( "��β��", ({ "whip" }) );
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1);
                set("material", "skin");
        }
        init_whip(4);
}

