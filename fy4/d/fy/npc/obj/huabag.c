
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("���۴�", ({ "huabag" , "���۴�"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "��ζ����Ļ��۴���\n");
		set("value", 1000);
	}
	::init_item();
}



