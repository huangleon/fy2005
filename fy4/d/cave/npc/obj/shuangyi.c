// tea_leaf.c

#include <weapon.h>
inherit THROWING;
#include <ansi.h>


void create()
{
	set_name(HIC"˫��ˮ��"NOR, ({ "crystal sand", "magic crystal", "crystal" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"һС����������ɫ�ʵ�ˮ����\n");
		set("unit", "��");
	        set("base_value", 5000);
		set("base_unit", "��");
		set("base_weight", 1);
		set("volumn",50);
	}
	set_amount(50);
	::init_throwing(10);
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
	victim->apply_condition("no_shadow",random(10)+10);
	message_vision("$N����˫��ˮ���ϵĶ���\n", victim);
}

