#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
		string msg;
    	int i, cost, mod,n;
	
		if (me->query_skill("liangyi-force")<100)
			return notify_fail("������Ʊա���Ҫ����100�������ķ���\n");
	
		if( !target ) target = offensive_target(me);
    	if( !target
		||!target->is_character()
		||!me->is_fighting(target) )
        	return notify_fail("������Ʊա�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

    	if( target->is_busy() )
        	return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");
    
    	mod = COMBAT_D->can_busy(me, target, "liangyi-force");	
		if (!mod)
			return notify_fail(HIW"���˹�����տ�����ᱻ���Ʒ��Ի�ġ�\n"NOR);
    	
    	if (me->query("force")<300)
			return notify_fail("������Ʊա���Ҫ300�������Ϊ������\n");
	
		cost = 250 - me->query_skill("liangyi-force",1);
		if (cost <50) cost = 50;
		if (userp(me)) 
			me->add("force", -cost);
		
    	message_vision(BRED + HIW"\n$N"BRED + HIW"ʹ�������ķ���һ�С�����Ʊա����ҽ�ʵ������飬ճ��ճ�棬
���ƴ�ס"+"$n"+BRED + HIW"���󣬺ᾢ������\n"NOR, me, target);
    	me->perform_busy(1);   	
    	    	
    	if (COMBAT_D->do_busy_attack(me, target, "liangyi-force/rufengsibi", "step", 200, mod))
    	{
			message_vision(CYN"\n$N"+CYN"����������ǰһ�壬������������ʼվ����\n\n"NOR,target);
			target->perform_busy(2);
      		target->set_temp("busy_timer/liangyi-force",time());
      	} else 
      		message_vision(WHT"\n����"+"$n"+WHT"������"+"$N"+WHT"����ͼ����û���ϵ���\n\n"NOR, me, target);
			
  		return 1;
}
