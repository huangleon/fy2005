#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
 string msg;
 int extra;

 object weapon;

 extra = me->query_skill("springrain-blade",1);
 if ( extra < 120 && userp(me)) 
 	return notify_fail("��Ĵ��굶���������졣\n");
 if( !target ) target = offensive_target(me);
 if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�۵�ʱ���£�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	me->add_temp("apply/attack",extra*2);
	me->add_temp("apply/damage",extra);
	weapon = me->query_temp("weapon");
	msg = HIC  "$N��̾һ�����������˸�������"+ weapon->name()+"бб�ӳ���ȴ�ǡ����굶�����еľ���֮ʽ����ʱ�������£�����\n" NOR;
	message_vision(msg,me,target);
	msg = HIC"		��   "HIY"	       ��\n" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIC"		ʱ   "HIY"	       ��\n" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIC"		��   "HIY"	       ��\n" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIC"		��   "HIY"	       ��\n" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIC"		��   "HIY"	       ��\n" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	me->perform_busy(3);
        me->add_temp("apply/attack",-extra*2);
        me->add_temp("apply/damage",-extra);
	return 1;
}
