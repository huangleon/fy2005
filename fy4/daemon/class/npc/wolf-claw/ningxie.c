
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
    	if(me->query("class")!="wolfmount")
    	return notify_fail("ֻ����ɽ���Ӳ���ʹ������Ѫ���ľ�����\n");
    	if((int) me->query("force")<50)
    	return notify_fail("�������������ʹ��������Ѫ��������\n");
	
	
	if( !target ) target = offensive_target(me);
	extra = me->query_skill("unarmed")* 2 ;
	if(extra <= 60 ) return notify_fail("��ġ������ǻ�צ������������\n");
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail(WHT"����Ѫ��ֻ�ܶ�ս���еĶ���ʹ�á�\n"NOR);

	
	msg = HIB "$N˫צ�ػ�����һ�����Σ�һ��ɭɭ������ֱ��$n��\n" NOR;
    	if(random(extra*extra/2 + me->query("combat_exp")) 
    		> (int)target->query("combat_exp")) {
		    COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        	msg += WHT"\n����Ϯ����$Nֻ���ó��Ǳ��䣬��׹��ڤ������ѪҺ�������̣� \n" NOR;
        	target->receive_wound("sen", ((int) me->query("max_sen")/5), me);
        	target->receive_wound("kee", ((int) me->query("max_kee")/10), me);
        	target->start_busy(2);
    	}
    	else msg += HIY"\n$N��æ�����Խ��������$n����������һ���� \n" NOR;

    	message_vision(msg, target, me);
    	me->add("sen",-50);
    	me->add("force",-50);
    	me->start_busy(4);
    return 1;
}