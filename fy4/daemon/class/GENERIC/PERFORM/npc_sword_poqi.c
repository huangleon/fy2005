// npc_poqi.c ����ʽ --- modified to cut force for NPC to use @silencer
 
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	 string msg;
	 int skill,ap,dp,tf;

	if(userp(me))
		return notify_fail("����ѡ�õ��书��û�����ֱ�ɱ������\n");
		
	 if( !target ) target = offensive_target(me);
	        if( !target
	        ||      !target->is_character()
	        ||      !me->is_fighting(target) )
	                return notify_fail("������ʽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	
	 skill = (int)me->query_skill("dugu-sword",1);
	 //no poqi in fy4 for players-neon
	 if( skill < 100 && userp(me))
	 	return notify_fail("��Ķ��¾Ž��ȼ�����, ����ʹ�á�����ʽ����\n");
	
	 msg = HIB "$N���˶��¾Ž�������ʽ����һ����������Ȼ����, �����ǽ�����񾪣� \n";
	
	 ap =  (int) me->query("combat_exp")* skill/50;
	 dp = (int) target->query("combat_exp");
	 if(random(ap+dp) > dp) {
	 	target->set("force",0);
	 	msg += "$n�����������Ѩ�ƺ��������У�������ʧ��\n" NOR;
	        me->start_busy(3);
	        target->start_busy(2);
	 }else {
	 	msg += WHT"����$n������$N�Ľ�·���͵�һ�����ſ��������\n" NOR;
	 	me->start_busy(2);
	 }
	 message_vision(msg, me, target);
	 return 1;
}
