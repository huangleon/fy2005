// �ݺ��ĺ�      
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra, mod, enhance;
	extra = me->query_skill("fengyu-piaoxiang",1);
	if ( extra < 150) return notify_fail("���ݺ��ĺ�����Ҫ150������Ʈ�㲽��\n");

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���ݺ��ĺ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
	if(target->is_busy())
		return notify_fail(target->name()+"�Ѿ���æ�����ˣ�\n");
		
	mod = COMBAT_D->can_busy(me, target, "fengyu-piaoxiang");	
	if (!mod)
		return notify_fail(HIW"�����������ᱻ�˲����Ի�ġ�\n"NOR);
	
	message_vision(HIY"$N����ͻȻ�ӿ죬��ͬ�������������������ݺ��ĺ�֮���ƣ�\n" NOR,me,target);
	
	enhance = 150 + (extra -150)/2;
	
	if (COMBAT_D->do_busy_attack( me, target, "fengyu-piaoxiang/zonghengsihai", 
		"step", enhance, mod))
	{
		message_vision(HIB "���$N"+HIB"���ָ��ţ�һ��Īչ��\n" NOR,target);
		me->set_temp("timer/pfm/zonghengsihai",time());
		target->force_busy(2+random(2));
		target->set_temp("busy_timer/fengyu-piaoxiang",time());
	}
	else{
		message_vision(YEL"���$N�������ң�\n"NOR,target);
		me->perform_busy(2);
	}
	return 1;
}


