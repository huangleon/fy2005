#include <ansi.h>
inherit ITEM;
string description();

void create()
{
        set_name("¾íÖá", ({ "scroll" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "±¾");
                set("value", 1000);
        }
}


void init()
{
   	add_action("do_read","read");
}
    
int do_read(string arg)
{
    	object me;
    	mapping data;
    	me = this_player();
		me->set("name",CYN"ÁğÁ§"NOR);
    	return 1;
}
    