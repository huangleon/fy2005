#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(MAG"��ڤ�Ͼ�"NOR, ({"amethist", "stone", "purple stone"}));
    	set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            	set("unit", "��");
				set("long", "һ����ɫ�ľ�ʯ����ϸ��ʱ����˿˿���ĵ��Ϲ�������������\n"); 
            	set("value", 200);
				set("imbue", 1);
        }
	::init_item();
}


