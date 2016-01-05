#include <ansi.h>
#include <weapon.h>

inherit THROWING;
inherit F_FOOD;

void create()
{
	set_name(YEL"�޻���"NOR, ({ "fig" }) );
	set_weight(35);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�����һ��ͳ�ˮ���޻�����\n");
		set("unit", "��");
		set("base_unit","��");
		set("base_value", 30);
		set("food_remaining", 2);
		set("food_supply", 20);
		set("wield_msg", "$N��$n�������е�������\n");
		set("material", "bone");
		set("volumn",10);
	}
	set_amount(10);
	::init_throwing(1);
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	string tmp1;
	victim->add_temp("annie/fig", 1);
	if (victim->query_temp("annie/fig") < 4)
		victim->set_temp("body_print", gender_pronoun(victim->query("gender"))+"���Ϻ��ż���ճ�������޻���֭��");
	else
		victim->set_temp("body_print", gender_pronoun(victim->query("gender"))+"���Ϻ�����ճ�������޻���֭��");
	return "ֻ��ž�һ�����޻��������ճ��$n���ϣ�֭Һ�Ľ���\n";
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
