
inherit MEDICINE;
#include <ansi.h>

void create()
{
	set_name("�����",({"hupodiao", "herb"}));
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long","һ�ֲ�̫������ҩ�ݣ����ҩ���ķ����������ⶾ��\n");
	    set("unit","��");
	    set("base_unit","��");
	    set("base_weight",30);
	    
	    set("base_value",0);
	    set("usage_type","herb");	
	    
	    set("material","herb");
	    set("level",50);
	    set("effect",1000);
	    set("type","depoisonx");
	    set("volumn",1);
	}
	set_amount(1);
}

