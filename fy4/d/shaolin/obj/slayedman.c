inherit ITEM;
#include <ansi.h>

void create()
{
    	set_name("׳����е�ʬ��", ({ "corpse"}) );
    	set_weight(800000);
    	set_max_encumbrance(400000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        set("long", "һ�����ֺ��е�ʬ�壬��������˲��á���\n");
		set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }
