
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
void single_perform(object target, object me, int myexp, int skill);

int perform(object me, object target)
{
    	string msg;
    	int myexp, ownexp, ownskill;
 	int skill, gin_cost, i, extra, boosted, damage;
 	string *style = ({
	HIY"�����ţݣ� $N"HIY"��Ӱ�ӹ�����ɳ���ֳ�������$n"HIY"��$l��"NOR,
	HIG"�����ţݣ� $N"HIG"��ʽ���಻�����罭�����˽�$n"HIG"�ȵô�����������"NOR,
	HIR"�����ţݣ� $N"HIR"�ڽ��Ľ����ľ�������$n"HIR"���˹�ȥ��"NOR,
	HIC"�۶��ţݣ� $N"HIC"��������������ʮ��ױ���ض�����"NOR,
	HIM"�۾��ţݣ� $N"HIM"���а���������һ��������������$n"HIM"��$l��"NOR,
	HIB"�����ţݣ� $N"HIB"�������ڵ�ɱ���������������������$n��"NOR,
	HIC"�۾��ţݣ� $N"HIC"��һ�һ��ǿ�������������һ�����$n"HIC"��$l��"NOR,
	WHT"�ۿ��ţݣ� $N"WHT"��Ѹ��է�֣���ȡ$n"WHT"��$l��"NOR});
	object ob,*obs,*myteam,*env;

 	skill = (int) me->query_skill("five-steps",1);
 	gin_cost = (int)me->query_int() + 45;
 	
 	if ((string)me->query("class") != "wudang")
  		return notify_fail(WHT"�㲻���䵱���ӣ������ݱ䡺����ͼ����\n"NOR);

	if( !skill || (skill < 100))
  		return notify_fail(WHT"�ݱ䡺����ͼ����Ҫ100������������\n"NOR);
 	
 	if( !target ) target = offensive_target(me);
	if( !target
		|| !target->is_character()
		|| !me->is_fighting(target) )
        return notify_fail("������ͼ��ֻ�ܶ�ս���еĶ���չ����\n");
        
       	myexp = (int) me->query("combat_exp"); 	
       	
       /*Single player perform*/
        if (!me->query_team()) { 
		single_perform(target, me, myexp, skill);
               	return 1;
        	}
       
       	
	if (member_array(target,myteam = me->query_team())!=-1) 
		return notify_fail("�㲻�ܹ������ѡ�\n");

//	Here is the checking to exclude all that not satisfy the condition.	
	
	obs = ({});
        env=all_inventory(environment(me));
        for (i=0;i<sizeof(env);i++) {
        //	tell_object(me,"i = "+ env[i]->query("id") + "\n");
        	if (member_array(env[i],myteam)==-1) continue;
        	if (env[i]->is_busy()) continue;
        	if (!env[i]->query_skill("five-steps")) continue;
        	if (env[i]->query_skill_mapped("dodge") != "five-steps"
        		&& env[i]->query_skill_mapped("move") != "five-steps")	continue;
        	if (env[i]->query_skill("five-steps",1)<120) continue;
        	// Why we now require fight? Because, we don't want ppl using this to bypass legitimate check.
        	if (!env[i]->is_fighting(target))	continue;
        	obs += ({ env[i] });
        	if (sizeof(obs)>=8) break;
        }
        
        if (sizeof(obs)<2) {
		single_perform(target, me, myexp, skill);
               	return 1;
        }

		/* team perform*/
        	else { 
//===============Team==================================================
			tell_object(me, "??\n");
			if(skill<160) {
				single_perform(target, me, myexp, skill);
				return 1;
			}
			
			// confirm everyone using five-steps
			if(sizeof(obs) > 8 ) {
				single_perform(target, me, myexp, skill);
				return notify_fail("������ͼ�������˸��ˣ���\n");
			}
			
			myexp =0;
			extra=0;
			
			for(i=0;i<sizeof(obs);i++)
			{
				myexp += (int) obs[i]->query("combat_exp");
				extra += (int) obs[i]->query_skill("five-steps");
			}
			ownskill=me->query_skill("five-steps");
			ownexp=me->query("combat_exp");
				
			message_vision(MAG"\nֻ��$N"NOR MAG"������һ�䣬�������˾����ݼ�"YEL" �ݡ������ˡ��š���������������"MAG" ����λ�ã��ܳ�"WHT"������ͼ��"MAG"��\n"NOR, me);
                	target->set_temp("no_check_pfm_win",1);
                	
                	if ( random(myexp)*5/i + ownexp/2 > (int) target->query("combat_exp") ){
                		msg = HIR"$N"HIR"ֻ��ɭɭɱ��ֱ͸��ͷ��Ω����ʯ��룬�Ѿ�ƽ�����ɳ�������ص���ɽ��\nһʱ�ĵ��Ժ����粽���ƣ�\n\n"NOR;
                		target->start_busy(2);
                		damage = ownskill + 3*random(extra)/i ;
                		damage = COMBAT_D->magic_modifier(me, target, "sen", damage);     
                		target->receive_damage("sen", damage,me);
                	}
                	else{
                		msg = HIW"\n$N��̤���ţ���ת�����ֵ�������ͼ����Χ����\n"NOR;
                      	}
                	extra = extra/i ;     	
			message_vision(msg, target);
			
			for(i=0;i<sizeof(obs);i++)
        		{
				msg = HIR +  style[i] + NOR;
        			obs[i]->add_temp("apply/attack", extra/2);
        			obs[i]->add_temp("apply/damage", extra);
			//	obs[i]->kill_ob(target);	
				COMBAT_D->do_attack(obs[i],target, TYPE_PERFORM,msg);
				target->set_temp("skip_damage_record",1);
				obs[i]->add_temp("apply/attack", -extra/2);
				obs[i]->add_temp("apply/damage", -extra);
				obs[i]->perform_busy(3);
			}
		if (objectp(target))	{
			if (target->query_temp("damaged_during_attack")) 
				 COMBAT_D->win_lose_check(me,target,1);
		}
	
		if (objectp(target))	{
			target ->delete_temp("no_check_pfm_win"); 
			target->delete_temp("skip_damage_record");
		}

			return 1;

//===============End Team==================================================
        	}
}

