// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ITEM;


void create(){
	set_name(HIG"���̲�"NOR, ({"grass" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ��������ε�С�ݡ�\n");
		set("unit", "��");
		set("real_flower",3);
	}
    ::init_item();
}

