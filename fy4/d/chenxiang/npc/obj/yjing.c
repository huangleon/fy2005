
#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
	set_name("������Զ��" , ({ "wyj", "telescope" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ����ͭ��ĥ�ĵ�����Զ����\n");
		set("value", 6200);
		set("wield_msg", "$N�ó�һ����ͭ��ĥ��$n�������С�\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}

	::init_staff(15);
}
