#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
      	string msg;                                
        int extra;
	object target1, target2, *enemy;

	extra = me->query_skill("ill-quan",1);
	if ( extra < 150) 
		return notify_fail("��Ǭ��Ų�ơ���Ҫ150����άĦȭ��\n");


	enemy=me->query_enemy();
        if (sizeof(enemy)<2) 
        	return notify_fail("�����ͬʱ���������������ϵĵ���ս������ʹ��Ǭ��Ų�ƣ�\n");
        
        if( target) 
        	return notify_fail("��Ǭ��Ų�ơ�����Ҫָ�����֡�\n");
        
	target1=enemy[0];
        target2=enemy[1];
        
        if( !target1 || !target2
	||	!target1->is_character() || !target2->is_character()
	||	!me->is_fighting(target1) || !me->is_fighting(target2))
		return notify_fail("��Ǭ��Ų�ƣ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	
	if (me->query("force")<=100) 
		return notify_fail("����������㣬�޷��������˹��ƣ�\n");
		
        if (target1->query_busy() && target2->query_busy())
        	return notify_fail(WHT"����������æ���޷�������ʹ�á�Ǭ��Ų�ơ�\n"NOR);
        
        if (userp(me))	me->add("force",-100);
        
        message_vision(CYN"$Nʹ����άĦȭ�Ĳ���֮�ء�Ǭ��Ų�ơ�\n"NOR,me);
        me->start_busy(2);
        
        if (random(me->query("combat_exp")*(extra/30+1))>target1->query("combat_exp"))
        {
          message_vision(HIY "$N���ִ���$n�Ĺ��ƣ�ʹ֮����"+target2->name()+"��\n" NOR,me,target1);
          COMBAT_D->do_attack(target1,target2, TYPE_PERFORM, 0);  
          if(target2->query_temp("damaged_during_attack")) 
          		target2->receive_damage("kee",0,me);
          target1->force_busy(1);
        }
        else
        {
          message_vision(BLU"��$n����$N����ͼ�����Ʒ���������\n"NOR,me,target1);
          COMBAT_D->do_attack(target1,me,TYPE_PERFORM, 0);
        }
        
        if (random(me->query("combat_exp")*(extra/30+1))>target2->query("combat_exp"))
        {
          message_vision(HIY "$N���ִ���$n�Ĺ��ƣ�ʹ֮����"+target1->name()+"��\n" NOR,me,target2);
          COMBAT_D->do_attack(target2,target1, TYPE_PERFORM, 0);  
          if(target1->query_temp("damaged_during_attack")) 
          		target1->receive_damage("kee",0,me);
          target2->force_busy(1);
        }
        else
        {
          message_vision(BLU"��$n����$N����ͼ�����Ʒ���������\n"NOR,me,target2);
          COMBAT_D->do_attack(target2,me,TYPE_PERFORM, 0);
        }
        
     	return 1;
}
