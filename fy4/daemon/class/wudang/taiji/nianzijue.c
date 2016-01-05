#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
    	string msg;
    	int extra, mod, damage;

    	if(me->query("class")!="wudang" && userp(me))
		return notify_fail("̫����ճ�־������䵱���֮����\n");

    	extra = me->query_skill("taiji",1);
    	if (extra < 60)
        	return notify_fail("��ճ�־�����Ҫ60��̫��ȭ��\n");

    	if (userp(me) && me->query_skill_mapped("force") != "taijiforce")
		return notify_fail("��ճ�־�����Ҫ̫���ķ���ϣ�\n");

    	if( !target ) target = offensive_target(me);
    	if( !target
        	||!target->is_character()
        	||!me->is_fighting(target) )
        	return notify_fail("��ճ�־���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	mod = COMBAT_D->can_busy(me, target, "taiji");	
	if (!mod)
		return notify_fail(HIW"���˹�����տ�����ᱻ��ȭ���Ի�ġ�\n"NOR);

    	if( target->is_busy() )
        	return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");

    	if (extra < 170) {
        	msg = CYN "\n$Nʹ��̫��ȭ���еġ�ճ�־�������ͼ����$n�Ĺ��ƣ�\n";
        	me->start_busy(1);
        	if (COMBAT_D->do_busy_attack( me, target, "taiji/nianzijue", "unarmed", 200, mod))
        	{
               		msg += "���$p��$P���˸����ֲ�����\n\n" NOR;
            		target->force_busy( me->query_skill("taiji",1) / 50 + random(2));
        	}  else {
            		msg += "����$p������$P����ͼ����û���ϵ���\n\n" NOR;
        	}
        	message_vision(msg, me, target);
        	return 1;
    	}
    	else {

	if (!target->query_temp("annie/wd_busy_test_2") || time() > target->query_temp("annie/wd_busy_test_2") +6 )
	{

        	msg = HIR "\n$N�����Ķ���˫ȭ�û�Ϊ�������СС��ԲȦ��$n��ȥ��\n";
        	if (COMBAT_D->do_busy_attack( me, target, "taiji/nianzijue", "unarmed", 300, mod))
        	{
            		msg += "	���$pͷ��Ŀѣ����$P��ȭ��Χס��������ƵƵ���У�\n\n" NOR;
       
            		target->force_busy(3);
            		me->perform_busy(random(2));
               		damage = me->query("max_force")/6;
            		damage = COMBAT_D->magic_modifier(me, target,"kee",damage);
            		target->receive_damage("kee",damage,me);
       	    		message_vision(msg, me, target);
            		target->set_temp("damaged_during_attack", 1);
               		COMBAT_D->report_status(target, 0);
            		COMBAT_D->win_lose_check(me,target,1);
        	}	else {
            		msg += "	����$p����Ӧ�У���$P�Ĺ����������Ρ�\n\n" NOR;
            		me->perform_busy(random(2));
       	    		message_vision(msg, me, target);
        	}
	        return 1;
	}
	else
	{
        	msg = HIR "\n$N"HIR"ץס$n"HIR"�����������Ķ���˫ȭ�û�Ϊ�������СС��ԲȦ��$n"HIR"��ȥ��\n";
        	if (COMBAT_D->do_busy_attack( me, target, "taiji/nianzijue", "unarmed", 300, mod))
        	{
            		msg += "	���$pͷ��Ŀѣ����$P��ȭ��Χס��������ƵƵ���У�\n\n" NOR;
       
            		target->force_busy(3);
            		me->perform_busy(random(2));
               		damage = me->query("max_force")/6;
            		damage = COMBAT_D->magic_modifier(me, target,"kee",damage);
            		target->receive_damage("kee",damage,me);
       	    		message_vision(msg, me, target);
            		target->set_temp("damaged_during_attack", 1);
               		COMBAT_D->report_status(target, 0);
            		COMBAT_D->win_lose_check(me,target,1);

					target->set_temp("annie/wd_busy_test_3",time());
        	}	else {
            		msg += "	����$p����Ӧ�У���$P�Ĺ����������Ρ�\n\n" NOR;
            		me->perform_busy(random(2));
       	    		message_vision(msg, me, target);
        	}
	        return 1;

	}

    	}
}


