#include <armor.h>
inherit HEAD;

void create()
{
	set_name("���Ķ���", ({ "hat" }) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","���Ķ��ң����غܿ��\n");
		set("value", 100);
		set("material", "wood");
		set("armor_prop/armor", 5);
	}
	::init_head();
}


