inherit SKILL;
#include <ansi.h>
#include <combat.h>

void setup(){
	set("name","��ԯ����");
	set("type","axe");
	set("usage/axe",1);
	set("usage/parry",1);
	set("effective_level",200);
	set("practice_limit",100);
	set("difficulty",200);
	set("skill_class","knight");
	set("parry_msg", ({
			"���$nһ�С�����Ʈ翡����Ӷ�����$v����$N��$w��\n",
			"���$n����$vһ�֣�һ�С���ת���̡���б��$N��$w��\n",
			"���$n����$v�ն���ɣ�һ�С�����ü��������$N��$w��\n",
			"���$n����$v������ת��һ�С����񹤡�����ɨ$N��$w��\n",
	}) );

	set("unarmed_parry_msg", ({
			"$n���е�$v�趯��ɣ�һ�С������ӡ�����ס��$N�Ĺ��ơ�\n",
			"$n��Ӱ�ζ���һ�С�����񺿡�������$N�����̡�\n",
			"$n����һ����һ�С���ħͬ�塹�����$N�Ĺ��ơ�\n",
			"$n���е�$v���϶��£�һ�С���ڤ��Ӱ��������$N��Ҫ����\n",
	}) );
	action = ({
		(["action":
"$N����$w�趯���Ų�һ����һ�С��������ϡ�������$w�����ǰ�ֱ��$n��$l",
				"damage":               210,
				"dodge":                210,
				"parry":                240,
				"damage_type":  "����"
		]),
		(["action":
"$Nһ�С�������ء��羪��һƲ����$n���޾�Ѷ��һ˲��$w������$n����ǰ",
				"damage":               210,
				"dodge":                210,
				"parry":                240,
				"damage_type":  "����"
		]),
		(["action":
"$N����$w�����ݰ���ת��ͣ��һ�С����������ֱȡ$n�ĸ���Ҫ��",
				"damage":               200,
				"dodge":                140,
				"parry":                100,
				"damage_type":  "����"
		]),
		(["action":
"$N����һԾ������$wǣ���������������һ�С����°����������а���$n$l��ȥ",
				"damage":               150,
				"dodge":                100,
				"parry":                100,
				"damage_type":  "����"
		]),
		(["action":
"$N����$w�ݷ����������㣬һ�С��ط����򡹣�ͻȻ������һ�ɺ�����$N�ĸ���͸��",
				"damage":               250,
				"dodge":                210,
				"parry":                240,
				"damage_type":  "����"
		]),
		(["action":
"ͻȻ���ݷ�ռ䱻�Ϳհ㣬$N����$w����һ���̳���һʽ�������ס�ʹ$n����������",
				"damage":               210,
				"dodge":                210,
				"parry":                240,
				"damage_type":  "����"
		]),
	});
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
	object ob, snake;
	object weapon;

	weapon = me->query_temp("weapon");

	if( ANNIE_D->check_buff(me,"poison_spirit") ) {
		if( me->query_temp("max_snake") < me->query_temp("poison_spirit") ) {
			message_vision( HIG "$N"HIG"����"+ weapon->name()+ HIG "�ɳ�һ������\n"NOR, me, victim);
			snake = new("/obj/npc/poison_spirit.c");
			snake->move(environment(me));
			me->add_temp("max_snake",1);
			snake->invocation(me);
		}
	}

	if( random(damage_bonus) < 350 ) {
		return 0;
	}
	if( ob = victim->query_temp("weapon") ) {
		if( ob->query("skill_type") == "spear" ) {
			if( victim->query_skill_mapped("spear") == "xuezhan-spear" || victim->query_skill_mapped("spear") == "yue-spear" || victim->query_skill_mapped("spear") == "duanhun-spear" ) {
				if( me->query_skill("axe") + 50 > victim->query_skill("spear") ) {
					switch( random(3) ) {
						case 0:
							message_vision(HIR "\n���书·����ˣ�$Nռ�����Ϸ磡" NOR, me, victim);
							break;
						case 1:
							message_vision(HIR "\n$N����׾ٵ�����$n�Ŀ�϶֮�䣡" NOR, me, victim);
							break;
						case 2:
							message_vision(HIR "\n$N��ʽ�������磬$n��ʩչ�����ˣ�" NOR, me, victim);
							break;
					}
					return random(me->query_skill("axe")) * 2;
				}
			}
		}
	}
	return 0;
}

int help(object me)
{
	write(@HELP
��ʹ��Ѫսǹ������ƽǹ�����ϻ�ǹ���мܵĶ����ж����˺���

L40 �����񹤡���guifushengong����������
������������æ��2�֣�
���⹥����=��ԯ�����ȼ�

L160��������������jiuqipoxiao��
������������æ��3�֣�ÿ30���ʹ��һ�Ρ�
���⹥����=��ԯ�����ȼ�
HELP
	);
	return 1;
}
