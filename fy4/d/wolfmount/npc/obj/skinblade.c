// Tie@fengyun
#include <weapon.h>

inherit DAGGER;

void create()
{
    set_name("��ƤС��", ({ "skin dagger","dagger" }) );
        set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        set("long", "����һ��Ƥ���õ�С����\n");
        set("value", 300);
		set("material", "steel");
        set("wield_msg", "$N����һ����һ��$n��Ȼ�������С�\n");
        set("unwield_msg", "$NС���������е�$n����Ƥ�ʡ�\n");
	}
    ::init_dagger(10);
}
