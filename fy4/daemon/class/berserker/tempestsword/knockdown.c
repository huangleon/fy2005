
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra, myexp, hisexp,flag;
	object weapon;
	mapping buff;
	
	extra = me->query_skill("tempestsword",1) ;
	if (extra < 100) 
		return notify_fail("��Ŀ������н����������죡\n");

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��һʽֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
	weapon = target->query_temp("weapon");
	myexp  = me->query("combat_exp");
	hisexp = target->query("combat_exp");
	
	if (COMBAT_D->do_busy_attack(me, target, "tempestsword/knockdown", "step", 300, 10)
    	&& weapon && !weapon->query("nodrop_weapon")
    	&& target->query_temp("marks/disarmed") + 60 < time())  		
	{
		message_vision(HIG "\n\n$N"HIG"ʹһʽ����紵��Ӣ���Ρ�������"+me->query_temp("weapon")->name()+HIG"��������к��������"+ 
		weapon->name()+  HIG"��ó������\n" NOR, me,target);
		if( weapon->unequip()){ 
			buff =
				([
					"caster":me,
					"who":  target,
					"type":"disarmed",
					"att":"curse",
					"name":"�������н���������Ӣ����",
					"buff1":"disarmed",
					"buff1_c":1,
					"time":  30,
					"buff_msg":" ",			
				]);
			ANNIE_D->buffup(buff);
		}			
		flag=1;
	}

	target->set_temp("marks/disarmed",time());

	if (flag == 1)
		msg=HIY"������"HIY"�ֽ�$wһ��һת"HIY"��һʽ���ɰ����䲻���ġ���մ���$n"HIY"��"NOR;
	else
		msg=HIY"$N"HIY"���е�$w"HIY"һ����һʽ���޿ɱܵġ��ɰ����䲻���ġ���$n��ȥ"HIY"��"NOR;
	
	me->add_temp("apply/attack", extra);
	me->add_temp("apply/damage", extra*2);
	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra*2);

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
