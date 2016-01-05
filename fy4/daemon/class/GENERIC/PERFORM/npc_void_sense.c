// void_sense.c

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
 	int skill;
 	int my_exp,his_exp;
 	object *enemy;

	if(userp(me))
		return notify_fail("����ѡ�õ��书��û�����ֱ�ɱ������\n");
		 	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�ۿ�ʶ��ͨ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    	
    	if( (int)target->query_temp("voidsense") ) 
    		return notify_fail("�����Ѿ������ˣ�����ץ��ʱ��������\n");
    	
    	message_vision(HIY "$N˫�ֺ�ʮ����ü���ף��������� ...\n" NOR, me);
	skill= (int) me->query_skill("essencemagic",1);

	message_vision(HIW"$N��ͷһ����ֻ���������½�Ϊ�������ƣ����β�������������\n"NOR, target);
	target->add_temp("apply/dodge", -skill);
	target->add_temp("apply/parry", -skill);
	target->add_temp("apply/attack",-skill);
	target->set_temp("voidsense", 1);
	target->start_call_out( (: call_other, __FILE__, "remove_effect", target, skill :), skill/4);
	return 1;
}

void remove_effect(object target, int amount)
{
        target->add_temp("apply/dodge", amount);
        target->add_temp("apply/parry", amount);
        target->add_temp("apply/attack", amount);
        target->delete_temp("voidsense");
        message_vision(HIR"$N����һ�ݣ��������γ��ѡ�\n" NOR, target);
}
 
    
    
    