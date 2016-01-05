// thin_sword.c

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("ϸ��", ({ "thin sword", "sword" }) );
	set_weight(1400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1);
		set("material", "steel");
		set("long", "����һ����ϸ�ֳ��Ľ�����ƮƮ������Ů���Ӽҵ����⡣\n");
		set("wield_msg", "$N���һ�ѽ���ϸ���Ľ����������С�\n");
		set("unequip_msg", "$N�������е�$n��\n");
		set("weapon_prop/courage", -4);
	}
	::init_sword(20);
}
