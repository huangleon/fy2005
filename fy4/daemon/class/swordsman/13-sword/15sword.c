 
#include <ansi.h>
 
inherit SSERVER;
 
int perform(object me, object target)
{
        string msg;
        int extra;
        object weapon;
        if( !target ) target = offensive_target(me);
 
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��ֻ�ܴ�ս����������ʮ�������ġ���ʮ��ʽ��\n");
 
        extra = me->query_skill("13-sword",1) ;
        if ( extra < 140) return notify_fail("�㻹û���������ʮ�������ġ���ʮ��ʽ��\n");

        msg = WHT"$N�����Ȼ����������𶯡����Ȿ����ббָ��$n����һ�������Ȼ��ȫ����ֹ��\n������Χ�Ŀ��������ݷ�Ҳ��ͣ�١� "
RED"\nû���κ���������������������ֻ��һ����...\n\nһ���ܼ򵥵��֡������� \n"HIB"��ˮǬ�ݣ��仯��������սᣬ����������\n"NOR;
	weapon=me->query_temp("weapon");
        message_vision(msg, me, target);
        me->start_call_out( (: call_other, __FILE__, "kill_him", me, target,weapon :), random(5)+6);

        me->start_busy(6);
        target->start_busy(4);
        return 1;
}
        
void kill_him(object me, object target,object weapon)
{
        string msg;
        int extra;

        extra = me->query_skill("13-sword",1) ;
        if(extra>160){extra=160+random((extra-160)/4);}
        if(random(extra-140)>5  ) {
        if(me->is_fighting() && target->is_fighting() &&
	        environment(me) == environment(target))
		{
                msg = RED"��$N����"+weapon->name()+"��ʼ��������ʱ��$n�������ˣ����޷������κα仯�� \n"NOR;
                message_vision(msg, me, target);
                target->set_temp("last_damage_from",me);
		target->die();
            
		}
        } else {
                msg = HIR"$Nһ��ʧȥĿ�꣬��Ȼ�������·𱻳���"+weapon->name()+"��Ҳ�޷����ƣ� "
 RED"\nһ��ɱ����"+weapon->name()+"���ܻ�������һ������$N���ࡣ "
 RED"ֱ��$N����ȥ��ֱ��$N��������ֹͣ��������ͣ�٣�$N�����"+weapon->name()+"�����𶯲�ͣ�� "NOR;
                message_vision(msg, me, target);
                me->die();
        }
        
        return ;
}
