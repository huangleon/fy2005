
inherit MEDICINE;
#include <ansi.h>

void create()
{
	set_name("µÆÐÄ²Ý",({"dengcao", "herb"}));
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
	    set("base_value",1000);
	    set("level",180);
	    set("effect",2500);
	    set("field","kee");
	    set("volumn",10);
	}
	set_amount(10);
}

