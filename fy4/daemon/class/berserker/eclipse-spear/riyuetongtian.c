#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        int extra;
        object *pros;
        extra = me->query_skill("eclipse-spear",1);
        if ( extra < 150) return notify_fail("���˷����ǹ���������죡\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail(HIC"����ͬ��"NOR"ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        
        msg = HIC"$N"HIC+me->query_weapon()->name()+"է�����У�һ��������ͬ�죢��ǹӰ���ش���ɭɭ��������ͷ������к���¡�\n"NOR;
		message_vision(msg, me, target);
		
        me->add_temp("apply/damage", extra);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
        me->add_temp("apply/damage", -extra);

        if (target->query_temp("damaged_during_attack"))
        {
                me->perform_busy(3);
                return 1;
        }

        if (me->is_busy())
        {
                me->perform_busy(3);
                return 1;
        }

        message_vision(HIW"$n"HIW"��סһ�У������ˣ���ͼ����$N���๥�ơ�\n",me,target);

        msg = HIC"$N"HIC+"������׷����Ӱ���θ���ȥ����ģ������ԭ�ⲻ������һ��������ͬ�죢��\n"NOR;
		message_vision(msg, me, target);
		
        me->add_temp("apply/damage", extra*3);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
        me->add_temp("apply/damage", -extra*3);

        if (target->query_temp("damaged_during_attack"))
        {
                me->perform_busy(3);
                return 1;
        }

        if (me->is_busy())
        {
                me->perform_busy(3);
                return 1;
        }

        message_vision(HIW"$n"HIW"�������ߣ��������ɣ�����������·��\n",me,target);

        msg = HIC"\n$N"HIC+"����ǹ�ֵ������ǾӸ����£����ǳ�����Ӱ㹥����������ʽ������ͬ�죢��"NOR;
        message_vision(msg,me,target);

        msg = BRED HIW"����������������������������������������������������������������������\n";
        msg += "�����������ա����¡���ͬ�����졡���������ˡ����ޡ����ɡ����ˡ���������\n";
        msg += "����������������������������������������������������������������������"NOR;

        target->add_temp("is_unconcious",1);
        pros = target->query_temp("protectors");
        target->delete_temp("protectors");
        
        me->add_temp("apply/damage", extra*8);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/damage", -extra*8);

        target->add_temp("is_unconcious",-1);
        target->set_temp("protectors",pros);

        target->stop_busy();    // Cancel Busy.
        msg = HIR"$N"HIR"��ɫɷ�ף�˫���Ͼ٣��Ȼ�������������ܾ��ˣ�"NOR;
        
        me->add_temp("is_unconcious",1);
        pros = me->query_temp("protectors");
        me->delete_temp("protectors");
        
        target->add_temp("apply/damage", extra*7);
        COMBAT_D->do_attack(target,me, TYPE_PERFORM,msg);
        target->add_temp("apply/damage", -extra*7);

        me->add_temp("is_unconcious",-1);
        me->set_temp("protectors",pros);
                
        me->perform_busy(3);

        return 1;
}


/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/

