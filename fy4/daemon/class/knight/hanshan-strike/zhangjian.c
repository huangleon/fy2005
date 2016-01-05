#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
		
	string msg;
	int extra,bonus, exp_bonus;
	
	extra = me->query_skill("hanshan-strike",1) ;
	if( extra < 100) 
		return notify_fail("���ƽ���������Ҫ100���ĺ�ɽ�Ʒ���\n");
		
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���ƽ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
	bonus = extra/4 + F_LEVEL->get_level(me->query("combat_exp"));
			
	message_vision(HIC"�׹��Ȼ����$N����������Ϊ����������գ������ƿգ�����Խ�գ�\n"NOR, me);
	
	me->add_temp("apply/attack", bonus);
	me->add_temp("apply/damage", bonus);
	target->set_temp("no_check_pfm_win",1);
	
	msg = MAG"$N˫�ƻ��ཻ��ͻһ����˫�ֻ���Ϊ������$n"MAG"��ȥ��" NOR;
	COMBAT_D->do_attack(me,target,  TYPE_PERFORM,msg);
	target->set_temp("skip_damage_record",1);
	
	msg = YEL"$N"YEL"һ����һ��ײ��$n"YEL"�����ţ�" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	
	if (extra>=100) {
        	msg = WHT"$N"WHT"��һ����˫�Ƽ���$n"WHT"��ȥ��" NOR;
		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	}
	
	if (extra>=130) {
        	msg = HIR"$N"HIR"���ֺ��أ����ֺ�һ���ƣ������Ѿõ��ƽ��ƿ���$n"HIR"��ȥ��" NOR;
		me->add_temp("apply/attack", bonus);
		me->add_temp("apply/damage", bonus);
		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
		me->add_temp("apply/attack", -bonus);
		me->add_temp("apply/damage", -bonus);
	}
	
    me->add_temp("apply/attack", -bonus);
	me->add_temp("apply/damage", -bonus);
	
	if (objectp(target))	{
		if (target->query_temp("damaged_during_attack")) 
		 COMBAT_D->win_lose_check(me,target,1);
	}
	
	if (objectp(target))	{
		target ->delete_temp("no_check_pfm_win"); 
		target->delete_temp("skip_damage_record");
	}

		
	if (extra>=130) 
		me->perform_busy(3);
	else 	
		me->perform_busy(2);
			
	return 1;
}
