// blade.c

#include <weapon.h>

inherit BLADE;

void create()
{
    set_name("�嵶", ({ "blade" }) );
	set_weight(40000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        set("value", 5000);
		set("material", "iron");
        set("long", "����һ�ѳ�͢����ר�õ��嵶��������Լ�����߽��ء�\n");
		set("wield_msg", "$N���һ�����λε�$n�������С�\n");
		set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
	}
    init_blade(45);
}
