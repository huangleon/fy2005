// mimicat@fy4
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg,weapon_name;
	int extra, mod;
	object weapon,myweapon;
	mapping buff;

	extra = me->query_skill("ittouryu",1) ;
	if ( extra < 100) 
		return notify_fail("�������С���Ҫ���������ġ�һ������������\n");
		
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�������С�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	
	weapon = target->query_temp("weapon");
	myweapon = me->query_temp("weapon");
	weapon_name= myweapon->query("name");
	
	mod = COMBAT_D->can_busy(me, target, "ittouryu");    
    if (!mod)       mod = 1000;
    
    message_vision(HIG "$N��������$n�Ĺ��������һ���������С�����"+weapon_name+ HIG"�߾ٹ��磬
�����Ϸ�ֱ��$n��ȥ��\n"NOR,me, target);
	
 	if (COMBAT_D->do_busy_attack(me, target, "ittouryu/gobankiri", "step", 150, mod)
    	&& weapon && !weapon->query("nodrop_weapon")
    	&& target->query_temp("marks/disarmed") + 60 < time()) {    
    	message_vision(HIG"
���$N����һ���һ����$n�����еı�������ʶ��һ����
"+ HIW"
$nֻ���û���һ�ȣ����е�"+weapon->name()+HIW"��Ҳ�ò�ס�ˣ���������һ������������\n\n" NOR, me,target);
		if(weapon->unequip()) {
			buff =
				([
					"caster":me,
					"who":  target,
					"type":"disarmed",
					"att":"curse",
					"name":"һ����������������",
					"buff1":"disarmed",
					"buff1_c":1,
					"time":  30,
					"buff_msg":" ",			
				]);
			ANNIE_D->buffup(buff);
		}
	}
	else {
		if (!random(10) && !target->query_temp("damaged_during_attack") && target->query_temp("weapon")
			&& COMBAT_D->do_busy_attack(me, target, "ittouryu/gobankiri", "step", 100, mod))
		{
			msg = "���$N����һ���һ����$n�����еı�������ʶ��һ����"+
HIC"\nֻ���á�������һ�����죬�������еı���һ�𣬸��Ժ�����һ����\n\n"+ NOR;
			message_vision(msg,me,target);
			target->set_temp("busy_timer/ittouryu",time());
			target->force_busy(2);
		} else {
			me->add_temp("apply/attack",extra);
			me->add_temp("apply/damage",extra*2);
			COMBAT_D->do_attack(me,target,1,"");
			me->add_temp("apply/attack",-extra);
			me->add_temp("apply/damage",-extra*2);
		}
	}
    target->set_temp("marks/disarmed",time());	
	me->perform_busy(2);
	return 1;
}
