// hippo@fengyun	2010.3.11

#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int myexp,yourexp,lvl,extra,mod,duration,x;
	mapping buff;
	
	if (me->query("class")!="lama") 
		return notify_fail("�������ǻ����Ǵ����µĶ����ܼ���\n");
		
	extra=me->query_skill("lamaism",1);
	if(extra<100)
		return notify_fail("�������ǻ�����Ҫ100�����ڷ𷨡�\n");	


	extra=me->query_skill("bloodystrike",1);
	if(extra<100)
		return notify_fail("�������ǻ�����Ҫ100�����ڴ���ӡ��\n");	

	duration = me->query("timer/pfm/dz_sssh") - time() + 480;
    if( duration > 0 ) {
       	return notify_fail("�㻹��Ҫ�ȴ�"+(int)(duration+1)+"�����Ҳ����ٴ�ʹ�á������ǻ�����\n");
	}

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�������ǻ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	
	if (ANNIE_D->check_buff(me,"ironup"))
		return notify_fail(me->name()+"�������ǻ���Ч�������С�\n");
		
	mod = COMBAT_D->can_busy(me, target, "bloodystrike");	
	if (!mod)
		return notify_fail(HIW"���˹�����տ���޷��óѡ�\n"NOR);
	
	//lvl = 200;					
	lvl = (int) me->query_skill("unarmed") /40 + 1;
	if (!userp(me)) 	lvl = 300;
		
	msg = BRED +HIG"
$Nʹ��һ�С������ǻ�����һָ���ٵľ���$n���ϸ���Ѩ����\n" NOR;
	message_vision(msg, me, target);
	if (COMBAT_D->do_busy_attack( me, target, "bloodystrike/sheshensihu","unarmed", lvl*100, mod))
	{
		msg = RED"$n��У��ϵ��ˣ��ع������Ѿ����ˡ�\n"NOR;
		message_vision(msg, me, target);
		buff =
		([
			"caster":me,
			"who":	 me,
			"type": "ironup",
			"att":  "bless",
			"name": "���ڴ���ӡ�������ǻ�",
			"time":  120,
			"buff1": "apply/iron-cloth",
			"buff1_c": me->query_skill("jin-gang",1),
			"buff_msg": "",
			"disa_msg": "",
			//"condition_type":  "<���ٶ�>",
			"warn_msg":"",
//			"disa_type": 0, 
		]);
		ANNIE_D->buffup(buff);	
		if (target && !userp(target)) {
			x = me->query("combat_exp")> target->query("combat_exp") 
				? target->query("combat_exp"): me->query("combat_exp");
			target->add_hate(me, F_LEVEL->get_level(x)*30);
		}
	} else	{
			msg = WHT"$n���˵ȼ����������ϵ���\n"NOR;
			message_vision(msg,me,target);
	}
	me->set("timer/pfm/dz_sssh", time());
	me->perform_busy(1); 
	return 1;
}