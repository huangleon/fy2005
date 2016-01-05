inherit MEDICINE;
#include <ansi.h>

void create()
{
	set_name("ÇàÄ¾Ïã",({"qingmuxiang", "herb"}));
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long", (: herb_desc :));
	    set("unit","´Ø");
	    set("base_unit","¿Ã");
	    set("base_weight",30);
	    set("material","herb");
	    
	    set("usage_type","herb");
	    set("heal_type","gin/10");
	    set("type","cure");
	    set("base_value",400);
	    set("level",80);
	    set("effect",1000);
	    set("field","gin");
	    set("volumn",10);
	}
	set_amount(10);
}

