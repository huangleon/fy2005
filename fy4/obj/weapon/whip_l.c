#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()
{
        set_name( "»¢Î²±Þ", ({ "whip" }) );
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ìõ");
                set("value", 1);
                set("material", "skin");
        }
        init_whip(4);
}

