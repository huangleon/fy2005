// Silencer@fengyun	June.2005
//	enhance = 250;

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
    	string msg;
    	int extra, busy, mod, enhance;
    	object weapon;
    
    	if (me->query("class")!="shaolin")
    		return notify_fail("����ȥ�δӡ��������书��\n");
    	
    	extra = me->query_skill("fumostaff",1);
    	if (me->query_skill("staff",1) < 150 || extra<150) 
    		return notify_fail("����ȥ�δӡ���Ҫ150����Τ�ӷ�ħ�ȷ���150�������ȷ���\n");
      
    	if( !target ) target = offensive_target(me);
    	if( !target
		||!target->is_character()
		||!me->is_fighting(target) )
        return notify_fail("����ȥ�δӡ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        
    	if(target->is_busy())
	        return notify_fail("�Է��Ѿ���æ�����ˣ�\n");

    	mod = COMBAT_D->can_busy(me, target, "fumostaff");	
		if (!mod)
			return notify_fail(HIW"���ֹ�����տ�����ᱻ���ȷ��Ի�ġ�\n"NOR);

    	weapon = me->query_temp("weapon");
    
    	message_vision(HBRED+HIW"\n�ຣãã���δ��ǰ���$N"HBRED+HIW"���е�"+weapon->name()+ HBRED+HIW"��Ȼ�ó�ʮ������ã���֣�\n"NOR,me);

		if (COMBAT_D->do_busy_attack(me, target, "fumostaff", "step", 200, mod)) 
    	{
			target->force_busy(3);
			target->set_temp("busy_timer/fumostaff",time());
			message_vision(YEL"$N���ȷ����󣬶�������������\n\n"NOR,target);
    		    		
    		if (userp(me) && !me->query("pfm/fumo_improve"))
    			me->perform_busy(1);
    	}
    	else
    	{
			message_vision(HIR"$N��Ȼ�����˷����������ϣ�$n���Ȼ���ʱ��ʧ���٣�\n\n"NOR,target,me);		
			me->perform_busy(2);
    	}
    	return 1;
}

