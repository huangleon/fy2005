// Silencer @ FY4 workgroup. Aug.2004

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
void remove_effect(object me, int amount);
int perform(object me, object target)
{
        int skill;
	string msg;
	mapping buff;
	
	skill = me->query_skill("tie-steps", 1);
	if(skill < 150 && userp(me)) 
		return notify_fail("����˿�ơ���Ҫ150����Ѫʮ���ƣ�\n"); 
		
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("����˿�ơ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
        if( (int)me->query("force") < 100 )    
        	return notify_fail("�������������\n");
        if (userp(me))	me->add("force", -100);
        		
        if( ANNIE_D->check_buff(target, "defdown")) 
        	return notify_fail("�Է��ķ������Ѿ��½��ˡ�\n");
        
        skill = skill;
        
        message_vision(HIR "$N"+HIR"����һԾ�������������ݰ�����$n"+HIR"�������ת����ͣ��\n" NOR, me,target);	
       	if (COMBAT_D->do_busy_attack(me, target, "tie-steps/chansi", "unarmed", skill*5/2,10))
       	{
       	   	msg = HIR"$N��������$n��Ӱ�죬�����Ӳ������\n"NOR;
        	buff =
			([
				"caster":me,
				"who":	target,
				"type": "defdown",
				"att":"curse",
				"name":"��Ѫʮ���ơ���˿��",
				"buff1":"apply/dodge",
				"buff1_c": -skill,
				"buff2":"apply/parry",
				"buff2_c": -skill,
				"time": 60,
				"buff_msg": msg,
			]);
		ANNIE_D->buffup(buff);
	}
	else
	{
		msg = WHT"��ϧ$N"+WHT"������$n"+WHT"��������$n"+WHT"ѸȻ������"NOR;
		COMBAT_D->do_attack(target,me,TYPE_PERFORM,msg);	
	}
    return 1;
}
