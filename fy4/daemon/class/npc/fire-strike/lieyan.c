// silencer@fengyun4

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra;
	extra = me->query_skill("fire-strike",1);
	if ( extra < 100) return notify_fail("��ģۻ����Ʒ��ݻ��������죡\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);

	msg = HIR  "$N��Ȼ����һ�����ܵ����棬��������ֱ��$n��ȥ��" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIC  "������һ����Ƿɳ���ֱ��$n��$l��" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIY  "����õĶž飬�������䣬��$n����ǰʢ����" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        
	me->add_temp("apply/attack",-extra);
	me->add_temp("apply/damage", -extra);
	me->start_busy(2);
	return 1;
}

