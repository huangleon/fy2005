#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int do_pfr(object me, object target);

int do_pfm(object me, object target,int idx)
{
        string msg;
        int l;

        string *style = ({
"������Ұ����$N�ն�����$w�������Х������$n��$l��",
"�������ѣ���$N����$w������Ӱ���أ���$n����Χס��",
"��ֹ��Ұ����$N��ǰһ�ݣ�����$w���裬��$n���˹�ȥ��",
"���Σ���$N������������$wͷβ������ִ�$n������Ҫ����",
"�Ϻ����죭��$N����$wһ�٣���������������$n��$l��",
"Գ�Σ���$N����������Ծ������$w���ƶ�����������$n��ȥ��",
"���Σ���$N��Ӱ����$n�����ζ�������$w������ɨ��$n��$l��",
"ӥ�Σ���$N������������$w���϶��£�Ѹ���ޱȣ�����$n��$l��"});

        if(!me||!target||!me->is_fighting(target)||environment(target)!=environment(me))
                return 0;

        msg = HIY+style[idx]+NOR;

        me->stop_busy();
        l = target->query("kee");
    COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        if (me->is_busy())
                return 1;               // Parry busy
        me->start_busy(3);      
        if (target->query("kee") < 1)
                return 1;               // Unconcious / Dead
        if (l == target->query("kee"))
                return 1;               // Miss
        if (me->query("force") < 50)
                return 1;               // Miss
        me->add("force",-50);
        
        if (idx == 7)
        {
                message_vision(HIG"\n$N����ʹ��һ�֡�����˪�쾹���ɡ������ν����ȶ�������\n"NOR,me,target);
                call_out("do_pfr",1,me,target);
                return 1;
        }

        do_pfm(me,target,idx+1);
}


int do_pfr(object me, object target)
{

        message_vision(HIG"$N������һ�ڳ���������һ£���֣��ٴλ���һƬ��Ӱ����$n��࣡\n"NOR,me,target);
        call_out("do_pfm",1,me,target);
        return 1;
}

int do_pfx(object me, object target)
{
        message_vision(HIY"$N��Ȼ���һ����ʹ�������Ƕ��ǵ�һʽ������˪�쾹���ɡ���\n"NOR,me,target);
        do_pfm(me,target,0);
        return 1;
}


int perform(object me, object target)
{
        string msg;
        int extra;
        
        extra = me->query_skill("unarmed");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���λ����ޡ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

//      message_vision(HIY"$N����"+me->query_temp("weapon")->name()+HIY"�ڵ������㣬���ν�ɢ�������߰˸���Ӱ����$n�����˾��û����λá�"NOR);
        message_vision(HIG"\n$N����"HIG"������"HIG"�ڵ������㣬���ν�ɢ�������߰˸���Ӱ����$n��\n"NOR,me,target);
        call_out("do_pfx",1,me,target);
        return 1;
}


