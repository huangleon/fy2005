inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("����", ({ "flag"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ���ߵ�С���죬����д�š���ԭ�����֡�\n");
		set("value", 1);
	}
}



