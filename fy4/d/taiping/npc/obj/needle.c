#include <weapon.h>

inherit THROWING;
#include <ansi.h>
void create()
{
	set_name("��Ӱ����", ({ "needle", "magic needle" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"��ǿ��ɱ�����ľ޶��ޱȵ���Ӱ���롣\n");
		set("unit", "��");
		set("base_unit", "֧");
		set("base_weight", 1);
		set("base_value", 1);
		set("volumn",150);
	}
	set_amount(150);
	init_throwing(55);
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	victim->apply_condition("no_shadow",random(10)+10);
	message_vision("$N������Ӱ�����ϵĶ���\n", victim);
}

