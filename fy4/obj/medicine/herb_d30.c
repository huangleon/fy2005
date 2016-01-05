
inherit MEDICINE;
#include <ansi.h>

void create(){
	set_name("µ¥ÐÄº£ÌÄ",({"haitang", "herb"}));
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long",(: herb_desc :));
	    set("unit","´Ø");
	    set("material","herb");
	    set("base_unit","¿Ã");
	    set("base_weight",30);
	    set("base_value",400);
	    set("volumn",10);
	    
	    set("type","poison");	
	    set("field","gin");
	    set("level",110);
	    set("effect",150);	    
	    set("proc", 50);	// Proc rate
	}
	set_amount(10);
}
