#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("�׹���Ҷ", ({"ginkgo leaf", "baiguo leaf"}) );
	set_weight(5);
	if( clonep() )
  	  set_default_object(__FILE__);
	else {
	    set("unit", "��");
	    set("long", "һ������ɫ������ҶƬ��\n");
	    set("value", 1);
	}
	::init_item();
}



