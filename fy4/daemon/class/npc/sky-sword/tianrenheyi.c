// ���������콣���ľ��С����˺�һ��
//	hehe, ��һ��NPC���е�skill��

#include <ansi.h>

inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int delay;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�����˺�һ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
	if((int) me->query_skill("sky-sword",1) < 200 && userp(me))
		return notify_fail("������콣�����������������ܷ��������˺�һ����\n");
	
	delay=2+random(2);
	message_vision(HIG"$N�������ֹˮ������������ء�\n"NOR,me,target);
        me->start_call_out( (: call_other, __FILE__, "kill_him", me, target :), delay);
	me->start_busy(5);
	return 1;
}


void kill_him(object me, object target)
{
	int targetexp,damage,mylevel,myexp,targetkee;
	string msg;
	if(me->is_fighting() && target->is_fighting() && environment(me) == environment(target))
	{
		msg = HIY "\n$N���ѻ����˫��ٿ�������������޿�����ľ�â����Ȼʹ����ر�ɫ��һ�С����˺�һ����
��������������磬��������֮���������˰�����$n���Ŀڣ�" ;
		targetexp=target->query("combat_exp");
		myexp=me->query("combat_exp");
		mylevel=me->query_skill("sky-sword", 1)/2;
		targetkee=target->query("max_kee");
	
		damage=targetkee*(75+random(mylevel))/100;
		if(random(myexp*2+targetexp)>targetexp)
			msg += HIR "\n$nֻ������һ����$N�Ľ����Ѿ�͸����롣\n" NOR;
		else {
			msg+=HIR "\n$n�͵�һ�����ǳ��Ǳ��Ķ����$N����һ������ȴ�޷��������Ľ�����\n"NOR;
			damage=damage/2;
	     	}
		target->receive_wound("kee",damage, me);
		message_vision(msg, me, target);
        	target->set_temp("damaged_during_attack", 1);
		COMBAT_D->report_status(target);
		target->set_temp("last_damage_from",me);
	}
	me->start_busy(1);
	return ;
}
