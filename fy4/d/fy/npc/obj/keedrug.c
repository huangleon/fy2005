// medicine.c

inherit MEDICINE;


void create()
{
	set_name("���ϰ�ҩ",({"baiyao"}));
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long","һ�����ϰ�ҩ��������������100������ ��\n");
	    set("unit","��");
	    set("base_unit","��");
	    set("base_value", 300);
	    set("base_weight",60);
	    set("field","kee");
	    set("type","cure");
	    set("effect",100);
	    set("heal_type","kee/100");
	    set("usage_type","pill");	
	    set("volumn",5);
	}
	set_amount(5);
}

