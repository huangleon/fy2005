#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
    	string msg;
    	int n,mod;
    	int my_weapon, y_weapon;
    	
    	if (me->query("class")!="wudang")
    		return notify_fail("��ճ�־������䵱�Ķ����书��\n");
    	
    	if( !target ) target = offensive_target(me);
    	if( !target
		||!target->is_character()
		||!me->is_fighting(target) )
        	return notify_fail("��ճ�־���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

    	my_weapon = me->query_temp("weapon");
    	y_weapon = target->query_temp("weapon");
    	
    	mod = COMBAT_D->can_busy(me, target, "taiji-sword");	
	if (!mod)
		return notify_fail(HIW"����������������տ�����ᱻ�˽����Ի�ġ�\n"NOR);
    	
    	if( target->is_busy() )
        	return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");
        	
    	if (y_weapon) {
    		msg = CYN"\n$N"+CYN"ʹ��̫�������е�ճ�־������е�"+my_weapon->name()+CYN"��һָ����һ�������ƺ����·���
��ÿ��һ�У����Ʒų�һ��ϸ˿������"+"$n"+CYN"��"+y_weapon->name()+CYN"��\n"NOR;
	} 	else {
    		msg = CYN"\n$N"+CYN"ʹ��̫�������е�ճ�־������е�"+my_weapon->name()+CYN"��һָ����һ�������ƺ����·���
��ÿ��һ�У����Ʒų�һ��ϸ˿������"+"$n"+CYN"���ֱۡ�\n"NOR;
	}
    	
    	me->perform_busy(1);
       	 
    	if (COMBAT_D->do_busy_attack( me, target, "taiji-sword/nianzijue", "weapon", 200, mod))
    	{
    	       	msg += WHT"���$p"WHT"��$P"WHT"���˸����ֲ�����\n\n" NOR;
		message_vision(msg, me, target);
		n= random(me->query_skill("taiji-sword", 1) / 40) + 2;
		if (n>3) n=3;
		target->force_busy(n);
    		target->set_temp("busy_timer/taiji-sword",time());
    	} else {
        	msg += YEL"����$p"YEL"������$P"YEL"����ͼ����û���ϵ���\n\n" NOR;
        	message_vision(msg, me, target);
    	}
    	return 1;
}

