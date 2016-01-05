


#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
    	string dodskill,msg;
    	int extra;
    	int tmp,chance;
    	extra = me->query_skill("shenji-blade",1);
    	if ( extra < 50) return notify_fail("�������������������죡\n");
    	dodskill = (string) me->query_skill_mapped("dodge");
    	if ( dodskill != "shenji-steps")
        	return notify_fail("���Ƴ���������Ҫ�����������ϣ�\n");
    	tmp = me->query_skill("shenji-steps",1);
    	if ( tmp < 50 )return notify_fail("��ġ�������������������죡\n");
	
	chance=(extra+tmp)/2;
	chance=chance<160? 160-chance:0;
	
	
    	if( !target ) target = offensive_target(me);
    	if( !target
		||	!target->is_character()
		||	!me->is_fighting(target) )
        	return notify_fail("���Ƴ�������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    
    	target->set_temp("no_check_pfm_win",1);
    	me->add_temp("apply/attack",tmp);
    	me->add_temp("apply/damage",extra);
    	msg = HIR  "\n\n$N"HIR"�ӳ���������еľ�����ص�һʽ�������ƣ�����������������\n\n"NOR;
    	message_vision(msg, me, target);
    		
    		msg=HIR"\n��սƪ��\n$N"HIR"����$w"HIR"ֱ��$n��" NOR;
    		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
    		target->set_temp("skip_damage_record",1);
    	
    	if(chance<random(160))
    	{
    		msg = HIY  "ʤսƪ��\n$N"HIY"����$w"+HIY"б��$n��" NOR;
    		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
    	}
    	if(chance<random(160))
    	{    
    		msg = HIW  "��սƪ��\n$N"HIW"����$w"+HIW"ƽ��$n��" NOR;
    		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
    	}
    	if(chance<random(160))
    	{        
    		msg = HIG  "��սƪ��\n$N"HIG"����$w"+HIG"�ῳ$n��" NOR;
    		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
    	}
    	if(chance<random(160))
    	{    
    		msg = HIM  "��սƪ��\n$N"HIM"����$w"+HIM"�ݶ�$n��" NOR;
    		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
    	}
    	if(chance<random(160))
    	{    
        	msg = HIC  "��սƪ��\n$N"HIC"����$w"+HIC"����$n��" NOR;
    		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
    	}
    	if(chance<random(160))
    	{       
    		msg = HIB  "��սƪ��\n$N"HIB"����$w"+HIB"����$n��" NOR;
    		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
    	}
//  if(chance<random(160))
    	{    
    		msg = HIR  "��սƪ��\n$N"HIR"����$w"+HIR"�ӽ����������$n"+HIR"ɱȥ��" NOR;
    		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
    	}
    
		me->add_temp("apply/attack",-tmp);
    	me->add_temp("apply/damage",-extra);
		
		if (objectp(target))	{
			if (target->query_temp("damaged_during_attack")) 
				 COMBAT_D->win_lose_check(me,target,1);
		}
	
		if (objectp(target))	{
			target ->delete_temp("no_check_pfm_win"); 
			target->delete_temp("skip_damage_record");
		}

		
    	me->perform_busy(5);
    	
    	return 1;
}
