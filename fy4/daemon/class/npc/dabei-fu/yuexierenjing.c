
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

        string *event1_msg=     ({
        CYN"\n����֮�У���ִ�ų����������裬���˷·���������֮���£�ƮƮ��������֮��ѩ��\n�����Ƿ��浶����һʽ�������ѩ��\n"NOR,
        MAG"\n�������ɵ�Ʈת����������ı�����ǳǳ���£��������ﻨ�䡣\n�������ﻨ�������һ����\n"NOR,
        RED"\n���ֻ������������г���"RED"�����񶯣�ʹ���ˣ���Ӱҡ�죢��\n�����ӳ���£���Ӱ������Ӱ���ڷ���ҡ�ڲ�����\n����������һĨ�ʺ���������ŵ�Ӱ���䡣\n"NOR,
        WHT"\n�轥����ֹ�ˣ�����ǰ��һ�ж�������ȥ�����ڵ�Ω��������ǹ���¼ŵ����¡�\n����������粻��������������顣�ϸ�ɢ��Ƴ��ѡ���\n��Ժ��б�˾���\n"NOR,
        });

int perform(object me, object target)
{
//      object weapon;  it' a unarmed perform now * mingyue
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("����б�˾���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

//      weapon = me->query_temp("weapon");
        message_vision( WHT "$NէȻ������������������������ɫ�����޷��ҵĵ��⣬���޷ɽ�����Ѫ��\n" NOR, me,target);
    call_out("do_yuexie", 1, me,target,0/*,weapon*/);

        me->start_busy(2);

        return 1;
}

int do_yuexie(object me,object target,int count/*,object weapon*/)
{
        if(!me||!target||!me->is_fighting(target)||environment(target)!=environment(me))
                return 0;
//      if(!present(weapon,me)||weapon->query("equipped")!="wielded")
//              return 0;
//      tell_object(me,"i="+count+event1_msg[count]);
        me->stop_busy();
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,event1_msg[count]);
        me->start_busy(2);
        if (count < 3)
        {
                count++;
            call_out("do_yuexie", 1, me,target,count/*,weapon*/);
        }
        return 1;
}


