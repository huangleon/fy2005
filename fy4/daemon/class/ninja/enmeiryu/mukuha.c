//mimicat@fy4

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int begin_perform(object me,object target);
int perform(object me, object target)
{
        string msg;
        int extra, exp_bonus;

        if(userp(me))
		return notify_fail("����ѡ�õ��书��û�����ֱ�ɱ������\n");  
        
        extra = me->query_skill("enmeiryu",1);
        if(extra<50) return notify_fail("�޿ղ���Ҫ50����½��Բ����ȭ��\n");
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�޿ղ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	extra = me->query_skill("enmeiryu",1) + F_LEVEL->get_level(me->query("combat_exp"))*3/2;
	
        if(!me->query("mark/true_mukuha")||userp(me)) 
        {
                me->add_temp("apply/attack", extra);    
        	me->add_temp("apply/damage", extra);
               	msg=HIR"$N�Ƶ��۽�$n��˫ȭ����$n���·��ϣ���˫ȭ�Ӵ������һ˲��
ʹ����½��Բ�������ذ��塺�޿ղ�����\n"NOR;
               	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        	me->add_temp("apply/attack", -extra);
        	me->add_temp("apply/damage", -extra);
        	me->perform_busy(2);
        	return 1;
        }
        
//	��perform����Ϸ���в����ڡ�        
        message_vision(CYN"$N�Ƶ��۽�$n��˫ȭ����$n���·��ϣ���$n�Ķ�������˵��\n"
HIR"����Ҫ�����Ѫ������Ⱦ�죡���� \n"HIG"
�����h����$n������$N��һ�С� 
$n���ɵؽ����峯�Ա�����һ�磬���������$N��һ���� \n"NOR,me,target);
	me->start_busy(4);
    	call_out("begin_perform",4,me,target);
        return 1;
        
}     


int begin_perform(object me,object target)
{
	
        if( !target || environment(target)!= environment(me)) return 0;

	message_vision(HIR"$NͻȻ�����ؿ�һ���ʹ��������ǰһ�ڡ� \n"NOR,target);
	if (environment(me)==environment(target))
	{
		tell_object(target,HIR"�����ǻ��֮�ʣ�������Լ����"+me->query("name")+"�Ļ������޿ղ��Ƕ㲻���ģ���\n"NOR);
		tell_object(me,HIC"����"+target->query("name")+"�Ķ�������˵�������޿ղ��Ƕ㲻���ģ���\n"NOR);
	}
	target->unconcious();			
        return 1;
}
