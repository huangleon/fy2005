
#include <ansi.h>
#include <weapon.h>
inherit SPEAR;
void create()
{
	set_name("���ľǹ" , ({ "lightspear", "spear" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ���ܲ����۵�ľǹ�����顰��⡱\n");
		set("value", 600);
		set("material", "wood");
		set("wield_msg", "$N�ó�һ���ںڵ�$n�������С�\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}

	init_spear(33);
}
