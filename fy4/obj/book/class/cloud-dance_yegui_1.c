#include <ansi.h>
inherit __DIR__"scroll.c";

void create()
{
        set_name(CYN"°∫ª√∑Á∆Æ‘∆ŒË°§¿Î»À“ππÈ£…°ª"NOR, ({ "scroll" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",(: description() :));
				set("value", 500);
                set("no_split",1);
                set("unit", "±æ");
                set("material", "paper");
                set("required_class","huashan");
                set("teaching", "yegui");
				set("required_exp", 1000000);
				set("required_skill", "cloud-dance");
                set("required_skill_level",150);
				set("grade",1);
        }
}

