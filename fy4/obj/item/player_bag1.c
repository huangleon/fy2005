inherit ITEM;
#include <ansi.h>

void create()
{
    set_name("��˿��", ({ "small bag","bag"}) );
    set_weight(2000);
	set_max_encumbrance(40000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        set("long", "һ��СС�����ң��߽������˳��á�\n");
		set("value", 2000);
	}
	::init_item();
}

int is_container() { return 1; }


