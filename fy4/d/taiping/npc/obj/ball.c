#include <weapon.h>
inherit THROWING;

void create()
{
	set_name("��������", ({ "ball"}) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"С������Ĳ������ӣ�������ɫʮ��Ư����\n");
		set("unit", "��");
		set("base_unit", "��");
		set("base_weight", 10);
		set("base_value", 10);
	}
	set_amount(1);
	init_throwing(10);
}
