
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
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�����١�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_skill("beilongblade",1) < 200 && userp(me))
                return notify_fail("��Ա����������ղ��㣬�޷�ʹ�á����١���\n");
        
        extra = me->query_skill("blade");

        msg = HIR BLK"\n$N";
        msg +=HIR BLK"�����Ȼ�������������г�����һ˲����Ȼ���ʣ�����������Ҳ�����ϵ��Ĺ켣��\nֻ�ܼ���һ����ɫ����Ӱ���ŵ���������������ڳ���ն���Ŀռ�������·�ͻȻ\n��˺�飬����ѹ�������������Х�У�һ��ƥ���Ƶļ�������$N"HIR BLK"����̤��ǰն�Ķ�����\n���޿��赲֮�ƴ�Խ������\n\n";
        msg += HIB"�������������������������������󡡺ס��١��١���\n\n"NOR;

        pp=random(random(random(random(extra*40))))+1;
        pd=random(random(random(random(random(extra*80)))))+1;
        // �����ȶ�������С������ֳ����˺���
        me->add_temp("apply/attack",pp);
        me->add_temp("apply/damage",pd);        
		message_vision(msg, me, target);
		
    COMBAT_D->do_attack(me,target,TYPE_PERFORM,"");

        me->add_temp("apply/attack",-pp);
        me->add_temp("apply/damage",-pd);       

        me->perform_busy(2);
        
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

