// blade.c
#include <weapon.h>
inherit DAGGER;
void create()
{
	set_name("Ӣ��ɳС��", ({ "small blade" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 500);
		set("material", "iron");
		set("long", "����һ���ܷ�����С���������ر��Ư����\n");
		set("wield_msg", "$N���һ�����λε�$n�������С�\n");
		set("unequip_msg", "$N�����е�$n����ѥ���\n");
	}
	::init_dagger(10);
}
