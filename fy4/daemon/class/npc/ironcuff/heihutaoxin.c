#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra, exp_bonus, extra_dam,n,m;
                
        extra = me->query_skill("ironcuff",1);
        if( extra < 100 ) 
                return notify_fail("��Ļ�����������ʵ���ò������ڻ����ġ���\n");

        if( me->query("class") || me->query("once_menpai"))
        	return notify_fail("��������ţ�����ƽ�������ȭ������ܿ������ۣ�\n");

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���ڻ����ġ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        
        if (me->query("force") < 500)
                return notify_fail("�������������ʹ�����ڻ����ġ���\n");
        if (userp(me))
                me->add("force",-500);
        if (userp(me))
                m=6;
        else
                m=8;
        
        msg = "$N���һ����ʹһ��ƽƽ����ġ�"BLINK"�ڻ�����"NOR"������׼$n���Ŀڡ������ؾ���һȭ��";
        n=1;

        if (me->query_temp("timer/ironcuff_heihutaoxin")+ m >time())
        {
                if (me->query_temp("annie/hhtx") == 1)
                {
                        msg = "$N��ȭ�ݳ����������գ�����ƽƽ����ġ�"BLINK"�ڻ�����"NOR"������׼$n���Ŀ�����һȭ��";
                        n=2;
                        extra*=4;       // 200 / 400
                }

                if (me->query_temp("annie/hhtx") == 2)
                {
                        msg = "$Nһ���Ϻȣ�˫���뷭��ƽƽǰ�ݣ��������С�"BLINK"�ڻ�����"NOR"����������$n���Ŀڴ�ȥ��";
                        n=0;
                        extra*=7;       // 350 / 700
                }
        }
        me->set_temp("annie/hhtx",n);

        me->add_temp("apply/attack",extra/2);
        me->add_temp("apply/damage",extra);
        
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        
        me->add_temp("apply/attack",-extra/2);
        me->add_temp("apply/damage",-extra);
        
        me->perform_busy(3-n);
        me->set_temp("timer/ironcuff_heihutaoxin",time());

        return 1;
}


/*

����Ц�������۹⡣
������������һ����ɽ��ȭ���ս��ľ���������֮���׵���ʽ���Ȳ����ɣ�Ҳ���ÿ���
Ȼ������֮���Գ�Ϊ���У�������Ϊ���ã����Գ���Ҫ�ã��ö��˴�Ҷ��ᣬ��˶���ϣ�档
��ѧ��ʦ���޲����Դ��书��������ʽ����׷�����ɣ������˷��ӹ���ı��⡣
����ν��ǿ����ǿ������ɽ�ڣ����������ᣬ�����մ󽭣��浽��ս��֮�ϣ�ʲô������Ҳ����ȥ�ܣ�
ֻҪ����ʵʵ��һ��һʽ������ɽ��ȭ��������ɵ�������æ���ҡ�


*/
