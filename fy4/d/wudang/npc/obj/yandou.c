
#include <weapon.h>

inherit HAMMER;

void create()
{
	set_name("�̶�", ({ "yandou" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "֧");
		set("long", "һ֧�����ĺ��̶���\n");
		set("value", 200);
		set("material", "iron");
		set("rigidity", 10);
		set("wield_msg", "$N�ó�һ֧$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���¡�\n");
	}
	::init_hammer(3);
}
