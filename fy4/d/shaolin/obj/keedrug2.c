// medicine.c

inherit MEDICINE;

void create()
{
	set_name("����ɢ",({"huitiansan"}));
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long",
     	        "һ�豻��Ϊ����֮���Ļ���ɢ��������������1000������ ��\n");
	    	set("base_unit","��");
        	set("unit","��");
        	set("base_value", 0);
        	set("base_weight",60);
	    	set("type","cure");
	    	set("heal_type","kee/1000");
	    	set("usage_type","herb");	
	}
	set_amount(1);
}
