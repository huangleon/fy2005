// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra, mod;
	extra = me->query_skill("shenji-steps",1);
	if ( userp(me) && extra < 100) 
		return notify_fail("��������㡻��Ҫ100�������������\n");
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��������㡻ֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
	mod = COMBAT_D->can_busy(me, target, "shenji-steps");	
	if (!mod)
		return notify_fail(HIW"�����������ᱻ�˲����Ի�ġ�\n"NOR);
		
	if(target->is_busy())
		return notify_fail(target->name()+"�Ѿ���æ�����ˣ�\n");
		
	message_vision(HIG"\n$N"+HIG"���������磬��������$n"+HIG"�����$n"+HIG"��һ��һ��������$N"+HIG"�����֮�У�\n"NOR,me,target);
	
	if (COMBAT_D->do_busy_attack(me, target, "shenji-steps/shenjimiaosuan", "step", 300, mod))
	{
		message_vision(HIB"���$N"+HIB"�����ô�ʧɫ����æ���ң�\n\n"NOR,target);
		target->force_busy(3);
		target->set_temp("busy_timer/shenji-steps",time());
	}
	else{
		message_vision(HIY"����$N"+HIY"�������ţ�\n"NOR,target);
		me->perform_busy(2);
	}
	return 1;
}
