#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
	set_name("ɱ����" , ({ "shawei bang", "bang" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ���ִ��ֳ���ľ��ɱ��������ͷ��ɫ��\n");
		set("value", 620);
		set("material", "wood");
		set("wield_msg", "$N�ó�һ����ͷ��ɫ��$n�������С�\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}

	::init_staff(13);
}
