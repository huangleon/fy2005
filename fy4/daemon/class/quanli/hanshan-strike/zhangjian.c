// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���ƽ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	extra = me->query_skill("hanshan-strike",1) ;
	if( extra <=60) return notify_fail("��ģۺ�ɽ�Ʒ��ݻ�����������\n");
	me->add_temp("apply/attack", extra/5);	
	me->add_temp("apply/damage", extra/5);
	msg = HIR  "$N˫�ƻ��ཻ��ͻһ����˫�ֻ���Ϊ������$n��ȥ��" NOR;
	COMBAT_D->do_attack(me,target,  TYPE_PERFORM,msg);
	msg = HIR  "ֻ��$N����һ�⣬ײ��$n�����ţ�" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIR  "$N��һ����˫�Ƽ���$n��ȥ��" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIR  "$N���ֺ��أ����ֺ�һ���ƣ������Ѿõģ��ƽ����ƿ���$n��ȥ��" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);

        me->add_temp("apply/attack", -extra/5);
	me->add_temp("apply/damage", -extra/5);
	me->start_busy(4);
	return 1;
}
