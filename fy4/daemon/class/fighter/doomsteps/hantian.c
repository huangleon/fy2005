// silencer@fengyun

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int step,fist,extra;
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�ۺ������ȣ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	
	step = me->query_skill("doomsteps",1);
	fist = me->query_skill("doomstrike",1);
	
	if (step< 100) return notify_fail("���������ȡ���Ҫ100���ĺ������ƺʹ�Ѫ������\n");
	if (fist< 100) return notify_fail("���������ȡ���Ҫ100���ĺ������ƺʹ�Ѫ������\n");
	
	me->add_temp("apply/attack", fist);	
	me->add_temp("apply/damage", fist*2);
	msg = HIR  "$Nʹ���۾��غ����ƣݣ�ȫ�������ת��˫��һǰһ�������Ļ���$n��" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	me->add_temp("apply/attack", -fist);
	me->add_temp("apply/damage", -fist*2);
	
	me->add_temp("apply/attack", step);	
	me->add_temp("apply/damage",step*2);
	msg = HIR  "$N��һ������Ѹ���ޱȵ���$n�߳�����һ�ȣ�" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg,"����");
	me->add_temp("apply/attack", -step);
	me->add_temp("apply/damage",-step*2);
	
	if (me->query("class")=="fighter" || !userp(me)) {
		if (me->query_busy()<2) me->start_busy(2); 
	} else {
		if (me->query_busy()<3) me->start_busy(3);
	}
	return 1;
}
