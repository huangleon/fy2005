#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string dodskill,msg;
	int extra;
	int tmp, timer, duration, i;
	object weapon;
			
	if (ANNIE_D->check_buff(me,"fg-afo-bffy")<1)
		return notify_fail("��ѧ���书��û�д����ؼ���\n");
		
	weapon = me->query_temp("weapon");
	if (!weapon)
		return notify_fail("�����޷�ʹ�ô��ؼ���\n");
				
	extra = me->query_temp("pfm/fg-afo-bffy");
	
//	write ("extra = " + extra + "\n");	
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���˷���������ݡ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	
	target->set_temp("no_check_pfm_win",1);
	
    msg = HIR "\n\n$N���һ������Ȼʹ����Ѫսǹ�����е�����һ����--�˷�--����--������--��\n"NOR;
    message_vision(msg, me, target);
    
    msg=HIR"�����š�\n$N����$w"+HIR"�ɻ�������$n"+HIR"������" NOR;
	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
	target->set_temp("skip_damage_record",1);
	
    msg = HIR  "�����š�\n$N����$w"NOR+HIR",��������ìӰ,���մ���$n��" NOR;
	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIR  "����š�\n$N��$w"NOR+HIR"��������,Ӳ�����㳯$n"NOR+HIR"���˹�����" NOR;
	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIR  "�ﾰ�š�\n����$N����$w"NOR+HIR"�û���ǧ��������,�����ܶ�,����$n��" NOR;
	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIR  "�ﾪ�š�\n$N��$w"NOR+HIR"��û�������,����һ����һ��������ˣ�����$n��" NOR;
	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);	
    msg = HIR  "�￪�š�\n$N��������,����$w"NOR+HIR"�󿪴���,����㳯$n"+HIR"Ϯ�˹�����" NOR;
	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIR  "�����š�\n$N�Ϻ�һ��,����$w"NOR+HIR"Ѹ�籼�׿���糸,����ͱ��$n��" NOR;
	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIW  "�����š�\n$w"NOR+HIW"����һ�������κ�����֮���Ļ���,���絶�а㻮��$n"NOR+HIW"�����ţ�" NOR;
	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);   
		if (objectp(target))	{
			if (target->query_temp("damaged_during_attack")) 
				 COMBAT_D->win_lose_check(me,target,1);
		}
	
		if (objectp(target))	{
			target ->delete_temp("no_check_pfm_win"); 
			target->delete_temp("skip_damage_record");
		}
 
 	ANNIE_D->debuff(me,"fg-afo-bffy"); 
    me->perform_busy(4);
	return 1;
}
