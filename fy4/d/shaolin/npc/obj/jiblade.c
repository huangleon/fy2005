// blade.c

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("�䵶", ({ "jieblade" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 500);
		set("material", "iron");
		set("long", "����һ�ѳ������õĽ䵶�����й���ܶۡ�\n");
		set("wield_msg", "$N���һ�ѳ������õ�$n�������С�\n");
		set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
	}
	init_blade(5);
}
