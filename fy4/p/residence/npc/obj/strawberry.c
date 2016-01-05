#include <ansi.h>
#include <weapon.h>

inherit THROWING;
inherit F_FOOD;

void create()
{
	set_name(HIR"��ݮ"NOR, ({ "strawberry" }) );
	set_weight(35);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ����������Ĳ�ݮ��\n");
		set("unit", "��");
		set("base_unit","��");
		set("base_value", 30);
		set("food_remaining", 4);
		set("food_supply", 80);
		set("wield_msg", "$N��$n�������е�������\n");
		set("material", "bone");
	}
	set_amount(1);
	::init_throwing(4);
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
	string tmp1;
	victim->add_temp("annie/strawberry", 1);
	if (victim->query_temp("annie/strawberry") < 4)
		victim->set_temp("body_print", gender_pronoun(victim->query("gender"))+"���Ϻ��ż���ճ�����Ĳ�ݮ֭��");
	else
		victim->set_temp("body_print", gender_pronoun(victim->query("gender"))+"���Ϻ�����ճ�����Ĳ�ݮ֭��");
	return "ֻ��ž�һ������ݮ�����ճ��$n���ϣ�֭Һ�Ľ���\n";
}

/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/
