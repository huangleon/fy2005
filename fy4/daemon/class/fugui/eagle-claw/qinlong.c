// Silencer@fengyun	June.2005

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int myexp,yourexp,lvl,extra,mod;
	mapping buff;
	
	if (me->query("class")!="fugui") 
		return notify_fail("��ʮָ������Ϊ�����ؼ���\n");
		
	extra=me->query_skill("eagle-claw",1);
	if(extra<50)
		return notify_fail("��ʮָ��������Ҫ50��ӥצ����\n");	
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��ʮָ������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	
	if (ANNIE_D->check_buff(target,"pseudo-busy"))
		return notify_fail(target->name()+"�Ѿ����ٶ��ˡ�\n");
		
	if(target->is_busy())
		return notify_fail(target->name()+"�Ѿ���æ�����ˣ�\n");	
	
	mod = COMBAT_D->can_busy(me, target, "eagle-claw");	
	if (!mod)
		return notify_fail(HIW"���˹�����տ�����ᱻ���ַ��Ի�ġ�\n"NOR);
	
	lvl = 200;					
	if (!userp(me)) 	lvl = 300;
		
	msg = BRED +HIW"
$N���һ����������ϣ�˫�����������꣬����Ѹ�ݸ��ͣ���������
���޵��������п���$n�Ĺؽ�Ҫ��������ӥצ���е�һ�С�ʮָ��������\n" NOR;
	message_vision(msg, me, target);
	
	if (COMBAT_D->do_busy_attack( me, target, "eagle-claw/shizhiqinlong","step", lvl, mod))
	{
		msg = BLU"$n��ʧɫ������$N��������һ������ʱ������ľ��\n"NOR;
		message_vision(msg, me, target);
		buff =
		([
			"caster":me,
			"who":	 target,
			"type": "pseudo-busy",
			"att":  "curse",
			"name": "ӥצ��������",
			"time":  6,
			"buff1": "pseudo-busy",
			"buff1_c": 1,
			"buff_msg": "",
			"condition_type":  "<���ٶ�>",
			"warn_msg":"",
			"disa_type": 0, 
		]);
		ANNIE_D->buffup(buff);	
	} else	{
			msg = YEL"$n���˷���������һȦһ����$N���ݲ�����ȥ��\n"NOR;
			message_vision(msg,me,target);
	}
			
	target->set_temp("busy_timer/eagle-claw",time());
	me->perform_busy(1); 
	return 1;
}

