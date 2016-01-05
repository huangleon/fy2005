#include <ansi.h>
#include <combat.h>
inherit SSERVER;


int perform(object me, object target)
{
	string msg;
	int extra,n;
	object weapon;
	extra = me->query_skill("xuanyuan-axe",1);
	if ( extra < 40) return notify_fail("�����񹤡�������Ҫ40������ԯ������\n");
	
	if (userp(me) && me->query_skill_mapped("force") != "longlife-force")
		return notify_fail("��ԯ������Ҫ����������ϣ�\n");
		
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�����񹤡�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
	weapon = me->query_temp("weapon");
	me->add_temp("apply/attack",extra);
	target->set_temp("no_check_pfm_win",1);
	
	msg = HIY  "$N"HIY"�������ŭ���������е�"+ weapon->name()+HIY"������������$n"+HIY"����һ��������\n" NOR;
	message_vision(msg, me, target);
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
	target->set_temp("skip_damage_record",1);
        msg = HIY  "\n$N"HIY"��Ǹ��ֱ�죬˫����Ȼ��֣����е�"+ weapon->name()+HIY"�طɣ�����������һ�����񹤡�\n" NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
        
        me->add_temp("apply/attack",-extra);
    
		if (objectp(target))	{
			if (target->query_temp("damaged_during_attack")) 
				 COMBAT_D->win_lose_check(me,target,1);
		}
	
		if (objectp(target))	{
			target ->delete_temp("no_check_pfm_win"); 
			target->delete_temp("skip_damage_record");
		}

	
	me->perform_busy(2);
	return 1;
}

