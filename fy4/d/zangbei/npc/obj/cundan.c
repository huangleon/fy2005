
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
		set("long", "һ���Ϲ�Ǯׯ�Ĵ浥����ֵ���ǡ�\n");
		set("value", 1);
		set("guizi",1);
	}
}



