// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	extra = me->query_skill("jindian-fire",1)* 2;
	if ( extra < 100) return notify_fail("��ģ۽���ݻ𷨣ݻ��������죡\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	me->add_temp("apply/attack", extra/5);	
	me->add_temp("apply/damage", extra/5);

	msg = HIM  "$N˫�ַ��أ�һ�У����������ݳ�һ��𻨷���$n��" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIM  "$N˫��һ�ϣ�����ڶ������" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIM  "$Nһ��ָ�죬һ����$nһ�ӣ������ַɳ�һ���һ�" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	me->add_temp("apply/attack",-extra/5);
	me->add_temp("apply/damage", -extra/5);
	me->start_busy(3);
	return 1;
}
