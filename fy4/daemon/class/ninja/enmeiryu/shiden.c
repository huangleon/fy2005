//mimicat@fy4

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        int extra,i;
	string *perform_msg=({
	YEL"$N�����ڵ���һ�ţ����岻��˼����ٴε���˫�ŵ���$n��ϥ�ؽڡ�\n"NOR,
	YEL"$N��������֮�ƣ��ٴ�ת������Ѹ�ײ����ڶ�֮�ƣ�ɨ��$n�ľ�����\n"NOR,
	YEL"$N�߸�Ծ�𣬿���һ��š������Ȼ�Խ������͵���$n��ͷ��ն��������\n"NOR,
	YEL"$N�͵شӲ���Ծ��$n������$n��֪����֮ʱ��һ����������$n�����š�\n"NOR,
	});

        extra = me->query_skill("enmeiryu",1);
        if(extra<100) 
        	return notify_fail("���ϵ������š���Ҫ100����½��Բ����ȭ��\n");

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���ϵ������š�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	
	message_vision(HIY"$NͻȻһЦ��������$n����ǰһ�Σ�Ծ����һ�ࡣ$nһʱ�޷�����$N����Ӱ�� 
		��	��	��	��	�� \n"NOR,me,target);
	
	extra = me->query_skill("enmeiryu",1) / 2;
	
	me->add_temp("apply/attack", extra);    
    me->add_temp("apply/damage", extra);		
	
	for(i=0;i<4;i++){
		msg = perform_msg[i];	
        	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	}
	
	me->add_temp("apply/attack", -extra);
    me->add_temp("apply/damage", -extra);
	
	me->perform_busy(3);        	

        return 1;
        
}     
