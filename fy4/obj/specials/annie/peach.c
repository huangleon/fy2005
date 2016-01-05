#include <weapon.h>
#include <ansi.h>
inherit HAMMER;
inherit F_FOOD;

void create()
{
	set_name(HIR"Ѫ¶���"NOR, ({ "peach" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���ʺ����ҡ�\n");
		set("value", 0);
		set("wield_msg", "$N�ӻ����ͳ�һö$n��\n");
		set("unwield_msg", "$N�����е�$n�Żػ��С�\n");

		set("food_remaining", 1);
		set("food_supply", 0);
		set("material", "food");
            set("value", 0);
			set("no_get", 1);
			set("no_give", 1);
			set("no_drop", 1);
			set("no_sell", 1);
			set("no_burn", 1);
	}
	::init_hammer(1);
}

int finish_eat()
{
	object me;
	int gin, kee, sen;
	me = this_player();
	gin = (int) me->query("max_gin");
	kee = (int) me->query("max_kee");
	sen = (int) me->query("max_sen");
	message_vision( HIR "$N�������ɰױ�죬�����Ҫ�γ�Ѫ���������ĺ�ɫ��������ȥ����\n"NOR, me);
	me->set("eff_gin",gin);
	me->set("eff_kee",kee);
	me->set("eff_sen",sen);
	me->set("gin", gin);
	me->set("kee", kee);
	me->set("sen", sen);
	destruct(this_object());
    return 1;
}


