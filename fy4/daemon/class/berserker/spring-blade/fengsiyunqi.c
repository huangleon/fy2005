// A perform with extra damage to sen. (up to (200*2 + 150)*3 = 1250 wound

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra;
	extra = me->query_skill("spring-blade",1);
	if ( extra < 100) return notify_fail("��Ĵ�����⵶���������죡\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail(HIG"��������"NOR"ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
	target->add_temp("no_check_pfm_win",1);
	 
	msg = HIC "\n$N"HIC"����էȻһת��ɱ���紺ѩ�����ڣ����е�"+(me->query_temp("weapon"))->name()+ HIC"������һƬ��������
�����ഺɫ����ӳ����ɽ��ˮ���̲����죬��ô�������޵�����$n��\n" NOR;
	
	message_vision(msg, me, target);
		
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
	
	if (target)
	if (target->query_temp("damaged_during_attack"))
	{
		message_vision(HIG"$N���������İ��Σ�ͻȻһ����ס�ؿڣ����һ����Ѫ��\n"NOR,target);
		target->receive_wound("sen",COMBAT_D->magic_modifier(me, target, "sen",me->query_skill("blade")*3+1), me);	
	}
	
    if (target) {
    	target->add_temp("no_check_pfm_win",-1);
        COMBAT_D->win_lose_check(me,target,1);
    }
    
	me->add_temp("apply/attack",-extra);
	me->add_temp("apply/damage", -extra);
	
	me->perform_busy(2);
		
	return 1;
}


/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/
