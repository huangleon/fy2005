// medicine.c

inherit MEDICINE;
#include <ansi.h>

int eat_fun();

void create()
{
    	set_name(WHT"�����ܵ���"NOR,({"baiyunwan","wan"}));
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    	set("long", "������ʢ��������ʥҩ�����۸񰺹���ͨ��ֻ��������̾��������������5000�����ˡ�\n");
	    	set("base_unit","��");
	    	set("unit","��");
	    	set("base_weight",60);
        	set("base_value", 20000);
	    	set("type","cure");
	    	set("field","kee");
	    	set("effect",5000);
	    	set("heal_type","kee/5000");
	    	set("usage_type","pill");	
	    	set("use_func",(: eat_fun() :));
	    	set("volumn", 1);
	}
	set_amount(1);
}



int 	eat_fun() {
    	message_vision("$N����һ�Ű����ܵ��裬�˿����������������������\n",this_player());
	return 1;
}