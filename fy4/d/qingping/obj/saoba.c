
#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
	set_name("ɨ��" , ({ "saoba", "ɨ��" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�ƾɵ�ɨ�ѡ�\n");
		set("value", 10);
		set("rigidity", 5);
		set("material", "wood");
		set("wield_msg", "$N�ó�һ���ƾɵ�ľ$n�������С�\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}

	init_staff(5);
}
