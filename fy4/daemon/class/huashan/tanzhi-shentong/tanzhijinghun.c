// tanzhijinghun.c
//	Busy Rate= *4 unarmed 

#include <ansi.h>
inherit SSERVER;

int perform(object me, object target) {
	
	string msg;
	int skill, mod, enhance, damage;
	
	if (me->query("class")!="huashan")
		return notify_fail("����ָ���꡻�ǻ�ɽ������\n");
	
	skill = (int) me->query_skill("tanzhi-shentong",1); 	
    if ( skill <80) 
    	return notify_fail("����ָ���꡻��Ҫ80���ĵ�ָ��ͨ��\n");
	
	if( !target ) target = offensive_target(me);
	if(!objectp(target) || !target->is_character() || !me->is_fighting(target)) {
		return notify_fail("����ָ���꡻ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	}
	
	if(target->is_busy()) {
		return notify_fail("�Է��Ѿ����ܶ����ˡ�����\n");
	}
	
	mod = COMBAT_D->can_busy(me, target, "tanzhi-shentong");	
	if (!mod)
		return notify_fail(HIW"���˹�����տ�����ᱻ���ַ��Ի�ġ�\n"NOR);
		
		
	msg = HIG"$N"+HIG"��Ӱ��������趯��ָ���ƿ�֮�����Ͳ���Ϯ��"+"$n"+HIG"����ҪѨ��\n"NOR;
	
	enhance = 400;
	
	if (COMBAT_D->do_busy_attack(me, target, "tanzhi-shentong/tanzhijinghun","unarmed", enhance, mod))
	{
		msg += HIG"$n"+HIG"ֻ���ؿ�����Ѩһ�飬��ʱ�������á�\n" NOR;		
		//	200
		damage = me->query_skill("throwing",1)/5;
		damage = COMBAT_D->magic_modifier(me, target, "kee", damage);
		target->receive_damage("kee", damage, me);
		target->force_busy(3);
		if(me->query_skill_mapped("force") != "hanmei-force") {
			me->perform_busy(2);
		}
		else {
		   	msg += WHT"$N"+WHT"������ת������Ȼ�ټ���ɬ��\n\n"NOR;
		   	me->perform_busy(1);
		}
		message_vision(msg, me, target);
		COMBAT_D->report_status(target);
		COMBAT_D->win_lose_check(me,target,1);
		target->set_temp("busy_timer/tanzhi-shentong",time());
	} else {
		msg += YEL"$n"+YEL"�͵�һ�����������$P"+YEL"��ָ�磡��\n"NOR;
		message_vision(msg, me, target);
		me->perform_busy(2);
	}
	
	return 1;
}

