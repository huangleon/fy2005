
#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
	set_name("������" , ({ "staff" }) );
	set_weight(80000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ���ִ��ֳ��ľ����ȣ�����������������\n");
        set("value", 600000);
		set("rigidity", 50);
		set("material", "iron");
		set("wield_msg", "$N�ó�һ��������$n�������С�\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}

	::init_staff(25);
}
