#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIG"�������"NOR, ({"jade", "fei cui", "green stone"}));
    	set_weight(200);
    	if( clonep() )
            set_default_object(__FILE__);
    	else {
        	set("unit", "��");
		set("long", "
����һ����̵���䡣��ɽ��֮���������֮�������ɵ����������Σ�
�·������������\n");
        	set("value", 200);
		set("imbue", 1);
		set("lore", 1);
    }
	::init_item();
}


