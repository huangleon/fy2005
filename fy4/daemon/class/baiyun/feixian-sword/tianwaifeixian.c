//	The purpose of this perform is to busy, not to damage.

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra;
	int i, force;
	object weapon;
	
	if ( me->query("class")!="baiyun")
		return notify_fail("ֻ�а��Ƴǵ��ӲŻ᡺������ɡ��ľ�����\n");
		
	if ((string) me->query_skill_mapped("dodge") != "feixian-steps")
		return notify_fail("��������ɡ�ֻ�ܺͷ��ɲ�����ϣ�\n");
	
	if (userp(me))
	if (me->query_skill_mapped("force") != "chessism")
		return notify_fail("��������ɡ���Ҫ�ĵ��ķ���ϡ�\n");
		
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��������ɡ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
	extra = me->query_skill("feixian-sword",1) / 20;
	extra += me->query_skill("feixian-steps",1) /20;
	
	if (extra > 20) extra = 20;
	
	me->add_temp("apply/attack", extra*4);	
	me->add_temp("apply/damage", me->query_skill("feixian-sword",1)/2);
	me->set_temp("in_feixian_pfm",1);
	weapon=me->query_temp("weapon");
	
	msg = HIR  "$N��̤���ɲ������������飬ʹ�����ɽ����еľ��裭����������ɡ�
���е�"+ weapon->name() +HIR"����һ�����磬�����Ļ���$n��" NOR;

	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
//	msg =  HIY "������磬ת˲���ţ�\n" NOR;
//        message_vision(msg, me, target);
	
	for(i=0;i< extra/5;i++)
	{
		msg = HIY "������磬ת˲���ţ�$N����ͻת�������طɣ�\n" NOR;
		COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
	}
	
	me->add_temp("apply/attack", -extra*4);
	me->add_temp("apply/damage", -me->query_skill("feixian-sword",1)/2);
	me->delete_temp("in_feixian_pfm");
	
	me->perform_busy(2);
	return 1;
}


