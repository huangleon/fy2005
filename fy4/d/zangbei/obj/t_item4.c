#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
	set_name("����" , ({ "scepter"}) );
	set_weight(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "���Ƕ����հͻ����ǰ����ʱ�������õĶ��ȣ�����ޱȡ�\n");
		set("value", 0);
		set("rigidity", 50);
		set("material", "iron");
		set("wield_msg", "$N�ó�һ���ƲӲӵ�$n�������С�\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}

	::init_staff(7);
}


