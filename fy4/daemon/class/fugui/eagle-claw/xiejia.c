// Silencer@fengyun	June.2005

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int myexp,yourexp,lvl,extra,mod,duration;
	mapping buff;
	
	if(me) 
		return notify_fail("������ж�ס�ͣ�á�\n");
		
	if (me->query("class")!="fugui") 
		return notify_fail("������ж�ס�Ϊ�����ؼ���\n");
		
	extra=me->query_skill("eagle-claw",1);
	if(extra<120)
		return notify_fail("������ж�ס���Ҫ120��ӥצ����\n");	
	
	duration = me->query("timer/pfm/fg_xiejia") - time() + 180;
    if( duration > 0 ) {
       	return notify_fail("�㻹��Ҫ�ȴ�"+(int)(duration+1)+"�����Ҳ����ٴ�ʹ�á�����ж�ס���\n");
	}
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("������ж�ס�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	
	if (ANNIE_D->check_buff(target,"irondown"))
		return notify_fail(target->name()+"Ӳ�����ѱ��߽⡣\n");
		
	mod = COMBAT_D->can_busy(me, target, "eagle-claw");	
	if (!mod)
		return notify_fail(HIW"���˹�����տ���޷��óѡ�\n"NOR);
	
	lvl = 200;					
	if (!userp(me)) 	lvl = 300;
		
	msg = BRED +HIW"
$N���һ��������ж�ס����Ʒ�˲���$n����ӹ���\n" NOR;
	message_vision(msg, me, target);
	
	if (COMBAT_D->do_busy_attack( me, target, "eagle-claw/jianlongxiejia","unarmed", lvl, mod))
	{
		msg = RED"$n���ȣ�һʱ��о�Ӳ������ȫ�᲻������\n"NOR;
		message_vision(msg, me, target);
		buff =
		([
			"caster":me,
			"who":	 target,
			"type": "irondown",
			"att":  "curse",
			"name": "ӥצ��������ж��",
			"time":  60,
			"buff1": "apply/iron-cloth",
			"buff1_c": -target->query_skill("iron-cloth")/10*7,
			"buff2": "apply/armor",
			"buff2_c": -target->query_temp("apply/armor")/10*7,
			"buff_msg": "",
			//"condition_type":  "<���ٶ�>",
			"warn_msg":"",
			"disa_type": 0, 
		]);
		ANNIE_D->buffup(buff);	
		me->set("timer/pfm/fg_xiejia", time());
	} else	{
			msg = CYN"$n���з�����΢Ų��λ��$N�Ʒ���������\n"NOR;
			message_vision(msg,me,target);
			me->set("timer/pfm/fg_xiejia", time()-120);
	}
	me->perform_busy(1); 
	return 1;
}

