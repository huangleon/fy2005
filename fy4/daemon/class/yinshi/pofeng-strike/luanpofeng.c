// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra, bonus;
	int exp_bonus;

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�����÷硻ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	
	extra = me->query_skill("pofeng-strike",1);
		
	exp_bonus=(me->query("combat_exp")-3000000)/1000*extra/6000;
	if (exp_bonus<0) exp_bonus=0;	
		
	me->add_temp("apply/attack", extra + exp_bonus);	
	me->add_temp("apply/damage", extra*2);
	msg = HIR  "$N˫��Ѫ�죬��ָ�������������Ʒ��ƿն�����������������Ѹ���ޱȵػ���$n��" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	me->add_temp("apply/attack", -extra - exp_bonus);
	me->add_temp("apply/damage", -extra*2);
	
	me->perform_busy(2);
	return 1;
}
