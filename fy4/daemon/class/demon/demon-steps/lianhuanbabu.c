// tie@fengyun
//	NPC only, no plan for players.

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra, mod;
	
	extra = me->query_skill("demon-steps",1);
	if ( userp(me) && extra < 200) 
		return notify_fail("�������˲�����Ҫ200����������ħ�����˲��ݣ�\n");
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�������˲���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
	if(target->is_busy())
		return notify_fail(target->name()+"�Ѿ���æ�����ˣ�\n");
	
	mod = COMBAT_D->can_busy(me, target, "demon-steps");	
	if (!mod)
		return notify_fail(HIW"�����������ᱻ�˲����Ի�ġ�\n"NOR);
		
	message_vision(HIC"������ʮ�أ���������������ţ�Ψ���Ǵӣ�����
$N"HIC"�ŲȰ��ԣ�����ħ�䣬���ӷ�����������һ�����̰���$n"HIC"��ߴ���\n"NOR,me,target);
	
	if (COMBAT_D->do_busy_attack(me, target, "demon-steps/lianhuanbabu", "step", 300, mod))
	{
		message_vision(HIB"$N���ŵ��ĵ����ѣ������ɢ��\n"NOR,target);
		target->force_busy(3);
		target->set_temp("busy_timer/demon-steps",time());
	}
	else{
		message_vision(YEL"$n�������񣬲�Ϊ������$N�Լ�����ת�˸�ͷ���ۻ���\n"NOR,me,target);
		me->perform_busy(2);
	}
	return 1;
}
