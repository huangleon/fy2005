// silencer@fengyun4

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int bonus, skill_lv, extra;
	int no_dodge, no_parry, exp_bonus;
	
	if( userp(me) ) {
		if( me->query("class") != "lama" ) {
			return notify_fail("��ӡ�����Ǵ����µĶ����ܼ���\n");
		}
	}
	bonus = me->query_skill("lamaism", 1);
	if( bonus < 100 ) {
		return notify_fail("��ӡ������Ҫ100�����ڷ𷨡�\n");	
	}
	skill_lv = me->query_skill("bloodystrike", 1);
	if( skill_lv < 100 ) {
		return notify_fail("��ӡ������Ҫ100�����ڴ���ӡ��\n");	
	}
	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail("��ӡ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	}
	me->add_temp("apply/attack", skill_lv);
	me->add_temp("apply/damage", skill_lv);
	target->set_temp("no_check_pfm_win", 1);

	msg = HIG "$N"HIG"΢΢һЦ��˫�ֺ�£��ʳָѹ��ָ��ķָѹСָ������ָ�������ƺ�����
�ŵ�������$n"HIG"��ȥ��������������ʽ��ʵס����ӡ����" NOR;
	COMBAT_D->do_attack(me, target, TYPE_PERFORM, msg);
	if( objectp(target) && target->query_temp("damaged_during_attack") ) { 	
		target->add_temp("cant_dodge", 1);
		message_vision(WHT"��$N����һ�Σ������ٶۣ��������ܡ�\n"NOR,target);
		no_dodge = 1;
	}

	msg = YEL"$N"NOR+YEL"ԭӡ��������˫��һ�������������Ƶ�һӡ�����Ͼ٣���ʱ����ͻȻ�ı䣬
������ŭ�ţ�����������ȴ�ǵڶ�ʽ�����ִ���ӡ����" NOR;
	COMBAT_D->do_attack(me, target, TYPE_PERFORM, msg);
	if( objectp(target) && target->query_temp("damaged_during_attack") ) { 	
		target->add_temp("cant_parry", 1);
		message_vision(WHT"��$N����һ�Σ��������飬�����мܡ�\n"NOR, target);
		no_parry = 1;
	}

	me->add_temp("apply/attack", -skill_lv);
	me->add_temp("apply/damage", -skill_lv);

	extra = bonus/2 + skill_lv;
	msg = HIR"$N"HIR"˫���漴��£��ȭ��ֻ��ķָ��ʳָͻ�����ڹ�״����������͸�����죬
����������ţ�һ�ƻ�������ʽ����������ӡ����" NOR;
	exp_bonus = (me->query("combat_exp")-3000000)/1000*extra/6000;
	if( exp_bonus < 0 ) {
		exp_bonus = 0;
	}
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra+exp_bonus);
	COMBAT_D->do_attack(me, target, TYPE_PERFORM, msg);
	me->add_temp("apply/attack", -extra);	
	me->add_temp("apply/damage", -extra-exp_bonus);

	if( objectp(target) ) {
		if( no_parry ) {	
			target->add_temp("cant_parry", -1);
		}
		if( no_dodge ) {
			target->add_temp("cant_dodge",-1);			
		}
	}
	
	if( objectp(target) ) {
		if( target->query_temp("damaged_during_attack") ) { 
			COMBAT_D->win_lose_check(me, target, 1);
		}
	}
	
	if( objectp(target) ) {
		target->delete_temp("no_check_pfm_win"); 
		target->delete_temp("skip_damage_record");
	}

	me->perform_busy(3);
	return 1;
}
