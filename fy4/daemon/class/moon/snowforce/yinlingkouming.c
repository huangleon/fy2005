#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int exert(object me, object target, int amount)
{
	int skill,duration,duration2;
	string msg;
	mapping buff;
	int extra,my_exp,his_exp;
	int mod;

	if (me->query("class") != "moon")
		return notify_fail("ֻ����¹����˲���ʩչ�������������\n");

	extra = me->query_skill("snowforce",1);		
	if (extra < 160 && userp(me))
		return notify_fail("�������������Ҫ����160������ѩ�ľ���\n");

	if( !target ) target = offensive_target(me);
	if( target == me) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (ANNIE_D->check_buff(target,"soft_damage"))
       	return notify_fail("�Է��Ѿ��ܵ������Ƶ�Ӱ�졣\n");

	mod = COMBAT_D->can_busy(me, target, "snowforce");	
	if (!mod)
		return notify_fail(HIW"���˹�����տ��ó�ô��пַǵ��֡�\n"NOR);

	msg = CYN "\n���ƴ��ٴ�أ��������棬һ���������������ů��������������$N��\n"NOR;
	message_vision(msg,target);
	
	duration2 = 20 + F_ABILITY->check_ability(me,"ylkm_add"); 
	
	if (!COMBAT_D->do_busy_attack( me, target, "snowforce/yinlingkouming","step", 200, mod))
	{
		msg = YEL "$N"NOR+YEL"����һ���������ֱ����£�����ʹ�����ѹ�����\n"NOR;
		message_vision(msg,target);
	}
	else
	{
    	msg = WHT "$N"WHT"˯�����࣬����һ���Ƴ��ĺ�Ƿ���ֽŷ�������������\n\n" NOR;

    	buff =
		([
			"caster":me,
			"who": target,
			"type":"soft_damage",
			"att":"	curse",
			"buff1":"soft_damage",
			"buff1_c": 1,
			"name":"��ѩ�ľ����������",
			"time":  duration2,
			"buff_msg": msg,
			"disa_msg": HIG"$N����һ�𣬾���������ࡣ\n"NOR,
			"disa_type": 1,
		]);
		ANNIE_D->buffup(buff);	
	}
	
	target->set_temp("busy_timer/snowforce",time());
	me->perform_busy(1);
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
