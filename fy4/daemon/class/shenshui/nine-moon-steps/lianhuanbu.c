// silencer@fengyun4. workgroup

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra, mod, n;
	
	if(userp(me) && me->query("class")!="shenshui")
		return notify_fail("ֻ����ˮ���Ӳ���ʹ����������\n");
		
	extra = me->query_skill("nine-moon-steps",1);
	if ( extra < 30) return notify_fail("������������Ҫ�������ľ�������\n");
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	
	mod = COMBAT_D->can_busy(me, target, "nine-moon-steps");	
	if (!mod)
		return notify_fail(HIW"�����������ᱻ�˲����Ի�ġ�\n"NOR);
		
	if(target->is_busy())
		return notify_fail(target->name()+"�Ѿ���æ�����ˣ�\n");
	
	message_vision(HBRED+HIW"$N"HBRED+HIW"�������Ű��Է�λ���Ų�������һ��һƮ����Ȧ̤��������\n"NOR,me,target);
	
	if ( me->query_temp("marks/pfm/ss_shui")|| !userp(me)) n = 80;
		else n = 50;
	
	if (COMBAT_D->do_busy_attack( me, target, "nine-moon-steps/lianhuanbu", "rev-unarmed", n, mod))
	{
		message_vision(WHT"΢���Ȼ��$N"NOR+WHT"�ѵ���$n"NOR+WHT"���$n"NOR+WHT"���ǽ������ѣ��޷���ʩ!\n\n"NOR,me, target);
		extra = extra > 150 ? 150 : extra; // Can't let it be 4+ turns busy.
		target->force_busy(2+random(extra/60));
		target->set_temp("busy_timer/nine-moon-steps",time());
	}
	else{
		message_vision(YEL"$n"NOR+YEL"ʩչ�����Ṧ��ٹ�ĴӸɷ��Ƶ���λ��$N"NOR+YEL"�������˸����ֲ�����\n\n"NOR,me, target);
		me->start_busy(1);
	}
	return 1;
}


