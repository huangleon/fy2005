#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("�����", ({ "chopstick" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("base_unit", "֦");
		set("long", "һ�ԳԷ��õ�����ӡ�\n");
		set("base_weight", 40);
		set("value", 5);
		set("volumn",2);
	}
	set_amount(2);
	::init_throwing(2);
}
