#include <weapon.h>
inherit STAFF;

void create()
{
	set_name("ϸ���", ({ "bamboo", "zhu gan" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ��ͨ����̵���͡�\n");
		set("value", 100);
		set("rigidity", 5);
        set("material", "wood");
        set("wield_msg", "$N�ó�һ��ͨ����̵�$n�������С�\n");
        set("unwield_msg", "$N�������е�$n��\n");
    }
    ::init_staff(5);
}



