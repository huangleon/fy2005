inherit MEDICINE;
#include <ansi.h>

void create()
{
	set_name("��ҩ",({"drug"}));
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long","�׻�˵����ѧ���ˣ���ѧ�����ڽ��������ߣ�Ҫ��������������ħͷ���ⲻ��Ҫ
�Ŀ��������ܵ��ˣ��ã�����һ���Լ����������մ���ع������϶��е�С
�ˣ����е��˿�����������������������ƣ���������ˣ��ٷֱ����𣩣�����
Ҫ����ҩ�����һ���ϺõĽ�ҩ������������Ѫ�����ˣ�һ�����ƣ������㡣
�����ʽΪ����塡�����磬������������߾����ܵ����ˣ����Ե����ƶ���
������������򼸺й�Ƥ��ҩ�����ߵ��������ϲ��ķ�ҶȪȥϴ�������\n");
	    set("unit","��");
	    set("base_unit","��");
	    set("base_weight",30);
	    set("material","herb");
	    set("no_drop", 1);

		set("desc_ext","��������(use drug)");	// annie. 
	    
	    set("usage_type","pill");
	    set("heal_type","kee/100");
	    set("type","cure");
	    set("base_value",0);
	    set("effect",100);
	    set("field","kee");
	    set("volumn",100);
	}
	set_amount(100);
}

