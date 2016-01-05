#include <ansi.h>
inherit __DIR__"scroll.c";

void create()
{
        set_name(CYN"¡º·èÄ§ÕÈ·¨¡¤·èÄ§¾÷¡»"NOR, ({ "scroll" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",(: description() :));
				set("value", 1000);
                set("no_split",1);
                set("unit", "±¾");
                set("material", "paper");
                set("required_class","lama");
                set("teaching", "fengmo");
				set("required_exp", 6400000);
				set("required_skill", "fengmo-staff");
                set("required_skill_level",180);
				set("grade",1);
        }
}

