// icy_band.c

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name(  "��ѩ���ƽ�" , ({ "icy ribbon", "ribbon" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 100);
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("male_only", 1);
	}
	::init_head();
}
