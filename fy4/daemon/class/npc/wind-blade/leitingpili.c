// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	if(me->is_busy())
		return notify_fail("������û�գ���\n");
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("������������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	weapon = me->query_temp("weapon");
	extra = me->query_skill("wind-blade",1);
	me->add_temp("apply/attack", extra*2);	
	me->add_temp("apply/damage", extra*3);
	msg = HIR  "$N���е�"+ weapon->name() +HIR"�ó����쵶�ƣ�"+weapon->name() +HIR"���Ƶ��ƣ�����������Ļ���$n��\n" NOR;
	message_vision(msg, me, target);
	COMBAT_D->do_attack(me,target,TYPE_PERFORM,"");
	me->add_temp("apply/attack", -extra*2);
	me->add_temp("apply/damage", -extra*3);
	me->perform_busy(2);
	return 1;
}
