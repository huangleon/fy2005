#include <weapon.h>
inherit THROWING;

void create()
{
    set_name("�廨��", ({ "needle" , "skirt needle" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ��ϸϸ�����롣\n");
        set("base_unit", "��");
		set("base_weight", 1);
		set("base_value", 3);
	}
    set_amount(1);
    ::init_throwing(18);
}



