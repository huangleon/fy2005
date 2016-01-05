// Silencer@fengyun	June.2005

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
    string msg;
	int extra, timer, duration,tmp, cost;
	object weapon;
	
	if (me->query("class") != "shaolin")
		return notify_fail("�����Ƕ��ǡ������ֵ��ӵľ��С�\n");
	
	weapon=me->query_temp("weapon");
 	extra = me->query_skill("duanhun-spear",1);
    	    	
    if (extra < 170 )
    	return notify_fail("�����Ƕ��ǡ���Ҫ170���Ķϻ�ǹ��!\n");
    
    timer = 60 - F_ABILITY->check_ability(me,"qixing_add")*2;	
    duration = me->query("timer/pfm/sl_qxdp")+timer-time();
	if (duration>0)
    		return notify_fail("�����Ƕ��ǡ���Ҫ"+chinese_number(duration)+"�������ٴ�ʹ�á�\n");
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
        	return notify_fail("�����Ƕ��ǡ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");	      
 	
		msg = HIW" \n$N"HIW"��Хһ������ն�������"+weapon->name()+HIW"����һ�����磬��$n����������
����һ���İ׹⣬����һ������â��һǹ���ǣ�ͬʱ�ɻ������Ƕ��ǣ�һǹ������\n"NOR;
		
		message_vision(msg, me, target);
		me->add_temp("apply/attack", extra*3);
		me->add_temp("apply/damage", extra*6);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
        me->add_temp("apply/attack", -extra*3);
        me->add_temp("apply/damage", -extra*6);
        
        if (target)
        if (target->query_temp("damaged_during_attack"))
        	target->add_hate(me,extra*8);
        
        me->set("timer/pfm/sl_qxdp",time());
        
        me->perform_busy(1); 
        return 1;
}

