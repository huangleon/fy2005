// medicine.c

inherit MEDICINE;
#include <ansi.h>
int eat_fun();

void create()
{
    	set_name(GRN"���令�ĵ�"NOR,({"cuixiudan","dan"}));
        if( clonep() )
                set_default_object(__FILE__);
	else {
		set("long",
"��˵���ǡ���ɽ���䡱�Ķ�����ҩ������ʮ������ҩ������ʮ������ɣ�
ɫ����̣��������������޷���������������2��0�����������ˡ���\n");
	    	set("base_unit","��");
	    	set("unit","��");
	    	set("base_weight",60);
        	set("base_value", 20000);
	    	set("type","cure");
				set("field","sen");	 
				set("effect",2500);   	
	    	set("heal_type","sen/2500");
	    	set("usage_type","pill");	
	    	set("use_func",(: eat_fun() :));
	    	set("volumn", 1);
	}
	set_amount(1);
}



int 	eat_fun() {
    	message_vision("$N����һ�����令�ĵ���һ��ů����ס�����Ϣ��Ȼ��ͨ����������\n",this_player());
	return 1;
}
