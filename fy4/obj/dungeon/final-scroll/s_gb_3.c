
#include <ansi.h>
inherit "/obj/dungeon/scroll.c";

void create()
{
        set_name("�����޹�", ({ "scroll" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",(: description() :));
                set("value", 1000);
                set("material", "paper");
                
                set("teaching", "tianxiawugou");
		set("required_exp", 9000000);
                set("required_class","beggar");
                set("fy41","gb_tianxiawugou");
                    
        }
}

