// dart.c

#include <weapon.h>
inherit THROWING;

void create()
{
	set_name("�ߴ糤�Ķ̽�", ({ "short sword" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"��������Ķ̽��������ߴ磬�������硣\n");
		set("unit", "��");
		set("base_unit", "��");
		set("base_weight", 40);
		set("base_value", 5);
	}
	set_amount(1);
	::init_throwing(20);
}
