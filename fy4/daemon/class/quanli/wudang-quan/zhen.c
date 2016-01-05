#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int level,extra,kee,i;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        level = (int)me->query_skill("unarmed");
        extra = (int)me->query("wudang/level");
        extra = (extra >=2000)? 2000:extra;
        if(!me->query("wudang/zhen")){ 
                me->add_temp("apply/attack",extra/20);
                COMBAT_D->do_attack(me,target,TYPE_PERFORM, 0);
                me->add_temp("apply/attack",-extra/20);
                me->start_busy(1);
                if (me->query("wudang/level") < 3000){
                        me->add("wudang/level",1);
                        if ((int)me->query("wudang/level")%100==0)
                                tell_object(me, HIW "�������ϰ������룬�������������ˡ�\n" NOR);
                }
                else if (me->query("family/master_id") == "master shi"){
                        me->set("wudang/zhen",1);
                        tell_object(me, HIW "�������ϰ������룬��������µı仯��\n" NOR);
                        me->set("wudang/level",0);
                }
                return 1;
        }else {
                if ( me->query_skill_mapped("force") != "taijiforce")
                        return notify_fail("�����������̫���ķ���ͣ�\n");
                me->add_temp("apply/damage",level/10);
                me->add_temp("apply/attack",level/20);
                kee = target->query("kee");
                msg = HIR "\n$N"+HIR"˫����Ȼһ��һ£��һ��������$n"+HIR"ײ����" NOR;
                COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
                me->add_temp("apply/damage",- level/10);
                me->add_temp("apply/attack",- level/20);
                msg =  HIW "��������һ����ɢ����ʧ������\n" NOR;
                message_vision(msg, me, target);
                for (i=0; i< (int)level/50 ;i++){
                        if( (int)target->query("kee") < kee ) { 
                                if (level>300){
                                        msg = HIY"$N"+HIY"һ�����У�˫��˳������һ����������$n"+HIY"�����ƣ�\n"NOR;
                                        message_vision(msg, me, target);
                                        target->start_busy(1);
                                        me->start_busy(1);
                                        call_out("nextattack",1,me,target);
                                        break;
                                }else{
                                        msg = HIY"$N"+HIY"һ�����У���$n"+HIY"���̽��Լ���ס��\n"NOR;
                                        message_vision(msg, me, target);
                                        me->start_busy(2);
                                        break;
                                }
                        }else {
                                kee = target->query("kee");
                                msg = HIY"$N"+HIY"˫��һ��һ����һ����������$n"+HIY"ײ����" NOR;
                                me->add_temp("apply/damage",level/10);
                                me->add_temp("apply/attack",level/20);
                                COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
                                me->add_temp("apply/damage",- level/10);
                                me->add_temp("apply/attack",- level/20);
                                msg =  HIW "��������һ����ɢ����ʧ������\n" NOR;
                                message_vision(msg, me, target);
                        }
                }
                if (i == (int)level/50 ){
                        message_vision(HIY"$N"+HIY"һ��"+chinese_number(i)+"ʽ��Ȼȫ��δ�У�����¶��������\n"NOR,me);
                        me->start_busy(5);
                }
                return 1;
        }
}

void nextattack(object me,object target)
{
        string msg;
        int damage;
        if(!target || (environment(target) != environment(me)) || !me->is_fighting(target)){
                return ;
        }else{
                msg = HIR"\n$N"+HIR"�Ų�һת��˳������$n"+HIR"�ڹ���һ�⼱��$n"+HIR"�ؿڣ�\n"NOR;
                message_vision(msg,me,target);
                damage = me->query("str") * me->query("str")/10;
                damage = (damage + random(damage))/2;
                target->receive_damage("kee", damage,me);
                msg = "���һ�����У�$n�ƺ���һ����Ȼ���˲�С�Ŀ���\n";
                message_vision(msg, me, target);
                target->set_temp("damaged_during_attack", 1); 
                COMBAT_D->report_status(target);
                me->start_busy(1);
                target->start_busy(1);
                call_out("nextattack1",1,me,target);
        }
}

void nextattack1(object me,object target)
{
        string msg;
        int damage;
        if(!target || (environment(target) != environment(me)) || !me->is_fighting(target)){
                return ;
        }else{
                msg = HIB"\n$n"+HIB"��������Ӧ��$N"+HIB"��һ�Ÿ�����˫����ס$n"+HIB"��ۣ�\n���һ���������۶ϣ�\n"NOR;
                message_vision(msg,me,target);
                damage = me->query("str");
                damage = damage + random(damage);
                target->receive_damage("kee", damage,me);
                target->receive_wound("kee", damage/4,me);
                msg = "���ֻ��$n����۷�����������һ�����죬�����ǹ����������$n����۵�ʱ�׵��ϸߣ�\n";
                message_vision(msg, me, target);
                target->set_temp("damaged_during_attack", 2); 
                COMBAT_D->report_status(target);
                me->start_busy(1);
                target->start_busy(1);
                call_out("nextattack2",1,me,target);
        }
}

void nextattack2(object me,object target)
{
        string msg;
        object room;
        int damage;
        if(!target || (environment(target) != environment(me)) || !me->is_fighting(target)){
                return ;
        }else{
                msg = HIY"\n$n"+HIY"���Լ䣬$N"+HIY"����ס$n"+HIY"����������������\n"NOR;
                message_vision(msg,me,target);
                me->start_busy(2);
                target->start_busy(2);
                room = environment(me);
                me->move(__DIR__"null");
                target->move(__DIR__"null");
                call_out("nextattack3",2,me,target,room);
        }
}

void nextattack3(object me,object target,object room)
{
        string msg;
        if(!target || (environment(target) != environment(me)) || !me->is_fighting(target)){
                return ;
        }else{
                me->move(room);
                target->move(room);
                msg = HIR"\n$N�ڿ��н�$n"+HIR"һ����ѹס$n"+HIR"��$n"+HIR"����ײ����棡\n"NOR;
                message_vision(msg,me,target);
                me->start_busy(1);
                target->start_busy(1);
                call_out("nextattack4",1,me,target);
        }
}

void nextattack4(object me,object target)
{
        string msg;
        int damage;
        if(!target || (environment(target) != environment(me)) || !me->is_fighting(target)){
                return ;
        }else{
                msg = HIW"\n�����䣡����\n"+HIR"$N"+HIR"ѹ��$n"+HIR"�������������£�\n"NOR;
                message_vision(msg,me,target);
                damage = me->query_skill("unarmed")*4;
                damage = (damage + random(damage))/2;
                target->receive_damage("kee", damage,me);
                target->receive_wound("kee", damage/2,me);
                msg = "���ֻ�����项��һ�����죬$n�����������һ�����ݰ���˳�ȥ����\n";
                message_vision(msg, me, target);
                target->set_temp("damaged_during_attack", 2); 
                COMBAT_D->report_status(target);
                me->start_busy(3);
        }
}
