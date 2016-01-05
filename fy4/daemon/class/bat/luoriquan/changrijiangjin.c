#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        int extra,i,bonus;
        object *inv,skin;

        if (!me->query("fy41/luori_changrijiangjin") && userp(me))
                return notify_fail("����ѡ�õ��书��û�����ֱ�ɱ����\n");

        if (userp(me) && me->query_skill("luoriquan") < 220)
                return notify_fail("�����ս�������Ҫ220��������ȭ��\n");

        extra = me->query_skill("unarmed");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�����ս�����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        
        if (!me->query_condition("drunk") && userp(me))
                return notify_fail("��һ˿����Ҳû�У�����ʩչ�����ս�������\n");

        if (userp(me))
        {
                inv = all_inventory(me);
                for (i=0; i<sizeof(inv);i++ )
                {
                        if (!inv[i]->query("liquid/name"))      continue;
                        if (inv[i]->query("liquid/type") != "alcohol")  continue;
                        skin=inv[i];
                }
                if (!skin)
                        return notify_fail("����û�о���������ܹ�����ʩչ�����ս�������\n");
                msg = HIG "\n$N"HIG"�������һ��"+skin->query("liquid/name")+HIG"��һ�ѽ�"+skin->name()+HIG"�׿������ž��˹���"HIG"$n���������裺\n" NOR;
                destruct(skin);
        }
        else
                msg = HIG "\n$N�������һ������嫺���һ�ѽ����«�׿������ž��˹���"HIG"$n���������裺\n" NOR;

        if (userp(me))
                bonus = me->query_condition("drunk");
        else
                bonus = me->query_skill("luoriquan",1);

        bonus *= 2;

        me->add_temp("apply/attack",bonus);
        me->add_temp("apply/damage",extra/3);
		target->set_temp("no_check_pfm_win",1);
		
        message_vision(msg,me,target);
        msg = HIM    "����������������һ������أ�\n������������������������������������ĸ��ۡ�\n" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        target->set_temp("skip_damage_record",1);
        
        msg = HIC  "������������Ȼ��������\n�����������������������������Ϸ���衣\n" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIY  "�����������������辡����Ц��\n����������������������������������������Σ�\n" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIW   "����������������ʱ·��\n����������������������������������û��\n" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIR   "\n�����������������������գ�����������������������\n\n" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);

        me->add_temp("apply/attack",-bonus);
        me->add_temp("apply/damage",-extra/3);

		if (objectp(target))	{
			if (target->query_temp("damaged_during_attack")) 
				 COMBAT_D->win_lose_check(me,target,1);
		}
	
		if (objectp(target))	{
			target ->delete_temp("no_check_pfm_win"); 
			target->delete_temp("skip_damage_record");
		}

        me->perform_busy(3);
        return 1;
}


/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/

