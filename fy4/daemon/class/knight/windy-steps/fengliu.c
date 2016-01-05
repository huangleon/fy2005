#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg, type;
	int extra,enhance,mod;
	
	if (userp(me))
		return notify_fail("û�������书�ؼ���\n");
		
	extra = me->query_skill("windy-steps",1);
	if ( extra < 50) 
		return notify_fail("����������Ҫ50��������ʮ��ʽ��\n");
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
	if(target->is_busy())
		return notify_fail(target->name()+"�Ѿ���æ�����ˣ�\n");
	
	mod = COMBAT_D->can_busy(me, target, "windy-steps");	
	if (!mod)
		return notify_fail(HIW"����������������տ�����ᱻ�˲����Ի�ġ�\n"NOR);
	
	message_vision(HIY"$N"HIY"�Ųȷ��������½�ƮƮ���·�����ƣ�������$n"HIY"���ݰ���ת���죡\n"NOR,me,target);
	
	if (me->query("class") == "knight")	type = "step";
		else 				type = "unarmed";
	
	enhance = 150 + extra/2;
	
	if (COMBAT_D->do_busy_attack(me, target, "windy-steps/fengliu", type, enhance, mod))
	{			
		message_vision(HIG"���$N"HIG"���ŵ��ۻ����ң���Ӧ��Ͼ��\n"NOR,target);
		target->set_temp("busy_timer/windy-steps",time());
		target->force_busy(2+random(2));
	}
	else{
		message_vision(WHT"���$N"WHT"�Լ�ת�˸�ͷ���ۻ���\n"NOR,me);
		me->perform_busy(2);
	}
	return 1;
}