// fork.c

#include <weapon.h>
inherit FORK;

void create()
{
	set_name("�ֲ�", ({ "fork" }) );
	set_weight(30000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1);
		set("long", "����һ�ѿ����൱��ͨ�ĸֲ�");
                set("material", "steel");
                set("wield_msg", "$N��$n�������������С�\n");
		set("unwield_msg", "$N�ɿ������е�$n��\n");
	}
	::init_fork(30);
}

