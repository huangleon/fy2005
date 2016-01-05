#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
    	string msg;
    	int n,mod;
    	int my_weapon, y_weapon;
    	
    	if (me->query("class")!="wudang")
    		return notify_fail("��ǧ����ɳ�����䵱�Ķ����书��\n");
    	
    	if( !target ) target = offensive_target(me);
    	if( !target
		||!target->is_character()
		||!me->is_fighting(target) )
        	return notify_fail("��ǧ����ɳ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

    	my_weapon = me->query_temp("weapon");
    	y_weapon = target->query_temp("weapon");
    	
    	mod = COMBAT_D->can_busy(me, target, "taiji-sword");	
	if (!mod)
		return notify_fail(HIW"����������������տ�����ᱻ�˽����Ի�ġ�\n"NOR);
    	
    	if( target->is_busy() )
        	return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");
        
		msg=YEL"$N"YEL"ʹ��̫�������е���ɳ������$n"YEL"����������ǧ����ɳ�����಻��������ɱ����...\n"NOR;
    	
    	me->perform_busy(1);
       	 
    	if (COMBAT_D->do_busy_attack( me, target, "taiji-sword/nianzijue", "weapon", 400, mod))
    	{
			msg += WHT"���$p"WHT"��$P"WHT"���˸����ֲ������������ͣ�����ɳ����\n\n" NOR;
			message_vision(msg, me, target);
			n= random(me->query_skill("taiji-sword", 1) / 40) + 2;
			target->force_busy(1);
    		target->set_temp("busy_timer/taiji-sword",time());
			target->set_temp("annie/wd_busy_test_1",time());

    	} else {
        	msg += CYN"����$n"CYN"������$N"CYN"����ͼ����ʵ�Դ�����ȥ$N"CYN"��ʽ���С�\n\n" NOR;
        	message_vision(msg, me, target);
    	}

    	return 1;
}

