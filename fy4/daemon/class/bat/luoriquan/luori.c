#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
 	string msg;
 	int extra;
 	
 	extra = me->query_skill("unarmed");
 	if (me->query_skill("luoriquan",1) < 220 && userp(me)) 
 		return notify_fail("����ȭ����Ҫ220��������ȭ��\n");
 	
 	if( !target ) target = offensive_target(me);
 	if( !target
		||	!target->is_character()
		||	!me->is_fighting(target) )
		return notify_fail("�����ա�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	
	me->add_temp("apply/attack",extra/3);
	me->add_temp("apply/damage",extra/5);
	target->set_temp("no_check_pfm_win",1);
	
	msg = HIR  "\n$N���췢��һ����Ц��ʹ��������ȭ�еġ����ա���\n���Ʋ����ޱȵ�Ϧ������ʱ�������Ϊ֮��ɫ��\n" NOR;
	message_vision(msg,me,target);
	msg = HIC    " ��\n" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        target->set_temp("skip_damage_record",1);
        
        
        msg = HIY  "          ��\n" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIW  "                    ��\n" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
       	msg = HIR   "                             ��\n" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
       	msg = HIB   "                                       Բ\n" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/attack",-extra/3);
        me->add_temp("apply/damage",-extra/5);

		if (objectp(target))	{
			if (target->query_temp("damaged_during_attack")) 
				 COMBAT_D->win_lose_check(me,target,1);
		}
	
		if (objectp(target))	{
			target ->delete_temp("no_check_pfm_win"); 
			target->delete_temp("skip_damage_record");
		}
	
	me->perform_busy(3);
	return 1;
}
