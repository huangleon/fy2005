// Silencer@fengyun workgroup	June.2005

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
    string forceskill,msg;
	int extra, exp_bonus, chance;
	int tmp;
	object weapon;
	
	forceskill= me->query_skill_mapped("force"); 
	weapon=me->query_temp("weapon");
 	extra = me->query_skill("yue-spear",1);		
	tmp = me->query_skill("manjianghong",1);
    	
    if (tmp < 60 || extra < 60 )
    	return notify_fail("���ݺ����¡���Ҫ60����������ƽǹ�����������ķ�!\n");
    	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
        	return notify_fail("���ݺ����¡�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    
    weapon = me->query_temp("weapon");
    
    
    chance = F_ABILITY->check_ability(me,"3_zhtx_add",3)* 10;
    if (random(100)< chance)
    	chance = 1;	
    else
    	chance = 0;
    
    if ( (me->query("family/master_id")!="master yue" 
    	||extra < 160 ||me->query("class")!="official") && !me->query("annie/npc-zhtx7hit")){ 
   		// extra= 120, tmp = 130*3
   		me->add_temp("apply/attack", extra);    
        me->add_temp("apply/damage", tmp*3);
    	msg = HIR  "$N"HIR"���쳤Х������"+weapon->name()+HIR"�û���ǧ��ìӰ��һʽ���ݺ����¡�������˷�ֱ��$n����\n" NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -tmp*3);
        me->perform_busy(2 - chance); 
    	return 1;
    }
        
        else {
	
		if ( forceskill != "manjianghong") tmp = 0;
        	
        target->set_temp("no_check_pfm_win",1);
		me->add_temp("apply/attack",extra);
		// +atk 180
		msg = HIW "\n$N"HIW"���쳤Х����Ȼ����ֱ������������"+weapon->name()+HIW"�û���ǧ��ìӰ�����ǡ�������ƽǹ����
��ս�޵�֮ʽ��--��-��-��-��--��!!\n"NOR;
		message_vision(msg, me, target);
		
			msg = HIC"��\n$N"HIC"����$w"HIC"���Ƴ��գ���Ȼֱ��$n!" NOR;
						
			COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg, "����");
    		target->set_temp("skip_damage_record",1);
    		
    		msg = HIC  "����\n$N"HIC"ŭ��һ����ǧ��ìӰ���κ��˰����$n��" NOR;
			COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg, "����");
    		msg = HIC  "����Ȼ\n$N"HIC"��ǹ֮�������м䣬ǹͷǹβ���������������$n��" NOR;
			COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg, "����");
    			// +atk 180*3, +dgm 150*2
    			me->add_temp("apply/attack",extra*2);
        		me->add_temp("apply/damage",tmp*2);  
    		msg = HIC  "�ݺ�����\n$N"HIC"����$w"+HIC"������Ҷ���޴����ڣ�����ǹӰ��һ����ֱ��$n��" NOR;
        		COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg, "����");
    			me->add_temp("apply/attack",-extra*2);
        		me->add_temp("apply/damage",-tmp*2); 
    		msg = HIC  "��˻\n$N"HIC"ǹ�ⶶ��,�������磬�������죬����������,�Ʋ��ɵ���" NOR;
        		COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg, "����");
    		msg = HIC  "Ѫ��\n$N"HIC"����$w"+HIC"ǹͷ����ٿȻ��������������Ѫ�⣡" NOR;
			COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg, "����");
    		msg = HIC  "��\n������ţ�$N"HIC"����$w"+HIC"ǹӰ��ʧ��" NOR;
			COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg, "����");
        	me->add_temp("apply/attack",-extra);
   
		if (objectp(target))	{
			if (target->query_temp("damaged_during_attack")) 
				 COMBAT_D->win_lose_check(me,target,1);
		}
	
		if (objectp(target))	{
			target ->delete_temp("no_check_pfm_win"); 
			target->delete_temp("skip_damage_record");
		}
           
		me->perform_busy(6 - chance);   
        }
        return 1;
}
