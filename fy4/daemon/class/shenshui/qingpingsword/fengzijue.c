#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int mod, enhance;
	
	if (userp(me))
		return notify_fail("��ʹ�õ��书��û�����������ʽ��\n");
		
	if(me->query_skill("qingpingsword",1)<50)
		return notify_fail("�����ƽ�����ȼ�������\n");
		
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���⡹�־�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");
	
	mod = COMBAT_D->can_busy(me, target, "qingpingsword");	
	if (!mod)
		return notify_fail(HIW"���˹�����տ�����ᱻ�˽����Ի�ġ�\n"NOR);
		
	msg = CYN "$N"+CYN"ʹ����ƽ�����еġ��⡹�־�����������������ͼ����$n"+CYN"�Ĺ��ƣ�";
	
	me->perform_busy(1);
	
	enhance = 1500/4;
	if (COMBAT_D->do_busy_attack( me, target, "qingpingsword/fengzijue", "unarmed", enhance, mod))
	{		
		msg += "���$p"+CYN"��$P"+CYN"���˸����ֲ�����\n" NOR;
		target->force_busy((int)me->query_skill("qingpingsword", 1) / 100 + 2);
		target->set_temp("busy_timer/qingpingsword",time());
	} else {
		msg += YEL"����$p"NOR YEL"������$P"NOR YEL"����ͼ����û���ϵ���\n" NOR;
	}
	
	message_vision(msg, me, target);

	return 1;
}
