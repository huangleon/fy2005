
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("�ܼ�", ({ "plan" }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ���ܼ�������д�ţ���ʱ�������������ˡ�\n");
		set("value", 1);
	}
}



