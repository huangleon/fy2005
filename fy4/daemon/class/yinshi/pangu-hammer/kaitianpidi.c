// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra,i;
	object weapon;
	if(userp(me))
		return notify_fail("ֻ��������Ӳ���ʹ������ٵء�\n");
	
	if (me->query_skill("pangu-hammer",1)<100)
		return notify_fail("������ٵء���Ҫ100�����̹Ŵ�����\n");
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("������ٵء�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	
	weapon = me->query_temp("weapon");
	extra = me->query("force");
	if ( extra < 300) return notify_fail("�������̫�������ò���������ٵء�����У�\n");
		
	msg = HIC"
	        �� �� �� �� �� �� �� �� ��\n\n"NOR;
	msg += HIY  "    $N"+HIY"�߸ߵؾ������е�"+ weapon->name()+ HIY"��ȫ��֮��������$n"+HIY"��Ȼ����\n\n" NOR;
	message_vision(msg, me, target);
	
	me->add_temp("apply/damage", extra);
	COMBAT_D->do_attack(me,target,TYPE_PERFORM,"");
	me->add_temp("apply/damage", -extra);
	
	if (userp(me)) me->set("force",(me->query("force"))*2/3);
	me->perform_busy(3);
	return 1;
}

