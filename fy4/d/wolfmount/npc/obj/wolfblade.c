#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("��ͷ��", ({ "wolf blade", "blade" }) );
	set("unit", "��");
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("long", "����һ����ɽ���ӳ��õĵ������кܷ�����\n");
		set("wield_msg", "$N����$n�������\n");
		set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
		set("value", 4);
		set("material", "bone");
	}
	::init_blade(15);
}
