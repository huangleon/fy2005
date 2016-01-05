inherit MEDICINE;
#include <ansi.h>

void create()
{
	set_name("Áúµ¨²Ý",({"longdan", "herb"}));
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long",(: herb_desc :));
	    set("unit","´Ø");
	    set("base_unit","¿Ã");
	    set("base_weight",30);
	    set("material","herb");
	    
	    set("usage_type","herb");
	    set("heal_type","kee/10");
	    set("type","cure");
	    set("base_value",200);
	    set("level",20);
	    set("effect",500);
	    set("field","kee");
	    set("volumn",10);
	}
	set_amount(10);
}

