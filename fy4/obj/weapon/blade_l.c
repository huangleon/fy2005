// blade.c

#include <weapon.h>

inherit BLADE;

void create()
{
    	set_name("�ٱٱ���", ({ "blade" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        	set("value", 1);
		set("material", "iron");
        	set("long", "����һ��ɳ���ϳ��õ�ս����\n");
		set("wield_msg", "$N���һ�����λε�$n�������С�\n");
		set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
	}
    	init_blade(4);
}
