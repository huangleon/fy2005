
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
		return notify_fail("���Ϻ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	extra = me->query_skill("unarmed")* 2 ;
	if(extra <= 60 ) return notify_fail("��ġ������ǻ�צ������������\n");
	msg = HIR "$N�����������ϣ�˫��һǰһ��ץ$n���ʺ�Ҫ��$n�ĺ��ץ�ϣ�\n" NOR;
	me->add_temp("apply/damage",extra*2.2);
	me->add_temp("apply/attack",extra*0.8);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	me->add_temp("apply/damage",-extra*2.2);
        me->add_temp("apply/attack",-extra*0.8);
	me->start_busy(2);
	return 1;
}
