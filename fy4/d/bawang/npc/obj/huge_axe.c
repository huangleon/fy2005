
#include <ansi.h>
#include <weapon.h>
inherit AXE;
void create()
{
	set_name(HIC"��ɽ��"NOR, ({ "huge axe", "axe" }) );
	set_weight(50000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�ѳ��ִ�С�İ師��\n");
		set("value", 60);
		set("material", "iron");
		set("wield_msg", "$N�ó�һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���ڼ��ϡ�\n");
	}

	::init_axe(15);
}
