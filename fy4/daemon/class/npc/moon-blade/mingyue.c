#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        string dodskill,msg;
        int extra, busy,busy2,pp=0,pd=0;
        object weapon;
        
        if( !target ) target = offensive_target(me);
        if( !target
        || 		!target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�����¼�ʱ�С�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_skill("moon-blade",1) < 100 && userp(me))
                return notify_fail("���Բ��ħ�����������������ܳ����¼�ʱ�У���200������\n");
        
        extra = me->query_skill("moon-blade",1)*2;
	
        message_vision(HIW"\n\n$N"HIW"���һ����������$n"HIW"��ǰһ����
"HIR BLK"��Ȼ˭Ҳû�п������ô���£���˭�����Ըо�����$N"HIR BLK"��Ȼ������
"HIY"����������	��	��	ʱ	�С�����\n"NOR,me,target);

        pp=random(random(random(random(extra*40))))+1;
        pd=700+random(random(random(random(random(extra*80)))))+1;
        // �����ȶ�������С������ֳ����˺���
        me->add_temp("apply/attack",pp);
        me->add_temp("apply/damage",pd);        
	    COMBAT_D->do_attack(me,target,TYPE_PERFORM,"");
        me->add_temp("apply/attack",-pp);
        me->add_temp("apply/damage",-pd);       

        me->perform_busy(2);
        return 1;
}
