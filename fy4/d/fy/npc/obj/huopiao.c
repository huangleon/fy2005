inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("��Ʊ", ({ "huopiao"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ���ʨ�ھֵĻ�Ʊ��\n");
		set("value", 100);
	}
}



