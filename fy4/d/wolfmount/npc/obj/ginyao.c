// medicine.c

inherit MEDICINE;
#include <ansi.h>
int eat_fun();

void create()
{
    	set_name(RED"�Ż���¶��"NOR,({"yuluwan","wan"}));
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    	set("long",
"��˵��ҩ���ǲɼ�ÿ�ճ���ʱ�����ʻ������ϵ�¶ˮ���ƶ��ɣ�������
ɫ������Ϯ�ˣ��������񣬹�Ч������������������2500�㾫�����ˡ�\n");
	    	set("base_unit","��");
	    	set("unit","��");
	    	set("base_weight",60);
        	set("base_value", 20000);
	    	set("type","cure");
	    	set("field","gin");
	    	set("effect",2500);
	    	set("heal_type","gin/2500");
	    	set("usage_type","pill");	
	    	set("use_func",(: eat_fun() :));
	    	set("volumn", 1);
	}
	set_amount(1);
}


int 	eat_fun() {
    	message_vision("$NС����������һ�žŻ���¶�裬������ˬ�ޱȣ�����Ȼһ��\n",this_player());
	return 1;
}

