inherit MEDICINE;
#include <ansi.h>

void create()
{
	set_name("������",({"jinyinhua", "herb"}));
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long","һ�ֲ�̫������ҩ�ݣ����ҩ���ķ����������ⶾ��\n");
	    set("unit","��");
	    set("base_unit","��");
	    set("base_weight",30);
	    
	    set("base_value",2000);
	    set("usage_type","herb");	
	    
	    set("material","herb");
	    set("level",50);
	    set("effect",1000);
	    set("type","depoison");
	    set("volumn",10);
	}
	set_amount(10);
}

