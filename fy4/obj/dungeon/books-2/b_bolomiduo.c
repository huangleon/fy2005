#include <ansi.h>
inherit "/obj/dungeon/draft.c";

void create()
{
        set_name("�����۶��ľ�", ({ "book" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",(: description() :));
                set("value", 1000);
                set("no_get", 1);
                set("no_drop",1);
                set("no_sell",1);
                set("material", "paper");
                
                set("teaching", "bolomiduo");
		set("teaching_limit", 160);
		set("required_level",140);
		set("required_exp", 3000000);
                set("perform_name","�����Ϸ�ţݣ�roar��");    
        }
}