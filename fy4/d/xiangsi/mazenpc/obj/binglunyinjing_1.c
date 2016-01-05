#include <ansi.h>
inherit __DIR__"scroll.c";

void create()
{
        set_name(CYN"¡º±ùÂÖÓ¯¾µ¡¤ÌìĞÇÖ®ÕÂ¡»"NOR, ({ "scroll" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",(: description() :));

				set("value", 1000);
                set("unit", "±¾");
                set("material", "paper");

                set("required_class","moon");

                set("teaching", "binglunyinjing");
				set("required_exp", 1000000);
				set("required_skill", "chillblade");
                set("required_skill_level",120);
				set("grade",1);
        }
}

