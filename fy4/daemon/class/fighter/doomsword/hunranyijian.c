// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
    	string msg;
    	int extra, skill, damage;
    	object weapon;
    	
    	if( !target ) target = offensive_target(me);

    	if( !target
	||!target->is_character()
	||!me->is_fighting(target) )
        	return notify_fail("����Ȼһ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    	
    	weapon = me->query_temp("weapon");
    	skill=me->query_skill("doomsword",1);
    	
    	if(skill < 130 && userp(me)) {
	// 	130+random(130)
		extra = skill + random(skill);
		damage = extra;
        	msg = HIR  "$N"HIR"����ǰ�����е�"+ weapon->name()+ HIR"һʽ����Ȼһ��������â�������޵���$n"+HIR"��ȥ��" NOR;
    	}
    	else    {
	// 	260+random(260)
	  	extra = skill + random(skill);
	  	damage=extra*3/2;	
	  	if (me->query("class")=="fighter") damage = extra*5/2;
        	msg = HIR "$N"HIR"����ǰ�����е�"+ weapon->name() + HIR"һʽ����Ȼһ��������Ѫ��ɫ�Ľ�â,��$n"+HIR"��Χ�����У�" NOR;
    	}
    	
    	me->add_temp("apply/attack", extra);	
    	me->add_temp("apply/damage", damage);
    	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
    	me->add_temp("apply/attack", -extra);
    	me->add_temp("apply/damage", -damage);
    	
    	me->perform_busy(2);    	    	
    	return 1;
}

