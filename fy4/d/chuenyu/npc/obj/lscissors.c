// scissors.c

#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
	set_name( "����", ({ "scissors" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�ѳ���������԰��������\n");
		set("value", 100);
		set("material", "iron");
		set("wield_msg", "$N�ó�һ��$n�������С�\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}

	::init_sword(15);
}
