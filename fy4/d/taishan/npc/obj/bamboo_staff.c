#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
	set_name(HIG"������"NOR , ({ "bamboo staff", "staff" }) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�������͵������ȡ�\n");
		set("value", 2000);
		set("rigidity", 200);
		set("material", "iron");
		set("wield_msg", "$N�ó�һ�������͵�$n�������С�\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}

	::init_staff(10);
}
