// TIE@FY3
#include <ansi.h>
inherit SSERVER;
int cast(object me, object target)
{
    	string msg;
    	int ap, dp,myexp;
    	mapping buff;
    	
    	if(!me->is_fighting())
		return notify_fail("���ź�����ֻ������ս����ʩչ��\n");
    	
    	if((int)me->query_skill("mapo", 1) < 100 )
        	return notify_fail("������ź����������ߣ�\n");
    
    	if( !target ) target = offensive_target(me);
    	if( !target
		||!target->is_character()
		||target->is_corpse()
		||target==me)
        	return notify_fail("��Ҫ��˭ʩչ���������\n");

    	if (ANNIE_D->check_buff( target,"freeze"))
    		return notify_fail("�����ڲ�����Ҫʩչ���ź�������\n");

    	if((int)me->query("mana") < 100 )
        	return notify_fail("��ķ���������\n");

    	if((int)me->query("sen") < 50 )
        	return notify_fail("��ľ���û�а취��Ч���У�\n");

    	if (userp(me)) 	me->add("mana", -100);
    	if (userp(me))	me->receive_damage("sen", 50);
    
    	msg = HIW "\n$N˫��һ�ۣ��γ�һ������ĺ�������$n������\n\n"NOR ;
    	message_vision(msg, me, target);
    
    	ap = me->query_skill("mapo",1);
    	myexp = me->query("combat_exp");
    	ap = ( ap * ap /100 * ap/40 ) * (int)me->query("sen") ;
    	dp = target->query("combat_exp");
    
    	if (random(ap + dp) > dp )
    	{
		buff =
		([
			"caster":me,
			"who": target,
			"type":"freeze",
			"att":"curse",
			"name":"���ź�����������",
			"buff1": "disable_inputs",
			"buff1_c":1,
			"buff2":"is_unconcious",
			"buff2_c":1,
			"disable_type": HIW "<������>" NOR,
			"time":  10,
			"buff_msg": YEL"$N��ܲ���������һ���������Ǹ��˷���Ѩ��һ�㡣\n"NOR,
			"disa_msg": HIR "\n\n$N����һ��ŭ��˫��һ�񣬽��������۵ı�����÷��飡��\n\n" NOR,
			"disa_type": 1,
		]);
		ANNIE_D->buffup(buff);
				
		/*
		msg +="����ĺ�����Χ��$n��ȫ����$n���۳ɱ��飡\n";
        	target->set_temp("disable_inputs",1);
        	target->set("disable_type",HIW "<������>" NOR);
        	target->set_temp("is_unconcious",1);
        	target->start_call_out( (: call_other, __FILE__, "remove_frozen",target :),10);*/
    	} else  {
    		msg = "���Ǳ�$n�㿪�ˡ�\n";
        	message_vision(msg+NOR, me, target);
    	}
    	me->perform_busy(2);
    	return 1;
}

/*
void remove_frozen(object me)
{
    	me->delete("disable_type");
    	me->delete_temp("disable_inputs");
    	me->delete_temp("is_unconcious");
    	if(!me->is_ghost())
		message_vision(HIR "\n\n$N����һ��ŭ��˫��һ�񣬽��������۵ı�����÷��飡��\n\n" NOR, me);
}

*/
