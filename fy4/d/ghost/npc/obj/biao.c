// dart.c

#include <weapon.h>
inherit THROWING;

void create()
{
	set_name("ͭǮ��", ({ "biao" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"ͭǮ����һ��ʮ�ֳ����İ�����\n");
		set("unit", "Щ");
		set("base_unit", "��");
		set("base_weight", 10);
		set("base_value", 0);
		set("volumn",20);
	}
	set_amount(40);
	::init_throwing(20);
}
