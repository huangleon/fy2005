// ������Taunt��

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        int amount, skill, dorm, add, duration, fix;
        string msg,dot_owner,dir,index;
		object hatred;
	
		if(me->query("class")!="legend")
			return notify_fail("ֻ����ѩɽׯ�ĵմ����Ӳ��ܹ�ʹ��������\n");

 		skill = me->query_skill("meihua-shou",1);
 		dorm = me->query_skill("dormancy",1);
 		
 		if(skill <100)
			return notify_fail("����������Ҫ100����÷���֡�\n");
 	 		 	
 		if( !target ) target = offensive_target(me);
		if( !target
			||	!target->is_character()
			||	!me->is_fighting(target) )
			return notify_fail("��������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
                
        fix = 10;        
        duration = me->query("timer/pfm/tx_taunt")+ fix - time();
        if (duration>0)
        	return notify_fail("�㻹��Ҫ�ȴ�"+ duration+"�������Ҳ��ܹ��ٴ�ʹ��������\n");
        
        dot_owner = file_name(me);
    	sscanf(dot_owner,"%s#%s",dir,index);
    	dot_owner = me->query("id")+ index;
    	
    	if (target->query_temp("dot/meihua-shou/taunt/"+dot_owner))
    		return notify_fail("�����Ѿ��������µ������ˡ�\n");
        
        me->set("timer/pfm/tx_taunt",time());
        
        msg = HIR"\n$N����$n˫���һΣ���Ȼ¶���ô��һ��������\n"NOR;
        
        if (!COMBAT_D->do_busy_attack(me, target, "taunt", "unarmed", 500, 10))
        {
        	msg += WHT"$n�������أ���$N�������Ӷ�������\n"NOR;
        	message_vision(msg, me, target);
        	return 1;
        }
        
       	amount = F_LEVEL->get_level(me->query("combat_exp"))* 10;
       	
//	    printf("%O's hate is %O\n",target,target->query_hate_list());
                
        // ��ʵ�����ӵ�hateΪ lvl* 14��
		
		if (!userp(target))			
      		target->add_hate(me, amount);
 		target->set_temp("dot/meihua-shou/taunt/"+dot_owner,1);
 		target->add_temp("marks/kongmen_adjust",-1);
 		
		call_out("dot",6,me,target,3,0, amount,dot_owner, msg);       
               
        if( me == target->query_max_hate())
        	msg+= YEL"$nһ���л��ɳˣ������ع���$N��\n"NOR;
        else
        	msg+= RED"$n�ƺ���Щ�Ķ�����$N�ݺݵص���һ�ۡ�\n"NOR;
        	
		message_vision(msg, me, target);

//		printf("%O's hate is %O\n",target,target->query_hate_list());
	       
		return 1;       
}



void dot (object me, object enemy, int total, int count, int amount, string dot_owner, string msg)
{
		if (!me || !enemy || !enemy->is_fighting(me)) {
			if (enemy) {
				enemy->delete_temp("dot/meihua-shou/taunt/"+dot_owner);
				enemy->add_temp("marks/kongmen_adjust",1);
			}
			return;
		}
	
		message_vision(msg, me, enemy);
		if (!userp(enemy))
			enemy->add_hate(me, amount/2);
		
		count = count+1;
		if (count<total) 
			call_out("dot",6,me, enemy,total,count, amount, dot_owner,msg);
		else {
			tell_object(me,YEL"���"+enemy->name()+YEL"������Ч�������ˡ�\n"NOR);
			if (enemy) {
				enemy->delete_temp("dot/meihua-shou/taunt/"+dot_owner);
				enemy->add_temp("marks/kongmen_adjust",1);
			}
		}
		return;
}
