
#include <ansi.h>
#include <weapon.h>
inherit AXE;
void create()
{
	set_name("��⸫ͷ" , ({ "lightaxe", "axe" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�Ѻܲ����۵ĸ�ͷ�����顰��⡱\n");
		set("value", 600);
		set("material", "iron");
		set("wield_msg", "$N�ó�һ��ѩ����$n�������С�\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}

	init_axe(43);
}
