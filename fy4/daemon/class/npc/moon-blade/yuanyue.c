#include <ansi.h>
#include <ansi.h>
#include <combat.h>

inherit SSERVER;
int perform(object me, object target)
{
        string msg;
       object weapon;
        int extra;

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���¼�ʱ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
		extra = me->query_skill("moon-blade",1);
        if((int) extra <= 120)
                return notify_fail("���Բ��ħ�����������������ܳ����¼�ʱ�С�\n");
	
		if (target->query_condition("moon-blade"))
			return notify_fail("�����Ѿ������ˡ�\n");
			
        message_vision(RED"$N���һ����������$n��ǰһ����\n��Ȼ˭Ҳû�п������ô���£���˭��
���Ըо�����$N��Ȼ������\n"NOR,me,target);
		weapon=me->query_temp("weapon");

		if (weapon->query("for_modao"))
		if(random((extra*extra*extra*extra)/50 + target->query("combat_exp"))
			>(target->query("combat_exp")))
		{
			me->set_temp("kill_other",1);
			weapon=me->query_temp("weapon");
		    target->remove_all_killer();
			target->set_temp("last_damage_from",me);
			target->apply_condition("moon-blade",1);
		}
		else
		{
			message_vision(HIW"��$n�͵�һ������������$N��������һ�У�\n\n"NOR,me,target);
			me->start_busy(3);
		}

	else
	{	
		me->add_temp("apply/damage",extra);
		me->add_temp("apply/dodge",extra/2);
		COMBAT_D->do_attack(me,target,TYPE_PERFORM,"");
		me->add_temp("apply/damage",-extra);
		me->add_temp("apply/dodge",-extra/2);
		me->start_busy(3);
	}
        return 1;
}

/*
void kill_him(object me, object target)
{
        string msg;

		
  	msg =  "\n"HIC+target->name()+"��Ȼ�ɶ����࣬��Ϊ��Ƭ�������ߵ�����ȥ��\n" NOR;

//        message_vision(msg, me,target);
		message("vision",msg,environment(target));
		target->set_temp("last_damage_from",me);
        target->die();

		me->set_temp("kill_other",0);

        return ;
}
*/