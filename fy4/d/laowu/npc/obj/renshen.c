// medicine.c

inherit MEDICINE;

void create()
{
	set_name("Ұ�˲�",({"renshen"}));
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long",
     	        "һ��Ұ�˲Σ�������������200�㾫�����ˡ�\n");
	    	set("unit","��");
        	set("base_unit","��");
        	set("base_value", 1000);
        	set("base_weight",60);
	    	set("type","cure");
	    	set("field","gin");
	    	set("effect",200);
	    	set("heal_type","gin/200");
	    	set("usage_type","herb");	
	    	set("volumn", 2);
	}
	set_amount(2);
}
