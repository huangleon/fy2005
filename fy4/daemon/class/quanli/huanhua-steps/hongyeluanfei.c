// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int i;
	object weapon;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("[��Ҷ�ҷ���ǧȥ]ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	weapon = me->query_temp("weapon");
	if (!weapon) return notify_fail("[��Ҷ�ҷ���ǧȥ]ֻ�ܺ�佻�������ͣ�\n");
	if( (string)weapon->query("skill_type") != "sword" )
	return notify_fail("[��Ҷ�ҷ���ǧȥ]ֻ�ܺ�佻�������ͣ�\n");
	if ( (string) me->query_skill_mapped("sword") != "huanhua-sword")
	return notify_fail("[��Ҷ�ҷ���ǧȥ]ֻ�ܺ�佻�������ͣ�\n");
	
	extra = me->query_skill("huanhua-sword",1) ;
	extra += me->query_skill("huanhua-steps",1);
	
	me->add_temp("apply/attack", extra/2);	
	me->add_temp("apply/damage", extra);
	
	msg = HIR  "$Nʹ��[��Ҷ�ҷ���ǧȥ]������������������е�"+ weapon->name() +"�������԰˷�����$n��" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	if (weapon)	weapon->unequip();
	
	msg =  HIW "���������������$n��������\n" NOR;
        message_vision(msg, me, target);
	
	for(i=0;i<extra/100;i++)
	{
	msg = HIY "$N�������ƣ�ʹ��佻��ɵķ����Ʒ�������$n��$l��\n" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	}
	if (weapon) weapon->equip();
	
	me->add_temp("apply/attack", -extra/2);
	me->add_temp("apply/damage", -extra);
	me->start_busy(2);
	return 1;
}
