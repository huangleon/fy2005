// Silencer @ FY4 workgroup. Aug.2004

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra;
	extra = me->query_skill("luohan-quan",1);
	if( extra <10) return notify_fail("������չ�᡻��Ҫ10���޺�ȭ��\n");
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("������չ�᡻ֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
	me->add_temp("apply/attack", extra * 2);	
	me->add_temp("apply/damage", extra);
	msg = HIY"$N"HIY"��ȭ���ƣ�ȭ�����ģ���ǰһ�ͣ�����ȭ��һ�֣����ƺᵲ���������ӣ�
�����չ�ᣬ��$n"HIY"��ȥ��" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	me->add_temp("apply/attack", -extra * 2);
	me->add_temp("apply/damage", -extra);
	
	me->perform_busy(2);
	
	return 1;
}


