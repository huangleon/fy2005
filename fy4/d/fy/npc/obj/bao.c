
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("�ٻ���", ({ "bao" , "�ٻ���"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "��ζ������ٻ���\n");
		set("value", 1000);
	}
	::init_item();
}



