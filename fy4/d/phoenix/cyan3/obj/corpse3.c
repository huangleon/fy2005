#include <ansi.h>
inherit ITEM;
void create()
{
	set_name("����", ({ "katana"}) );
	set("no_get", 1);
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ���Ϻõ������������εض���������ɵ������ϡ�\n\n");
		set("unit", "��");
		set("value", 0);
	}
	::init_item();
}


