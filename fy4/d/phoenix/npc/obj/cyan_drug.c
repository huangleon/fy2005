inherit MEDICINE;
#include <ansi.h>

void create()
{
	set_name("���ٻ���ɢ",({"demon drug","drug"}));
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("unit","��");
	    set("base_unit","��");
	    set("base_weight",30);
	    set("material","herb");
	    set("no_drop", 1);
		set("long","����ħ�����Ƶ���ҩ֮һ��������Ѫ���������ޱȡ�
��ҩЧ������������");

		set("desc_ext","��������(use)");	// annie. 
	    
	    set("usage_type","pill");
	    set("heal_type","kee/4000");
	    set("type","cure");
	    set("base_value",0);
	    set("effect",4000);
	    set("field","kee");
	    set("volumn",10);
	}
	set_amount(10);
}

