inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("��ѩ�ż�", ({ "letter"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ������д�����񺭵��ż���\n");
		set("value", 1000);
	}
}



