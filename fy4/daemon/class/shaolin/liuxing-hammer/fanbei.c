// Silencer@fengyun	June.2005
//	+atk 85. +dmg 0;

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra,n;
	
	if (me->query("class") != "shaolin")
		return notify_fail("�������������������ֵ��ӵľ��С�\n");
	
	extra = me->query_skill("liuxing-hammer",1);
	if (extra < 50) 
		return notify_fail("��������������������Ҫ�������ķ�ת���Ǵ�����\n");
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��������������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
	msg = BBLU+HIY  "$Nʹ�����Ǵ����еġ���������������������ˣ���ط�����һ����\n" NOR;      	
    message_vision(msg, me, target);
    
        	me->add_temp("apply/attack",extra*3/2);
        	COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
        	me->add_temp("apply/attack",-extra*3/2);
			
	if (extra >= 80) {
		msg = BBLU+HIY  "$N����һ�У���������һ������\n" NOR;
    	message_vision(msg, me, target);
        	me->add_temp("apply/attack",extra*3/2);
        	COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
        	me->add_temp("apply/attack",-extra*3/2);
    }	
   
   if (extra >= 110) {
        msg = BBLU+HIY  "$N��Ȼ������ͷ������һ������һ����\n" NOR;
        message_vision(msg, me, target);
        me->add_temp("apply/attack",extra*3/2);
		COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
		me->add_temp("apply/attack",-extra*3/2);
	}
        
	me->perform_busy(2);
	return 1;
}
