#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        
        extra = me->query_skill("unarmed");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�����ա�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        
        me->add_temp("apply/attack",extra/7);
        me->add_temp("apply/damage",extra/2);
        
        msg = HIG  "\n$N�������һ����Ҷ�࣬һ�ѽ���Ƥ�ƴ��׿������ž��˹���$n��һ���������裺\n" NOR;
        message_vision(msg,me,target);
        msg = HIC    "��������һ������أ�\n����������������������������ĸ��ۡ�\n" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIY  "������Ȼ��������\n�����������������������Ϸ���衣\n" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIW  "���������辡����Ц��\n��������������������������������Σ�\n" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIR   "������������·��\n����������������������������û��\n" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        if (me->query_busy()<3) 
                me->start_busy(3);
        me->add_temp("apply/attack",-extra/7);
        me->add_temp("apply/damage",-extra/2);
        return 1;
}

