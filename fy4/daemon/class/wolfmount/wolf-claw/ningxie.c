#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
    	if(me->query("class")!="wolfmount")
    		return notify_fail("ֻ����ɽ���Ӳ���ʹ������Ѫ���ľ�����\n");
    	
	extra = me->query_skill("wolf-claw",1) ;
	if(extra <= 100) 
		return notify_fail("��ġ������ǻ�צ������������\n");
	
	if(me->query("force")<50 && userp(me))
    		return notify_fail("�������������ʹ��������Ѫ��������\n");
		
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail(WHT"����Ѫ��ֻ�ܶ�ս���еĶ���ʹ�á�\n"NOR);

	
	msg = HIB "$N"HIB"˫צ�ػ�����һ�����Σ�һ��ɭɭ������ֱ��$n��\n" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
    	
    	if(random(extra*extra*extra/2 + me->query("combat_exp"))+ me->query("combat_exp")/2 
    		> (int)target->query("combat_exp")) {
	       	msg = WHT"\n����Ϯ����$nֻ���ó��Ǳ��䣬��׹��ڤ������ѪҺ�������̣� \n" NOR;
        	target->receive_wound("sen", ((int) me->query("max_sen")/5), me);
        	target->receive_wound("kee", ((int) me->query("max_kee")/10), me);
        	target->start_busy(2);
    		if (userp(me)) me->start_busy(4);
    			else me->start_busy(3);
    	}
    	else {
    		msg = HIY"\n$n��æ�����Խ��������$N����������һ���� \n" NOR;
		me->start_busy(2);
		}
    	message_vision(msg, me, target);
    	if (userp(me)) me->add("sen",-50);
    	if (userp(me))  me->add("force",-50);
    	return 1;
}