// ��Ӱǧ��
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra,n, myexp, mod;
	
	extra = me->query_skill("meng-steps",1);
	if ( extra < 100) return notify_fail("��Ҫ100�����β�������ʹ�á���Ӱǧ�ء�\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("����Ӱǧ�ء�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if(target->is_busy())
		return notify_fail(target->name()+"�Ѿ���æ�����ˣ�\n");
		
	if (me->query("class")=="bat" && extra >=170) n=0;
		else n=10;
	if(me->query_temp("huanyinqianchong")+n>time() && userp(me))
		return notify_fail("��ո�ʩչ������Ӱǧ�ء�\n");	
	
	mod = COMBAT_D->can_busy(me, target, "meng-steps");	
	if (!mod)
		return notify_fail(HIW"�����������ᱻ�˲����Ի�ġ�\n"NOR);
		
/*	myexp=random(me->query("combat_exp")*3);
	if (me->query("class")=="bat")
		myexp=myexp+me->query("combat_exp")/5;*/
		
	message_vision(HIR"\n$N"+HIR"����ӰͻȻһ��ʮ��ʮ��١��ٱ�ǧ��"+HIR"$n"+HIR"�类"+HIR"$N"+HIR"��ǧ�ػ�ӰΧס��\n\n" NOR,me,target);
	
	if (COMBAT_D->do_busy_attack(me, target, "meng-steps/huanyinqianchong", "step", 200, mod))
	{
		message_vision(HIW "���"+HIW"$N"+HIW"Ŀѣ��ڣ��ľ�������\n\n" NOR,target);
		target->force_busy(3);
		me->set_temp("huanyinqianchong",time());
		target->set_temp("busy_timer/meng-steps",time());
	}
	else{
		message_vision(YEL"����"+YEL"$N"+YEL"��������Ӱ�����ң�\n\n"NOR,target);
		me->perform_busy(2);
	}
	
	return 1;
}
