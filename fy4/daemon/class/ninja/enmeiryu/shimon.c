// mimicat@fy4

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
		
	if(me->query_skill("enmeiryu",1)<120)
		return notify_fail("����-��ȸ��Ҫ120����½��Բ����ȭ����\n");
		
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("������-��ȸ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
	if(me->query("kee")*100/me->query("max_kee")> 20 || me->query("kee")>1000)
		return notify_fail("������-��ȸ��ֻ������Ѫֵ����1000��20%��ʱʹ�á�\n");
	
	extra = me->query_skill("unarmed") ;
		
	msg = HIR "$N������˵������ֻ����һ���ˡ�����������$Nʹ��������һ�С�����.��ȸ��!
$nһʱ��Ϊ�Լ��ۻ�����Ȼ�����ĸ�$N����Ӱ!
$n����һ��$N�͵س���$n����ϥ����ס$n���������־�ס$n
��ͷ������������ȥ��ͬʱ�ⲿ����$n��ü�ġ�" NOR;
        
// damage =(372-150)*10 = 2220, atk = 222*4;
    extra=extra-150;
	
	me->add_temp("apply/damage",extra*10);
	me->add_temp("apply/attack",extra*4);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	me->add_temp("apply/damage",-extra*10);
    me->add_temp("apply/attack",-extra*4);
	
	target->add_hate(me, extra*10);	// !!
		
	me->perform_busy(2);
	return 1;
}
