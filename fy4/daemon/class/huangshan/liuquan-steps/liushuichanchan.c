// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int myexp,yourexp,lvl;
	int sen;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("����ˮ������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
	myexp = (int) me->query("combat_exp");
	yourexp = (int) target->query("combat_exp");
	
	lvl = (int) me->query_skill("liuquan-steps", 1)/ 20 + 2;
	msg = HIR "$Nʹ����Ȫ�����еġ���ˮ���������ó�������Ӱ��ӰӰ����$n��" NOR;
	
	if( yourexp < random(myexp * lvl/3))
	{
		message_vision(msg + "\n", me, target);
		msg = CYN"���$n��$N���˸���������\n"NOR;
		message_vision(msg, me, target);
		sen = (int) target->query("sen");
		target->receive_wound("sen", sen/10, me);
		target->force_busy(2);
	}
	else
		 COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	
	me->perform_busy(2);
	return 1;
}
