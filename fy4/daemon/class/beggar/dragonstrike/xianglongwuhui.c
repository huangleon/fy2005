//	 �����޻ڣ� ÿ��ʮ�غϴﵽ����˺�һ�Ρ�

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int lvl, n, level, duration, mod, period;
	
	if( userp(me) && me->query("class") != "beggar" ) {
		return notify_fail("����ʮ����Ϊؤ�������\n");
	}
	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail("�������޻ڡ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	}
	level = me->query_skill("dragonstrike", 1);
	if( level < 20 ) {
		return notify_fail("�������޻ڡ���20���Ľ���ʮ���ơ�\n");
	}
	msg = HIR "$N"HIR"������ʮ���Ƶ�ʮ��ʽ�ڻ��ͨ���ó�ʮ�˸���Ӱһ������$n"HIR"��ʮ�˴�Ҫ����\n" NOR;
	
	mod = COMBAT_D->can_busy(me, target, "dragonstrike");	
	if( !mod ) {
		mod = 1000;
	}
	// �������޻ڡ� ����ʱ���޸����£�
	// level <= 120 --- 40 seconds, level >= 220 --- 30 seconds 
	if( level <= 120 ) {
		period = 40;
	} else if( level > 220 ) {
		period = 30;
	} else {
		period = 40 - (level-120)/10;
	}

	period = period - F_ABILITY->check_ability(me, "xianglong_add");			// 20 - 40
	duration = time() + 1 - me->query_temp("timer/pfm/xianglongwuhui");			// time to last pfm, 1--- infinity.

	if( duration > period ) {
		duration = period;
	}
	if( duration < 1 ) {
		duration = 1;
	}
	lvl = level * 2 * duration / period; 
	
	//	40 sec 	+340atk, +340dmg/+680 dmg for a self-busy 2 pfm, �п���BUSY
	//	20 sec  +170atk, +170dmg/+340 dmg for a self-busy 2 pfm, û����BUSY
	//  ���� 4 sec, + 34 atk, + 34dmg/+68dmg for a self-busy 2 pfm  û����BUSY
	
	me->set_temp("timer/pfm/xianglongwuhui", time());

	if( !target->is_busy() &&  duration > 20 ) {
		msg += HIR"$N���һ�������ư�����˸�������\n"NOR;
		if( COMBAT_D->do_busy_attack(me, target, "dragonstrike/xianglongwuhui", "unarmed", 400, mod) ) {
			msg += WHT"���$n��$N���˸���æ���ң�\n"NOR;
			target->force_busy(2);
		} else {
			msg += WHT"$n�������񣬶�$N�ĺȽ��������ţ�\n"NOR;
		}
	}
	me->add_temp("apply/attack", lvl);
	me->add_temp("apply/damage", lvl*2);
	message_vision(msg, me, target);
	COMBAT_D->do_attack(me, target, TYPE_PERFORM, "");
	me->add_temp("apply/attack", -lvl);
	me->add_temp("apply/damage", -lvl*2);

	if( level >=160 && me->query("class") == "beggar") {
		me->add_temp("apply/attack", lvl);
		me->add_temp("apply/damage", lvl*2);
		msg = HIR "\n�����Ʒ��Ȼ��ʧ��$N"HIR"�������Ƴ�һ�У���һ��ȴ��ʮ���Ƹ����£�\n"NOR;
		message_vision(msg, me, target);
		COMBAT_D->do_attack(me, target, TYPE_PERFORM, "");
		me->add_temp("apply/attack", -lvl);
		me->add_temp("apply/damage", -lvl*2);    
	}

	if( ANNIE_D->check_buff(me, "fastcast") > 0 ) {
		me->perform_busy(1);
	} else {
		me->perform_busy(2);
	}
	return 1;
}