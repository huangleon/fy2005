// annie 07.2003
// dancing_faery@hotmail.com
// �������� 
// ����(perform mingyue.....*escape)
// ��ʧ�ֵ�1HIT����������ս��������

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra, bonus, level, duration;
	object weapon, *pros;

	extra = me->query_skill("chillblade",1);
	if( me->query("class") != "moon" && userp(me) ) {
		return notify_fail("ֻ����¹����˲���ʩչ�����¡���\n");
	}
	if( me->query("gender") == "Ů��" && userp(me) ) {
		return notify_fail("Ů�Ӳ��ʺ�ʩչ�����߾��ġ����¡�һʽ��\n");
	}
	if( extra < 190 && userp(me) ) {
		return notify_fail("�����¡���Ҫ����190���ı����߾���\n");
	}
	if( me->query("max_mana") < 1000 ) {
		return notify_fail("�����¡���Ҫ����1000�����Ϊ������\n");
	}
	if( userp(me) && !me->query("annie/chillblade_mingyue") ) {
		return notify_fail("�����¡���Ҫ�ȴӾ������������ʹ�á�\n");
	}
	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail("�����¡�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	}
/*
����?�ϲ�		chillblade_mingyue_1		L150	1M
����?�в�		chillblade_mingyue_2		L150	2.4M
����?�²�		chillblade_mingyue_3		L150	4M
*/
	level = me->query("annie/chillblade_mingyue");
	if( !userp(me) ) {
		level = 5;
	}
	if( userp(me) ) {
		if( level >= 3 ) {
			duration = me->query("timer/mingyue")+180-time();
			if( duration > 0 ) {
				return notify_fail("�����¡�һʽ����ȴ�"+ duration+"���ӡ�\n");
			}
		} else {
			duration = me->query("timer/mingyue")+240-time();
			if( duration > 0 ) {
				return notify_fail("�����¡�һʽ����ȴ�"+ duration+"���ӡ�\n");
			}
		}
	} else if( me->query("timer/mingyue") + 180 > time() ) {
		// 3min
		return notify_fail("�����¡�һʽ������֮��ֻ��ʹ��һ�Ρ�\n");
	}
	if( userp(me) && target->query_temp("annie/damaged_by_mingyue") ) {
		return notify_fail("��ʽ����ɱ��ֻ��һ�Σ�һ��ʧ�֣������ٷ���\n");
	}
	if( userp(me) && me->query("mana") < 1000 ) {
		return notify_fail("�����¡���Ҫ����1000������\n");
	}
	if( userp(me) ) {
		me->add("mana", -1000);
	}
	me->set("timer/mingyue", time());

	if( extra >= 200 ) {
		// capped
		extra = 200;
	}
	extra += F_ABILITY->check_ability(me,"3_myqh_add",3)*2;
	bonus = extra/6*extra/6;
	me->add_temp("apply/damage", bonus); // 190: 1000dmg
	target->add_temp("cant_dodge",1);
	target->add_temp("cant_parry",1);
	pros = target->query_temp("protectors");
	target->delete_temp("protectors");
	me->add_temp("marks/full_hit_damage",1);
	msg = HIC"\n$N"HIC"էȻ�˲����������֣������ε���\n\n���ȳ������ϵ���Ҳʧȥ�˹⻪�����ϵ����ﶼ��Ϣע����$N"HIC"����һ�����¡�\n�������£��¹��絶��\n"NOR;
	message_vision(msg, me, target);
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
	message_vision(HIC"\nһ��ָ������ʮɲ�ǣ��������н����뿪$N"HIC"�Ĺ��⣬ֻ������һɲ�Ǽ䡣\n�������������֡�\n"NOR,target);
	COMBAT_D->report_status(target); // snicker,��װ��һ��2hit��perform...
	me->add_temp("marks/full_hit_damage",-1);
	if( target ) {
		target->add_temp("cant_dodge",-1);
		target->add_temp("cant_parry",-1);
		target->set_temp("protectors",pros);
		target->set_temp("annie/damaged_by_mingyue",1);
	}
	me->add_temp("apply/damage",-bonus);
	if( level == 1 ) {
		me->perform_busy(2);
	}
	if( level == 2 ) {
		me->perform_busy(1);
	}
	return 1;
}



