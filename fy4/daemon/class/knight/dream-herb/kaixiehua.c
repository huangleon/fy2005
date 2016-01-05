// sillencer@fy4.com

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	int skill, enhance, mod;
    	string msg;

    	if(me->query("class")!="knight")
    		return notify_fail("ֻ�п���ֵ��Ӳ��ܹ�ʹ�á���л����\n");

	skill = me->query_skill("dream-herb",1);
	if (skill <50)
		return notify_fail("����л������Ҫ50���������廨����\n");

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("����л����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
	if (target->is_busy())
		return notify_fail("�����Ѿ���æ�����ˡ�\n");
		
	mod = COMBAT_D->can_busy(me, target, "dream-herb");	
	if (!mod)
		return notify_fail(HIW"���˹�����տ�����ᱻ�����ġ�\n"NOR);
		
	message_vision(HIM"\n�����á�������һ����ͻȻ��$N���Ϸɳ�һ����������������
��ϸ����˿�Ĺ�â�����ҷ������͵����졣\n"NOR, me, target);

	enhance = 200 + skill /2;	// 200 + 100 = 300
	
	if (COMBAT_D->do_busy_attack(me, target, "dream-herb/kaixiehua", "step", enhance, mod))
	{			
		message_vision(HIG"�������У�һ��Ũ�����棬����$N�����ը����\n"NOR,target);
		target->set_temp("busy_timer/dream-herb",time());
		target->force_busy(2+random(2));
	}
	else{
		message_vision(YEL"$N"YEL"���Ų�æ��һ�ƽ������ɢ��\n"NOR,target);
		me->perform_busy(2);
	}
	
	return 1;
	
}
	