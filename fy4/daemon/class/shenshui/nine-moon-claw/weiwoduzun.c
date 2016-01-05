//	HARM TOUCH
// 			--- Revised by Silencer@fy4 

#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
    	string msg;
    	int skill_bonus, myexp, cpexp, damage, duration, mod,stage;
    	
    	if(me->query("class")!="shenshui")
    		return notify_fail("ֻ����ˮ�����Ӳ���ʹ����Ψ�Ҷ��𡻵ľ�����\n");

    	if (me->query_skill("nine-moon-claw",1) < 100)
    		return notify_fail("��Ψ�Ҷ�����Ҫ100���ľ����׹�צ��\n");
    	
    	if ( me->query_skill_mapped("force") != "nine-moon-force")
    		return notify_fail("��Ψ�Ҷ�����Ҫ�����ľ��ĸ�����\n");
    	
 		duration = me->query("timer/ss_suicidal")-time()+ 1800 - F_ABILITY->check_ability(me,"wwdz_add")*60;
        if (duration>0)
        	return notify_fail("�㻹��Ҫ�ȴ�"+(int)(duration/60+1)+"�������Ҳ����ٴ�ʹ�á�Ψ�Ҷ���\n");
 	 	 		
    	if( !target ) target = offensive_target(me);
    	if( !target||!target->is_character()||!me->is_fighting(target) )
        	return notify_fail("��Ψ�Ҷ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 		
    	msg = HIR "$N"HIR"˫Ŀ���࣬������Ѫ�����������׹�צ���һʽ��Ψ�Ҷ��𡻣�˲ʱ�����Ϊ֮��ɫ����\n\n"NOR;
    
    	skill_bonus = me->query_skill("nine-moon-force",1) + me->query_skill("nine-moon-claw" ,1);                  
    	    	
    	// 180 + 200 = 360/40 = 9
    	
    	mod = COMBAT_D->can_busy(me, target, "nine-moon-claw");	
		if (!mod) mod = 10000;
    	    	
    	skill_bonus = 5 + ((skill_bonus>=0) ? skill_bonus/40 : 1) ;
    
       	// SCROLL ADVANCE PERFORM, 
	    stage = me->query("scroll/nine-moon-claw_weiwoduzun");
	    
	    switch (stage) {
	    	case 0:
	    	case 1:	damage = 3000; break;		// almost half kee
	    	case 2:	damage = 4500; break;		// L90
	       	case 3:	damage = 6000; break;		// L100
	     }	
       	
       	damage = damage * (100 + F_ABILITY->check_ability(me,"wwdz2_add")*5)/100;
       	
       	damage = COMBAT_D->magic_modifier(me, target, "kee", damage);
    	
    	if (COMBAT_D->do_busy_attack(me, target, "nine-moon-claw/weiwoduzun","unarmed", skill_bonus*100, mod))
    	{
    	
        	msg += WHT"���$p"NOR+WHT"��$N"NOR+WHT"���˸����ֲ�����\n" NOR;
        	target->receive_damage("kee", damage, me);
        	target->receive_wound("kee", damage, me);
        	message_vision(msg, me, target);
        	COMBAT_D->report_status(target,0);
    	}
    	else {
    		msg += YEL"����$p"NOR+YEL"���Ƕ����$N"NOR+YEL"�����һ������\n"NOR;
			message_vision(msg, me, target);
		}
    	
		me -> set("timer/ss_suicidal", time());
		me ->perform_busy(2);
		return 1;
}


