#include <weapon.h>
#include <ansi.h>

inherit DAGGER;

void create()
{
        set_name(WHT"ÑÀµñ¾û½£"NOR, ({ "ivory dagger","dagger" }) );
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "±ú");
                set("long", "Ò»±úµñ¹¤¾«Ï¸µÄÏóÑÀ¶Ì½£¡£\n");
   				set("no_stack",1);
				set("no_drop",1);
             set("value", 0);
                set("material", "ivory");
        }
        ::init_dagger(67);
}
