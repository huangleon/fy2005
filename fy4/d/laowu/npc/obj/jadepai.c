
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("��ɲ��" , ({ "luosha" , "pai"}) );
	set_weight(5);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ����ɲ��\n");
		set("value", 10000);
	}
}



