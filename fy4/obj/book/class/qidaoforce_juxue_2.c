#include <ansi.h>
inherit __DIR__"scroll.c";

void create()
{
        set_name(CYN"¡ºÆåµÀ¡¤¾ÛÑª£É£É¡»"NOR, ({ "scroll" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",(: description() :));
				set("value", 1000);
                set("no_split",1);
                set("unit", "±¾");
                set("material", "paper");

                set("required_class","legend");
                set("teaching", "juxue");
				set("required_exp", 3000000);
				set("required_skill", "dormancy");
                set("required_skill_level",250);
				set("grade",2);
        }
}

