inherit ITEM;
#include <ansi.h>

void create()
{
    set_name("����", ({ "big bag","bag"}) );
    set_weight(2000);
	set_max_encumbrance(160000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        set("long", "һ������ȥ��������ң����Է�ˮ���߽������˳��á�\n");
		set("value", 50000);
		set("waterproof",1);
	}
	::init_item();
}

int is_container() { return 1; }


