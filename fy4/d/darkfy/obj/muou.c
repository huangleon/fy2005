
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("��Ŀ�հ׵�ľ��", ({ "muxiang" , "ľ��"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "��Ŀ�հ׵�ľ��\n");
		set("value", 10);
	}
}



