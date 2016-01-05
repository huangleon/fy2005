//	revised for fy4.1 

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        int extra,mod,lvl;
        object weapon;
		mapping buff;
		
		lvl =  me->query_skill("fy-sword",1);
		if (userp(me) && lvl < 150)
			return notify_fail("��������ӿ����Ҫ150��������ƽ���\n");
		
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��������ӿ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
                
        weapon = target->query_temp("weapon");
		if(!objectp(weapon)) 
			return notify_fail("��Ķ���û���ñ�����\n");
        
        weapon = target->query_temp("weapon");
	
		mod = COMBAT_D->can_busy(me, target, "fy-sword");    
    	if (!mod)       mod = 1000;
	 
    	if (COMBAT_D->do_busy_attack(me, target, "fy-sword/fengqiyunyong", "step", 1000, mod)
    			&& weapon && !weapon->query("nodrop_weapon")
    			&& target->query_temp("marks/disarmed") + 60 < time()) {   			
			message_vision(YEL "\n$N˫�ֺ��ս����������缱�籩���Ϯ����$n���е�"+weapon->name()+NOR YEL"һ�𣬲�֪��ô�������˵��£� \n" NOR, me,target);
			if(weapon->unequip()) {
				buff =
				([
					"caster":me,
					"who":  target,
					"type":"disarmed",
					"att":"curse",
					"name":"������ƽ���������ӿ",
					"buff1":"disarmed",
					"buff1_c":1,
					"time":  60,
					"buff_msg":" ",			
				]);
				ANNIE_D->buffup(buff);
		  	}
		  	target->force_busy(2);
		} else	{
	        me->add_temp("apply/attack", extra);
	        me->add_temp("apply/damage", extra*2);
			msg = YEL "\n$N˫�ֺ��ս����������缱�籩���Ϯ����\n"+ NOR;
			message_vision(msg, me,target);
			COMBAT_D->do_attack(me,target,TYPE_PERFORM,"");
	        me->add_temp("apply/attack", -extra);
	        me->add_temp("apply/damage", -extra*2);
		}
	
		target->set_temp("marks/disarmed",time());
		me->perform_busy(2);
        return 1;
}
