#include <ansi.h>
inherit "/obj/dungeon/scroll.c";

void create()
{
        set_name("����������Ƶ���", ({ "scroll" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",(: description() :));
                set("value", 1000);
                set("material", "paper");
                
                set("teaching", "Drift to baiyun");
		set("required_exp", 6000000);
                set("required_class","taoist");
                set("fy41","taoist_drift_2");
                    
        }
}