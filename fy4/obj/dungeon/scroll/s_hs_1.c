#include <ansi.h>
inherit "/obj/dungeon/scroll.c";

void create()
{
        set_name("��ָ��ͨ����������", ({ "scroll" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",(: description() :));
                set("value", 1000);
                set("material", "paper");
                
                set("teaching", "mantianhuayu");
		set("required_exp", 6400000);
                set("required_class","huashan");
                set("fy41","hs_tz_double");
                    
        }
}