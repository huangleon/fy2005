#include <ansi.h>
#include <weapon.h>
inherit LONG_BLADE;

void create() {
        set_name(HIY"ÆÆÉ½µ¶"NOR, ({ "blade" }) );
        set_weight(40000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "°Ñ");
                set("value", 1000);
                set("material", "iron");
        }
        ::init_blade(20);
}

