#include <weapon.h>
inherit THROWING;
void create()
{
    set_name("�仨", ({ "drop flower", "flower" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("unit", "��");
        set("long", "һ����δ��л���仨��ɢ����һ˿������������\n");
        set("base_unit", "��");
		set("base_weight", 1);
		set("base_value", 1);
	}
	set_amount(1);
	::init_throwing(2);
}
