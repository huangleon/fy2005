#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("����", ({ "tooth"}) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ���˵ľʳݣ���Ƕ��һ��СС��̴ľ���С�\n");
		set("value", 1);
	}
}
