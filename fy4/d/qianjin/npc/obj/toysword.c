
#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
	set_name( HIR "����һ��ľͷ������Ƭ" NOR, ({ "rustysword" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�Ѱ���һ��ľͷ������Ƭ������������ߣ�\n");
		set("value", 400);
		set("material", "steel");
		set("wield_msg", "$N�ѱ�������$n�γ��������С�\n");
		set("unwield_msg", "$N�����е�$n�������䡣\n");
/*		set("no_drop",1);
		set("no_get",1);
		set("no_sell",1);*/
	}
	init_sword(25);
}

/*void owner_is_killed(object killer)
{
	message_vision("\n\n$N�����ڵ��ϵ�"+HIR"����һ��ľͷ������Ƭ " NOR +"�������������زص����У�\n\n",killer);
	this_object()->move(killer);
}*/