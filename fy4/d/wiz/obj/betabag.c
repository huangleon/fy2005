
inherit ITEM;
#include <ansi.h>

void create()
{
    set_name("����������", ({ "bottomless box","box"}) );
    set_weight(20000);
	set_max_encumbrance(4000000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        set("long", "һ�����󼫴�����ӡ�\n");
		set("value", 100);
	}
	::init_item();
}

int is_container() { return 1; }


