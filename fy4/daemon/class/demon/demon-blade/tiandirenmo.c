// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string dodskill,msg;
	int extra, step;
	extra = me->query_skill("demon-blade",1);
	if ( extra < 100) 
		return notify_fail("�������ħ����Ҫ100���������ħ������ʽ��\n");
	step = me->query_skill("demon-steps",1);
	if ( step < 100) 
		return notify_fail("�������ħ����Ҫ100���������ħ�����˲���\n");
	
	dodskill = (string) me->query_skill_mapped("dodge");
	if ( dodskill != "demon-steps")
		return notify_fail("�������ħ����Ҫ������ħ�����˲�����ϣ�\n");
	
	if ( me->query_skill_mapped("force")!= "demon-force")
		return notify_fail("�������ħ����Ҫ�����ħ�ķ�����ϣ�\n");
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�������ħ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	
	step = me->query_skill("demon-steps",1);
	
	target->set_temp("no_check_pfm_win",1);
	me->add_temp("apply/attack",step);
	me->add_temp("apply/damage",extra);	
	
	msg = HIY  "\n$N������ͨ���������ħ������ʽһ���ǳɣ�\n��ħ���ѣ�" NOR;
	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
	target->set_temp("skip_damage_record",1);
        
        msg = HIY  "ħ�����ɣ�" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIY  "ħ��է�֣�" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIY  "��ħ����" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIY  "������ħ��" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIY  "��ħ���죡" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIY  "��ħ���֣�" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIY  "��ħ���ڣ�" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        me->add_temp("apply/attack",-step);
	me->add_temp("apply/damage",-extra);	
	
		if (objectp(target))	{
			if (target->query_temp("damaged_during_attack")) 
				 COMBAT_D->win_lose_check(me,target,1);
		}
	
		if (objectp(target))	{
			target ->delete_temp("no_check_pfm_win"); 
			target->delete_temp("skip_damage_record");
		}

	
	me->perform_busy(5);
	return 1;
}
