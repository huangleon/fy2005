// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	extra = me->query_skill("yinshe-stick",1)* 2;
	if ( extra < 100) return notify_fail("��ģ����߹����ݻ��������죡\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�����߳�����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	me->add_temp("apply/attack", extra/2);		me->add_temp("apply/damage", extra/2);
	weapon = me->query_temp("weapon");
	msg = HIR "ֻ��$N�趯���е�"+ weapon->name()+ HIR"��������������������$n�����ڣ�" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIR "$N���ֻ��أ����ֵ��ۻӶ�"+ weapon->name()+ HIR"����������������$n��������" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
       	me->add_temp("apply/attack",-extra/2);
	me->add_temp("apply/damage", -extra/2);
	me->start_busy(2);
	return 1;
}
