// This pfm is just to simulate mind_sense. making it easier to code NPCs.


#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int damage, ap, dp;

	if(userp(me))
		return notify_fail("����ѡ�õ��书��û�����ֱ�ɱ������\n");
                   
	if( !target ) target = offensive_target(me);        
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���ַ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	msg = HIC "$N��Ŀ����ӡ�÷���һ����â����$n��\n\n" NOR;
	damage = me->query_skill("magic")*3;
	dp = target->query("combat_exp");
	ap = me->query("combat_exp");
	
	if( random(ap *3 )+ap > dp ) {
		damage = damage + random(damage);
		msg +=  HIY "��â��$p����͸��������ϳ�һ��������Ѫ��ֱ�䵽��������ĵ��£�\n" NOR;
		target->receive_damage("kee", damage, me);
		message_vision(msg, me, target);
        	COMBAT_D->report_status(target);
        	COMBAT_D->win_lose_check(me,target,damage);
	} else
		{	msg += HIB"���Ǳ�$n�㿪�ˡ�\n\n"NOR;
			message_vision(msg, me, target);
			}
	me->start_busy(2);
	return 1;
}
