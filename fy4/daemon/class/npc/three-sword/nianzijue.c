#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
    	string msg;
    	int your_exp,n,mod, enhance;
    	int my_weapon, y_weapon;
    	
		if (userp(me))
			return notify_fail("�㲻���䵱�����ǡ�\n");
		
    	if( !target ) target = offensive_target(me);
    	if( !target
		||!target->is_character()
		||!me->is_fighting(target) )
        	return notify_fail("��ճ�־���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

    	my_weapon = me->query_temp("weapon");
    	y_weapon = target->query_temp("weapon");
    	
    	if( target->is_busy() )
        	return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");
    	
    	mod = COMBAT_D->can_busy(me, target, "three-sword");	
		if (!mod)
		return notify_fail(HIW"����������������տ�����ᱻ�˽����Ի�ġ�\n"NOR);
    	       	
    	if (y_weapon) {
    		msg = CYN"\n$N"+CYN"ʹ�����Ž����е�ճ�־������е�"+my_weapon->name()+CYN"��һָ����һ�������ƺ����·���
��ÿ��һ�У����Ʒų�һ��ϸ˿������"+"$n"+CYN"��"+y_weapon->name()+CYN"��\n";
	} 	else {
    		msg = CYN"\n$N"+CYN"ʹ�����Ž����е�ճ�־������е�"+my_weapon->name()+CYN"��һָ����һ�������ƺ����·���
��ÿ��һ�У����Ʒų�һ��ϸ˿������"+"$n"+CYN"���ֱۡ�\n";
	}
    	
    	me->perform_busy(1);
    	enhance= 600;
		if (COMBAT_D->do_busy_attack( me, target, "three-sword/nianzijue", "step", enhance, mod))
		{
        	msg += "���$p"CYN"��$P"CYN"���˸����ֲ�����\n\n" NOR;
			message_vision(msg, me, target);
			n= random(me->query_skill("three-sword", 1) / 40) + 2;
			if (n>3) n=3;
			target->force_busy(n);
    		target->set_temp("busy_timer/three-sword",time());
    	} else {
        	msg += "����$p"CYN"������$P"CYN"����ͼ����û���ϵ���\n\n" NOR;
        	message_vision(msg, me, target);
    	}
    	return 1;
}

