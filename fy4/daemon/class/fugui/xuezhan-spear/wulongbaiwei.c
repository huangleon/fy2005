// Silencer@fengyun	June.2005

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
    string msg;
	int extra, exp_bonus;
	int mod;
	object weapon;
	
	weapon=me->query_temp("weapon");
 	extra = me->query_skill("xuezhan-spear",1);
    	    	
    if (extra < 50 || me->query_skill("skyforce",1)<50)
    	return notify_fail("��������β����Ҫ50����Ѫսǹ���ͱ̿��ķ�!\n");
    	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
        	return notify_fail("��������β��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    
    mod = COMBAT_D->can_busy(me, target, "xuezhan-spear");	
	if (!mod)
		return notify_fail(HIW"���˹�����񣬲��ᱻ����ʽ�Ի�ġ�\n"NOR);
	
	if(target->is_busy())
		return notify_fail(target->name()+"�Ѿ���æ�����ˣ�\n");

	msg = HIB"\n$N"HIB"���е�"+ weapon->name()+ HIB"��Ȼ�ջأ�ǹβһ�ڣ���в�´�������������β���������£�
�������������������Ƶ����죬ǹӰ���ǣ�\n"NOR;
	    			
    if (COMBAT_D->do_busy_attack( me, target, "xuezhan-spear/wulongbaiwei", "step", 230, mod))
    {
	    msg += YEL"$n��ͬ�⵽�����ȫ���ʹ�������߲��������ס���ӡ�\n"NOR;
		target->force_busy(2);
		target->set_temp("busy_timer/xuezhan-spear",time());
	}
	else{
	   	msg += WHT"$n"NOR+WHT"�ڿ�Ծ��һ�������$N"NOR+WHT"ͷ�Ϸɹ���\n"NOR;
		me->perform_busy(1); 
	}
	
    message_vision(msg, me,target);
    return 1;
}



