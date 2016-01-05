// Silencer@fengyun	June.2005
//	inherent +20% from six-sense
// no +atk, +dmg, 1st 100, 2nd 100, 3rd 500+200
//	compared to FY4 1st 150, 2nd 150, 3rd 1100

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra,apply, dmg, n;
	object weapon;
	
	extra = me->query_skill("diesword",1);
	weapon=me->query_temp("weapon");
	
	if ( extra < 100) 
		return notify_fail("���ʵ�����Ҫ100��������������\n");
	if (userp(me) && me->query_skill_mapped("force") != "qidaoforce")
		return notify_fail("���ʵ�����Ҫ����ķ�����ϣ�\n");

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���ʵ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	
	message_vision(HIG"$N����������˻���������$n����Ц�����ɼ佣����һ������Ī������������������������ͥ�¡�\n"NOR, me, target);
			
	if (me->query_temp("pfm/tx-hit-dodged") + 10 > time()) { 
		me->delete_temp("pfm/tx-hit-dodged");
		me->add_temp("apply/attack",extra*3);
		me->add_temp("apply/damage",extra*2);
		target->add_temp("cant_dodge",1);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
		target->add_temp("cant_dodge",-1);
		me->add_temp("apply/damage",-extra*2);
		me->add_temp("apply/attack",-extra*3);
	}
	else	{
		COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
		me->perform_busy(2);		
	}
	
	return 1;	
}