// medicine.c
inherit MEDICINE;

void create()
{
	set_name("��Ƥ��ҩ",({"gaoyao"}));
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long","һ�鹷Ƥ��ҩ����������������������40���������ˡ�\n");
	    set("unit","��");
	    set("base_unit","��");
	    set("base_weight",60);
	    set("type","cure");
	    set("base_value",20);
	    set("field","sen");
	    set("effect",40);
	    set("heal_type","sen/40");
	    set("usage_type","piece");	
	    set("volumn",5);
	}
	set_amount(5);
}


