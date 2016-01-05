// geese&silencer@fengyun4

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra, level, dam, n, count;
	object weapon;
	
	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail("��������Ұ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	}
	if( me->query_skill_mapped("force") != "lotusforce" ) {
		return notify_fail("�����ȷ������������ķ�Ϊ������\n");
	}
	weapon = me->query_temp("weapon");
	level = me->query_skill("cloudstaff", 1);
	extra = level + F_ABILITY->check_ability(me,"3_lxyy_add",3)*3;
	
	if( ANNIE_D->check_buff(me,"xg-cloudstaff-up")) {
		dam = level*3;
	} else {
		dam = level;		
	}
	if( level < 120 ) {
		me->add_temp("apply/attack", extra);
		me->add_temp("apply/damage", dam);
		msg = HIY"$N�ͺ���ţ���������˫�ۣ����е�"NOR+weapon->name()+HIY"�ó�һ�����׷�����\n����������$n��"NOR;
		COMBAT_D->do_attack(me, target, TYPE_PERFORM, msg);
		me->add_temp("apply/attack", -extra);
		me->add_temp("apply/damage", -dam);
		me->perform_busy(2);
		return 1;
	}
	if( level < 160 || me->query("class") != "bonze" ) {
		me->add_temp("apply/attack", extra);
		me->add_temp("apply/damage",dam);
		msg = HIR"$N�ͺ���ţ���������˫�ۣ����е�"+weapon->name()+HIR"�ó����������׷�������������һ���ǳɣ�\n��籩���ع���$n��\n\n��һʽ��������Ұ��"NOR;
		COMBAT_D->do_attack(me, target, TYPE_PERFORM, msg);
		msg = HIB"�ڶ�ʽ���������죡��"NOR;
		COMBAT_D->do_attack(me, target, TYPE_PERFORM, msg);
		me->add_temp("apply/attack", -extra);
		me->add_temp("apply/damage", -dam);
		me->perform_busy(3);
		return 1;
	}
	me->add_temp("apply/attack", extra);
	me->add_temp("apply/damage",dam);
	target->set_temp("no_check_pfm_win",1);
	msg = HIY"$N�ͺ���ţ���������˫�ۣ����е�"+weapon->name()+HIY"�ó����������׷�������������һ���ǳɣ�\n��籩���ع���$n�����ǰ����ȷ�֮�������ۣ�\n"NOR;
	message_vision(msg, me, target);
	msg = HIY"��������Ұ��"HIB"$N"HIB"���һ��������"+weapon->name()+HIB"����ʵʵ�����Ȳ���$n"HIB"��������硣\n"NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	target->set_temp("skip_damage_record",1);
	msg = HIY"���������졻"HIC"������Ӱ�У�"HIC"$N"HIC"ͻȻ����Ծ�𣬽�����"+weapon->name()+HIC"��ǧ��֮������$n��\n"NOR;
	COMBAT_D->do_attack(me, target, TYPE_PERFORM, msg);
	msg = HIY"�������ĺ���"HIR"$N"HIR"˫��էһ�ŵأ�˫��һ�𣬾��ΰ��������������ͬʱ����$n"HIR"�Ŵ�Ҫ����\n"NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -dam);
	if( objectp(target) ) {
		if( target->query_temp("damaged_during_attack") ) {
			COMBAT_D->win_lose_check(me,target,1);
		}
	}
	if( objectp(target) ) {
		target->delete_temp("no_check_pfm_win");
		target->delete_temp("skip_damage_record");
	}
	me->perform_busy(3);
	return 1;
}