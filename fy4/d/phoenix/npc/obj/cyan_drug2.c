inherit MEDICINE;
#include <ansi.h>

void create()
{
	set_name("������ҩ",({"drug"}));
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("unit","��");
	    set("base_unit","��");
	    set("base_weight",30);
	    set("material","herb");
		set("long","��ԭ��������Ϊ�ټ���ҽ������ҩ�(ҩЧ��1500)");

		set("desc_ext","��������(use)");	// annie. 
	    
	    set("usage_type","pill");
	    set("heal_type","sen/1500");
	    set("type","cure");
	    set("base_value",0);
	    set("effect",1500);
	    set("field","sen");
	    set("volumn",5);
	}
	set_amount(5);
}

