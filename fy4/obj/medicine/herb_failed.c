inherit MEDICINE;
#include <ansi.h>

void create()
{
	set_name("���õ�ҩ��",({"decayed herb", "herb"}));
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long","һ����ˮ�н��ݵ�̫���������õ�ҩ�ݣ��Ѿ�������������ʲô�����ˡ�\n");
	    set("unit","��");
	    set("base_unit","��");
	    set("base_weight",30);
	    set("type","medicine");
	    
	    set("base_value",0);
	    set("heal_type","kee/1");
	    set("usage_type","herb");	
	    
	    set("material","herb");
	    set("level",0);
	    set("effect",10);
	    set("field","kee");
	    set("volumn",1);
	}
	set_amount(1);
}

