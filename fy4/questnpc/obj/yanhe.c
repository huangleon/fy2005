#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW"���̺�"NOR, ({ "yanhe" }) );
	set_weight(200);
	set_max_encumbrance(4000);
//	set("no_get", 1);
//	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�����ı��̺�\n");
		set("value", 150);
	}
}

int is_container() { return 1; }
