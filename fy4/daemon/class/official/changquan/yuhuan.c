// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra,sklv;
	int orforce, force;
	
	if(userp(me) && me->query("class") != "official")		
		return notify_fail("�㲻�ǳ�͢��Ա������������ԧ��ȭ��\n");
	extra = me->query_skill("unarmed");
	sklv = me->query_skill("changquan",1);
	if (userp(me) &&extra < 220) 
		return notify_fail("����ԧ��ȭ����Ҫ220����Ч���ֳ�ȭ!\n");
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("����ԧ��ȭ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
	if (me->query("force") < 120)
		return notify_fail ("����ԧ��ȭ��������Ҫ120���������\n");

	orforce = extra/7;
	me->add("force_factor",orforce);
	force = me->query("force");
	
	target->set_temp("no_check_pfm_win",1);
	
	me->add_temp("apply/attack",extra/10);
	msg = HIY  "$Nʹ�����ֳ�ȭ�еġ���ԧ��ȭ����һ��������ʽ��$n������\n" NOR;
	message_vision(msg,me,target);
	msg = HIY  "��һȭ��" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	target->set_temp("skip_damage_record",1);
	
        msg = HIY  "��һȭ��" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIY  "��һȭ��" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIY  "��һȭ��" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIY  "ǰһȭ��" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIY  "��һȭ��" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIY  "�����һȭ����" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	me->add_temp("apply/attack",-extra/10);
	
		if (objectp(target))	{
			if (target->query_temp("damaged_during_attack")) 
				 COMBAT_D->win_lose_check(me,target,1);
		}
	
		if (objectp(target))	{
			target ->delete_temp("no_check_pfm_win"); 
			target->delete_temp("skip_damage_record");
		}
		
	if (me->query("force_factor"))
	me->add("force_factor",-orforce);
	me->set("force", force - 120);
	if (sklv >= 250) {
		me->perform_busy(4);
	} else {
		me->perform_busy(5);	      			
	}
	return 1;
}
