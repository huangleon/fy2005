
inherit MEDICINE;
#include <ansi.h>

void create()
{
	set_name("¡È÷•",({"lingzhi", "herb"}));
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long",(: herb_desc :));
	    set("unit","¥ÿ");
	    set("base_unit","ø√");
	    set("base_weight",30);
	    set("material","herb");
	    
	    set("usage_type","herb");
	    set("heal_type","kee/10");
	    set("type","full");
	    set("base_value",200);
	    set("level",150);
	    set("effect",6000);
	    set("field","kee");
	    set("volumn",10);
	}
	set_amount(10);
}
