#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("�����µ���", ({ "diqi"}) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�������µĵ�����ֽɫ�Ѿ������ˡ�\n");
		set("value", 1);
	}
}
