// tie@fengyun

#include <ansi.h>
#include <combat.h>
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
                return notify_fail("�۳��������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        weapon = me->query_temp("weapon");

        extra = me->query_skill("sword");
        me->add_temp("apply/attack", extra*2);  
        me->add_temp("apply/damage", extra*4);

        msg = HIR"\n$N"+HIR"ͻȻ΢Ц������������ס"+weapon->name() +HIR"��������ʱ�⻪�������ݳ���һ����û��" NOR;
        target->add_temp("combat_no_report",1);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        message_vision(msg,me,target);
        if (!target->query_temp("damaged_during_attack"))
                message_vision(HIY"\n$n"HIY"�������������ձܿ����ǵ����纮�⡣\n\n"NOR,me,target);
        else
        {
                message_vision(HIR"\nֻ��$n��ǰ��ɢ��һƬ��Ѫ���·���ͥ�л���ҡ���������̣��羡��Ϣ�������زк졣\n"NOR,me,target);
                COMBAT_D->report_status(target);
        }
        target->add_temp("combat_no_report",-1);

        me->add_temp("apply/attack", -extra*2);
        me->add_temp("apply/damage", -extra*4);
        me->perform_busy(2);
        return 1;
}

