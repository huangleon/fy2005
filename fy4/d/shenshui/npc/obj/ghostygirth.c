// icy_girth.c

#include <ansi.h>
#include <armor.h>

inherit WAIST;

void create()
{
	set_name(  "��Ӱ���" , ({ "ghosty girth", "girth" }) );
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 7000);
		set("material", "cloth");
	}
	::init_waist();
}
