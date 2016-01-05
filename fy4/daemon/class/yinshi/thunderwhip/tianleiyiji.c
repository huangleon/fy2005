#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
    	string msg;
    	int extra, hammer;
    	object weapon;
    	int busy, super;
    	
    	if( !target ) target = offensive_target(me);
		if( !target
        ||!target->is_character()
        ||!me->is_fighting(target) )
        	return notify_fail("������һ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        
    	weapon = me->query_temp("weapon");
    	extra = me->query_skill("thunderwhip",1);	// 200 *1.6
    	    	
    	if( extra <50) return notify_fail("������һ����������Ҫ50���������ƣ�\n");

    	if( extra < 200 || me->query("class")!= "yinshi")
    	{
            me->add_temp("apply/attack", extra);
        	me->add_temp("apply/damage", extra);
        	msg = HIR"\n$N"+HIR"������ң����е�"+weapon->query("name")+
            		HIR"���ȣ���һ����������������$n"NOR+HIR"��ȥ��\n" NOR;
        	message_vision(msg,me,target);
        	COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
        	me->add_temp("apply/attack", -extra);
        	me->add_temp("apply/damage", -extra);
        	me->perform_busy(2);
    	}	
    	else	{	  		
   			
   			me->add_temp("apply/attack", extra);
        	me->add_temp("apply/damage", extra);
        	msg = HIR"\n$N"+HIR"������ң����е�"+weapon->query("name")+
            		HIR"���ȣ���һ����������������$n"NOR+HIR"��ȥ��\n" NOR;
        	message_vision(msg,me,target);
        	COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
               	
        	msg = HIR"\n$N"+HIR"�������������һ�������е�"+weapon->query("name")+
            		HIR"���ž���֮����$n"NOR+HIR"�����ȥ��\n" NOR;
        	message_vision(msg,me,target);
        	COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
        	me->add_temp("apply/attack", -extra);
        	me->add_temp("apply/damage", -extra);
        	
	    	busy = 2;
	    	super = me->query_skill("flying-dragon",1);
	    	if (super >=100) {
	    		super = (super-100)/10;
				if (random(100)<super && me->query_temp("yl9x_times") < 2 )	{
					me->add_temp("yl9x_times",1);
					message_vision(WHT"$Nһ�������³�������Ȼ˿�����Գ��͡�\n"NOR, me);
					busy = 0;
				} else {
					me->set_temp("yl9x_times",0);
				}
			}

        	me->perform_busy(busy);
   		}
	return 1;
}
