// Silencer@fengyun	June.2005
// �������ʯ�����޷������мܵ�һ��, ������һ�Σ�Ability��-50sec---> 60 Secһ��
//	apply 250, 500, 750 damage @ L180+, L200, L230

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
    string msg;
	int extra, timer, duration,tmp, stage, i, num;
	object weapon, *team, *team1;
	
	if (me->query("class") != "fugui")
		return notify_fail("�������ʯ���Ǹ�����ӵľ��С�\n");
	
	weapon=me->query_temp("weapon");
 	extra = me->query_skill("xuezhan-spear",1);
    	    	
    if (extra < 180|| me->query_skill("skyforce",1) < 160)
    	return notify_fail("�������ʯ����Ҫ180����Ѫսǹ����160���ı̿��ķ���\n");
    
    timer = 120 -F_ABILITY->check_ability(me,"lgss_add")*6;	
    	
	duration = me->query("timer/pfm/xz_liguang")+timer-time();
	if (duration>0)
    		return notify_fail("�������ʯ����Ҫ"+chinese_number(duration)+"�������ٴ�ʹ�á�\n");
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
        	return notify_fail("�������ʯ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");	      

		msg = HIW" \n$N"HIW"��Ծ���𣬻��䷢ǹ

	ǹ��
		
		ǹ��

			ǹ��		
		 
"+(me->query_temp("weapon"))->name()+NOR+WHT"��������ͬ���紩�ְ��Х�У�ֻһ�����㴩�������ɵľ��룡\n"NOR;

    	// SCROLL ADVANCE PERFORM, 
	    stage = me->query("scroll/xuezhan-spear_liguangsheshi");
	    
	    switch (stage) {
	    	case 0:
	    	case 1:	break;	
	    	case 2:	extra = extra*2; break;		// 500
	       	case 3:	
	       	case 4:	extra = extra*3; break;	    // 750
	    }

		message_vision(msg,me,target);
		target->add_temp("cant_dodge",1);
		target->add_temp("cant_parry",1);
		me->add_temp("apply/damage", extra);
		me->add_temp("marks/full_hit_damage",1);		
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
        me->add_temp("marks/full_hit_damage",-1);
        me->add_temp("apply/damage", -extra);
        target->add_temp("cant_dodge",-1);
        target->add_temp("cant_parry",-1);
        
                
        team1 = me->query_team();
		if (pointerp(team1) && sizeof(team1)>1) {
			team = filter_array(team1,(: present($1,environment($2)) :),me);
			if (pointerp(team) && sizeof(team)>1) {
        		for (i=0;i<sizeof(team);i++){
        			if (me->is_busy())	break;
					if (!me->query_temp("weapon"))	break;	
					if (team[i]==me)	continue;
					if (stage == 4 || random(100)< 20) {				
						msg = WHT"\n$N����ǹ�ߣ�����"+team[i]->name(1)+ "����ֳ��У�"+ (me->query_temp("weapon"))->name()+NOR WHT"������$n"NOR WHT"�ɵ���\n"NOR;	
						message_vision(msg,me,target);
						target->set_temp("cant_dodge",1);
						target->set_temp("cant_parry",1);
						me->add_temp("apply/damage", extra);
						me->add_temp("marks/full_hit_damage",1);		
				        COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
				        me->add_temp("marks/full_hit_damage",-1);
				        me->add_temp("apply/damage", -extra);
				        target->delete_temp("cant_dodge");
				        target->delete_temp("cant_parry");
        			}
        		}
        	}
        }
    	           
        me->set("timer/pfm/xz_liguang",time());
        me->perform_busy(1); 
        return 1;
}

