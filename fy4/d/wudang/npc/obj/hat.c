// hat.c
#include <armor.h>
inherit HEAD;

void create()
{
	set_name("��ɫ����", ({ "hat" }) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 100);
		set("long", "һ����ɫ����\n");
		set("material", "cloth");
		set("armor_prop/armor", 2);
	}
	::init_head();
}
