#include <ansi.h>
inherit "/obj/dungeon/scroll.c";

void create()
{
        set_name("ɱ������", ({ "scroll" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",(: description() :));
                set("value", 1000);
                set("material", "paper");
                
                set("teaching", "sharenruma");
		set("required_exp", 12000000);
                set("required_class","assassin");
                set("fy41","jq_sharenruma");
                    
        }
}