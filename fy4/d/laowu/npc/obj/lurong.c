// medicine.c

inherit MEDICINE;

void create()
{
	set_name("¹��",({"lurong"}));
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    	set("long","һ��¹�ף�������������300�����ˡ�\n");
        	set("unit","��");
        	set("base_unit","��");
        	set("base_value", 1000);
        	set("base_weight",60);
	    	set("type","cure");
	    	set("field","kee");
	    	set("effect",300);
	    	set("heal_type","kee/300");
	    	set("usage_type","herb");	
	    	set("volumn", 2);
	}
	set_amount(2);
}