// ; annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <weapon.h>
#include <combat.h>
inherit BLADE;

void create() {
	set_name(CYN"����"NOR, ({ "dollar" }) );
	set_weight(40);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 0);
		set("material", "paper");
		set("long", "����һ�Ż������̵�ֽ�ţ�ֽ��ӡ�ź�ɺ��������ͷ��д��һ�����������֣���ôҲ����ѵ���\n");
		set("wield_msg", "$N���һ��$n��ӭ�ŷ����һ�Σ��������졣\n");
		set("unequip_msg", "$N��һ��$n���������\n");
		set("real_usdollar",random(2));	// 1/2����ٳ�,escape
	}
	::init_blade(1);
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	victim->set_temp("counter_action",1);
	victim->set_temp("counter_msg",CYN"$N���������������������ᣬһ�ߴ�е����ҵģ��ҵģ�\n"NOR);
	// snicker
	return 0;
}
