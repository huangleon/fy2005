
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("��Ʊ", ({ "cundan"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�Ŵ��ڻ�̫��ĳ��Ǯׯ�Ĵ浥��\n");
		set("value", 1);
	}
}



