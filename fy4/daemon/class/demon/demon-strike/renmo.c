// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra, damage;

	extra = me->query_skill("demon-strike",1) ;
	if(userp(me) && extra < 180 ) 
		return notify_fail("����ħʽ����Ҫ150�������ħ�������ƣ�\n");
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("����ħʽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	damage = me->query_skill("demon-strike",1)*3;
	
	msg = HIR "\n$N�ȵ���������ʮ�أ�������ħ���������ݣ�ͬ�Ǽ��֡�
ٿȻ��˫�۱�����һ�С���ħʽ����˫��£��$n��" NOR;
	if(random(3*me->query("combat_exp")) >= (int)target->query("combat_exp"))	{
		message_vision(msg+"\n",me,target);
		message_vision( HIM "$N����������ȫ��������Ӱ��ס�� һ��Ѫ���Ӷ�����ӿ������\n" NOR,target);
		damage = COMBAT_D->magic_modifier(me, target, "kee", damage);
		target->receive_damage("kee",damage, me);
		me->receive_fulling("kee",damage/2, me);
		COMBAT_D->report_status(target);
	        COMBAT_D->win_lose_check(me,target,damage);
	}	
	else{
        	me->add_temp("apply/attack",extra);
        	me->add_temp("apply/damage",extra);
        	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        	me->add_temp("apply/attack",-extra);
        	me->add_temp("apply/damage",-extra);
	}
	me->perform_busy(2);
	return 1;
}
