
inherit ITEM;
#include <ansi.h>

void create()
{
    set_name(HIW"�׹�"NOR, ({ "bone" , "�׹�"}) );
    set_weight(50000+random(60000));
	set_max_encumbrance(40);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        set("long", "һ�߲�֪��С���ﻹ���˵�ɭɭ�׹ǡ�\n");
		set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }


