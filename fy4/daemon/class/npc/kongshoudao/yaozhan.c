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
		return notify_fail("����ն��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	extra = me->query_skill("unarmed")* 2 ;
	if(extra <= 80 ) return notify_fail("��ģۿ��ֵ��ݲ���������\n");
	msg = HIR "$N"HIR"ͻȻ�Ƶ�$n"HIR"�����ϥ��Ȼ�϶���˫��ͬʱץ��$n"HIR"����ͼ��$n"HIR"�ĺ����Ķϣ�" NOR;
	me->add_temp("apply/damage",extra*2);
	me->add_temp("apply/attack",extra);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	me->add_temp("apply/damage",-extra*2);
        me->add_temp("apply/attack",-extra);
	me->start_busy(2);
	return 1;
}
