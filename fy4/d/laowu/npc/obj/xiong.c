// medicine.c

inherit MEDICINE;

void create()
{
	set_name("����",({"xiong"}));
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    	set("long","һС�����ƣ�������������200���������ˡ�\n");
	    	set("base_unit","��");
        	set("unit","��");
        	set("base_value", 1000);
        	set("base_weight",60);
        	set("field","sen");
	    	set("type","cure");
	    	set("effect",200);
	    	set("heal_type","sen/200");
	    	set("usage_type","herb");	
	    	set("volumn", 2);
	}
	set_amount(2);
}