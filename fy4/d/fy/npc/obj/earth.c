#include <ansi.h>
inherit ITEM;
void create()
{
    	set_name(YEL"����ճ��"NOR, ({ "clay"}) );
    	set_weight(500);
    	set_max_encumbrance(1000);
		set("skull_make",1);
    	if( clonep() )
    		set_default_object(__FILE__);
    	else {
        	set("unit", "��");
        	set("long", "�����ճ���������������Ϻò��ϡ�\n");
        	set("value", 200000);
    	}
    	::init_item();
}

