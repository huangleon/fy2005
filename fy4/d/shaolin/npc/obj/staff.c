
#include <ansi.h>
#include <weapon.h>
inherit STAFF;
void create()
{
	set_name("�������" , ({ "lightstaff", "staff" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ���ܲ����۵����ȣ����顰��⡱\n");
		set("value", 600);
		set("material", "iron");
		set("wield_msg", "$N�ó�һ���ںڵ�$n�������С�\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}

	init_staff(23);
}
