// silencer@fengyun
//	��������ī���廨���ۣ�ͷ������ƽ�߹ڵ�����
//	������ʮ�أ�����֮�ӣ�������٣���ħ��������
// 	����ʮ�أ�������ħ���������ݣ�ͬ�Ǽ���
//	����ʮ�أ���������������ţ�Ψ���Ǵ�
//	�����̣����ڻ����£��ְַ׸롢���ǡ���Ȯ�������ֵ���������
//    ����Ȯ������׷�٣������ǡ�����ɱ�����׸롱�����񣬾��Ǹ����̽���ݸ�·
//	����Ϣ��


#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra, damage;
	
	extra = me->query_skill("demon-strike",1) ;
	if(userp(me) && extra < 150 ) 
		return notify_fail("����ħʽ����Ҫ180�������ħ�������ƣ�\n");
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("����ħʽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	
	damage = me->query_skill("demon-strike",1)*3;
	
	msg = HIR "\n$N�ȵ���������ʮ�أ���������������ţ�Ψ���Ǵӡ���
ٿȻ��˫�۱�����һ�С���ħʽ����˫��£��$n��" NOR;
	
	if(random(me->query("combat_exp")*3) >= (int)target->query("combat_exp"))	{
		message_vision(msg+"\n",me,target);
		message_vision( HIC "$N����������ȫ��������Ӱ��ס�� һ�������Ӷ�����ӿ������\n" NOR,target);
		damage = COMBAT_D->magic_modifier(me, target, "sen", damage);
		target->receive_damage("sen",damage,me);
		me->receive_fulling("sen", damage/2,me);
		COMBAT_D->report_status(target);
	        COMBAT_D->win_lose_check(me,target,damage);
	}	
	else{
        	me->add_temp("apply/attack",extra);
        	me->add_temp("apply/damage",extra);
        	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        	me->add_temp("apply/attack",-extra);
        	me->add_temp("apply/damage",-extra);
	}
	me->perform_busy(2);
	return 1;
}
