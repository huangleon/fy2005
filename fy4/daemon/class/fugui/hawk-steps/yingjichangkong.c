// yingjichangkong: enhance = 260--> choose a fixed value to make it simple.

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	int extra, enhance, mod;
	string msg;
	
	if (userp(me))
		return notify_fail("��ѧ���书��û�������ؼ���\n");
		
	if(me->query("class") != "fugui" && userp(me))
		return notify_fail("��ӥ�����ա��Ǹ���ɽׯ�ľ�����\n");
		
	extra = me->query_skill("hawk-steps",1);
	if ( userp(me) && extra < 50) 
		return notify_fail("��ӥ�����ա���Ҫ50������������\n");
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��ӥ�����ա�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	   
	mod = COMBAT_D->can_busy(me, target, "hawk-steps");	
	if (!mod)
		return notify_fail(HIW"�����������ᱻ�˲����Ի�ġ�\n"NOR);
	
	if(target->is_busy())
		return notify_fail(target->name()+"�Ѿ���æ�����ˣ�\n");
			
   	message_vision( BRED + HIW "$N"+ BRED + HIW"���������������ӥ����죬�������裡\n"NOR,me,target);
    			
    	if (COMBAT_D->do_busy_attack( me, target, "hawk-steps/yingjichangkong", "step", 260,mod))
    	{
	    	message_vision(HIB"$N"+HIB"����һ�������������ʧ������ľ�������������Լ������վ���\n"NOR,target);
		target->force_busy(2+random(2));
		target->set_temp("busy_timer/hawk-steps",time());
	}
	else{
	    	msg = YEL"��ϧ$N"+ YEL"������$n"+ YEL"������������������ƣ���"NOR;
	        COMBAT_D->do_attack(target,me,TYPE_PERFORM,msg);        
		me->perform_busy(2);	
	}
	return 1;
}


