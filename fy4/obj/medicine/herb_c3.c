
inherit MEDICINE;
#include <ansi.h>

void create()
{
	set_name("��Ҷ��צ��",({"qiyelongzhua", "herb"}));
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long",(: herb_desc :));
	    set("unit","��");
	    set("base_unit","��");
	    set("base_weight",30);
	    set("material","herb");
	    
	    set("usage_type","herb");
	    set("heal_type","kee/10");
	    set("type","cure");
	    set("base_value",200);
	    set("level",200);
	    set("effect",4000);
	    set("field","kee");
	    set("volumn",10);
	}
	set_amount(10);
}


