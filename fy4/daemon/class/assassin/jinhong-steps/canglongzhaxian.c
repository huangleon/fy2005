// silencer@fengyun ����է�� ����ʱ��NPC, players ���� pfm,

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int lvl, duration, kee, mod, enhance;
	mapping buff;
		
	if (me->query("class")!="assassin")
		return notify_fail ("������է�֡�ֻ�н�Ǯ�������ʹ�á�\n");
	
	lvl= me->query_skill("jinhong-steps",1);
	if (lvl<80)
		return notify_fail("������է�֡���Ҫ����80����粽����\n");		
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("������է�֡�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	
	msg = HIR  "$N"+HIR"����һת��ͻȻ���η���˫����������ڿ�һ���͵���$n"+HIR"�߳���\n" NOR;
	message_vision(msg, me, target);
		
	if ((me->query_skill("jinhong-steps",1)>164 || !userp(me)) 
		&& random(201)>197
		&& !target->query("big_boss") && !target->query("boss") ) 
	{
		kee = target->query("kee");
		target->receive_wound("kee", kee/2, me);
		message_vision(RED"\n$n"+RED"һ���ҽУ���$N"+RED"�ߵÿ�����Ѫ��\n\n"NOR,me,target);
	}
	else
	{
		me->add_temp("apply/attack", lvl);	
		COMBAT_D->do_attack(me,target, TYPE_PERFORM, "", "����");
		me->add_temp("apply/attack", -lvl);		
	}		
	
	me->perform_busy(2);	
	mod = COMBAT_D->can_busy(me, target, "jinhong-steps");	
	if (!mod)	mod = 10000;
					
	// lvl = 160 *4 = 640	
	enhance = lvl* 4;
	if (COMBAT_D->do_busy_attack(me, target, "jinghong-steps/canglongzhaxian","step", enhance, mod))
	{
		msg=WHT"
$N���һ���������ڰ�գ�˫��������չ����糵һ�㣬��ʩ����
�������ȷ�ɨ����$n"WHT"�������ͣ�������ת��\n"NOR;
		message_vision(msg, me, target);
		if (!ANNIE_D->check_buff( target, "lockup"))		
		{	
			buff =
			([
				"caster":me,
				"who":	 target,
				"type": "lockup",
				"att":  "curse",
				"name": "��粽��������է��",
				"time":  10 + random(5),
				"buff1": "till_death/lockup",
				"buff1_c": 1,
				"buff_msg": "",
				"warn_msg":"",
			]);
			ANNIE_D->buffup(buff);				
		}		
		target->set_temp("busy_timer/jinhong-steps",time());
	}
	
	return 1;
}