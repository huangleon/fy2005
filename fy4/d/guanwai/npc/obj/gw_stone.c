
#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("�����", ({ "needle" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"Դ�����ŵİ�����\n");
		set("unit", "��");
		set("base_unit", "��");
		set("base_weight", 10);
        	set("base_value", 500);
        	set("volumn",200);
	}
	set_amount(200);
	::init_throwing(20);
}
