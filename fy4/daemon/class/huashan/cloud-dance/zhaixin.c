// ��ժ��ʽ����zhaixin�����������Ψ�Ҷ�����50��ժ���֣���1000-5500 enhance 300, 30m CDT
//	��ժ���ֵ�perform�����ǳɹ��ʴ�*3��ߵ�*5

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
    	int extra, cloud, mod, damage, duration, damage2;
    	string msg;
    	if (me->query("class") != "huashan") 
    		return notify_fail("ֻ�л�ɽ���ӿ���ʹ�á�ժ��ʽ����\n");
    
    	extra=me->query_skill("zhaixin-claw",1);
    	cloud = me->query_skill("cloud-dance",1);
    	
    	if (cloud < 120) 
    		return notify_fail("�÷�Ʈ���踨���ġ�ժ��ʽ��������Ҫ120���Ļ÷�Ʈ���衣\n");
    	    	
    	if (extra<120) 
    		return notify_fail("�÷�Ʈ���踨���ġ�ժ��ʽ��������Ҫ120����ժ���֡�\n");
    	
    	if (me->query_skill_mapped("unarmed") != "zhaixin-claw")
		return notify_fail("�÷�Ʈ����ĸ���������Ҫժ���ֵ�ȭ����ϡ�\n");

    	duration = me->query("timer/pfm/hs_zhaixin")-time()+1800 
    				- F_ABILITY->check_ability(me,"zhaixin_add")*60;
        if (duration>0)
        	return notify_fail("�㻹��Ҫ�ȴ�"+(int)(duration/60+1)+"�������Ҳ����ٴ�ʹ��ժ��ʽ��\n");
        	
    	if( !target ) target = offensive_target(me);
    	if( !target||!target->is_character()||!me->is_fighting(target) )
        	return notify_fail("��ժ��ʽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    	
    	msg = WHT "$n��ɫ��òҰ���ֽ��˫������ָ�ⷢ��ӨӨ�Ĺ�â�� 
$n��Ȼ����һ˿Ʈ�ư�����$N��ǰ��˫צ�������ץ��$N�Ŀڣ� \n"NOR;
	
		me->set("timer/pfm/hs_zhaixin",time());    	

		mod = COMBAT_D->can_busy(me, target, "zhaixin-claw");	
		if (!mod) mod = 10000;
    	
    	// 500 + 28*100/5 = 1060
    	// 500 + 139 * (180+200/2)/5 = 8284;
    	    	
//		extra = extra > 220? 220: extra;	// capped.
					
		damage = 500 + F_LEVEL->get_level(me->query("combat_exp")) * (extra + cloud/2) /5;	
	
		if (userp(me) && userp(target)) {
			damage = damage/2;
		}
		damage2= damage * F_ABILITY->check_ability(me,"3_zhaixin_add",3)/10;
			
		damage  = COMBAT_D->magic_modifier(me, target, "sen", damage);
		damage2 = COMBAT_D->magic_modifier(me, target, "kee", damage2);
			    	
    	//	*5 ������
    	if (COMBAT_D->do_busy_attack(me, target, "cloud-dance/zhaixin","unarmed", 120 + extra + cloud, mod)){   
	        
	        target->receive_wound("sen", damage ,me);
	        if (damage2)	target->receive_damage("kee",damage2,me);
	        	
	        if (target->query("eff_sen")< 0 || target->query("eff_kee")<0)
	        	msg += RED"\n$N"RED"�ò������ŵ��۹⿴���Լ��Ŀڵ�Ѫ��������һ�Σ����ڵ��ϡ� \n" NOR;
	        else
	        {
	        	msg += YEL"\n$N�����ܿ����Ŀ�Ҫ����צ�������ȴҲ����ǰһ�ڣ���Ѫ���硣\n"NOR;
	        	message_vision(msg, target, me);
    			COMBAT_D->report_status(target);
    			COMBAT_D->win_lose_check(me,target,damage);
    			me->perform_busy(3);
    			return 1;	
    		}
	        		
    	}
    	else 
    		msg += HIC"\n$N��æ���з�ס$n������ɭɭצӰ�������ˣ��㿪��$n������һ���� \n" NOR;

    	message_vision(msg, target, me);
    	me->perform_busy(5);
    	return 1;
}
