// annie 6.27.03
// MANAFLARE - NPC ONLY

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	int i;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("������������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!target->query("force"))
		return notify_fail("�������������޷��ԶԷ�ʹ�á�\n");

	message_vision( HIR BLK"\n$N�����������֡���������������һ��ߵ��$n������\n"NOR,me,target);
	message_vision( WHT
"$n���㲻������һ�ƻ���Ҫ������ʱ��Ϣ��������Ѫ��ӿ��\n" NOR, me,target);
	
	target->receive_damage("kee",target->query("force")*(1+random(3)),me);
	target->receive_wound("kee",target->query("force")*(1+random(3))/3,me);
	target->set("force",0);
    COMBAT_D->report_status(target);
	me->perform_busy(2);
	return 1;
}