void single_perform(object target, object me, int myexp, int skill) {
                int damage;
                string msg = MAG"\nֻ��$N"NOR MAG"������һ�䣬�����ݼ�"YEL" �ݡ������ˡ��š���������������"MAG" �ܳ�"WHT"������ͼ��"MAG"��\n"NOR;
                msg += WHT"\n��ʱ�����������ɳ��ʯ������ǵء�$nֻ��������ӿ�����罣��֮����\n"NOR;
                
                if (COMBAT_D->do_busy_attack( me, target, "five-steps/bazhentu", "step", skill *2, 10))
                {
                       	msg+= HIR"ɭɭɱ��ֱ͸$n��ͷ��Ω����ʯ��룬�Ѿ�ƽ�����ɳ�������ص���ɽ��\n$nһʱ�ĵ��Ժ����粽���ƣ�\n\n"NOR;
                	target->start_busy(2);
               		me->perform_busy(3);
//			average 1500, lowest 1000, highest 2000                		                		
//			200*2 + 150
                	damage = skill*2 + F_LEVEL->get_level(myexp);
                	damage = COMBAT_D->magic_modifier(me, target, "sen", damage);      		
                	target->receive_wound("sen", damage, me);
                	
                	message_vision(msg, me, target);
                	COMBAT_D->report_status(target);
        		COMBAT_D->win_lose_check(me,target,1);
                }
                else {
                	msg+= HIW"\n$n��̤���ţ���ת��ת�����ˡ�����ͼ����Χ����\n"NOR;
                	me->perform_busy(2);
                	message_vision(msg, me, target);
                }                
}
                      
                      
                      