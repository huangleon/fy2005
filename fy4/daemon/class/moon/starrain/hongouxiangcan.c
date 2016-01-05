#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
		string msg;
		mapping buff;
		int extra,level, mod, count, duration;
		object weapon;
		
		if (me->query("class") != "moon")
			return notify_fail("ֻ����¹��ĵ��Ӳ���ʩչ����ź��С���\n");
	
		extra = me->query_skill("starrain",1);
		if (extra <130)
			return notify_fail("����ź��С���Ҫ����130���ĺ���������\n");
	
		if( !target ) target = offensive_target(me);
		if( !target
		||	!target->is_character()
		||	!me->is_fighting(target) )
			return notify_fail("����ź��С�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
		duration = me->query("timer/pfm/starrain_sp")+ 20 - time();	
		if (duration > 0)
			return notify_fail("����ź��С��������ǰ��¡��͡�����˥�ݡ�ÿ��������ֻ��ʹ��һ�Σ�����ȴ�"+duration+"�룩\n");
			
		if (ANNIE_D->check_buff(target,"fight_stop"))
       		return notify_fail("�Է��Ѿ��ܵ������Ƶ�Ӱ�졣\n");

		// We don't use mod since we want it to be workable on tough NPCs. but we need a timer to limit its repeatability.
				
		weapon = me->query_temp("weapon");
		count = weapon->query_amount();
		if (count < 6)
			return notify_fail("����ź��С�������Ҫ6ö������\n");
		if (userp(me))	weapon->add_amount(-6);
		
		me->set("timer/pfm/starrain_sp",time());
		
		msg = HIR "\n$N��շ������ֽ�ִ���֣������С�ʳ��������ָ���죬ת�ۼ�����ͨ��Ѫ�죬���һ����һ����â��������ָ������\n"NOR;
		message_vision(msg,me,target);

		if (!COMBAT_D->do_busy_attack( me, target, "starrain/hongouxiangcan","step", 200, 10))
		{
			msg = YEL "$N"NOR+YEL"���ζ�Ȼ���ɣ����յرܿ��˺�â��\n"NOR;
			message_vision(msg,target);
		}
		else
		{
	    	msg = HIR BLK"$N����������ĵ��ˣ���Ѫ�Դ���ӿ����\n\n" NOR;
			buff =
			([
				"caster":me,
				"who":target,
				"type":"fight_stop",
				"att":	"curse",
				"name":"������������ź���",
				"time":  5,
				"buff1": "marks/fight_stop",
				"buff1_c":	1,	
				"buff_msg":msg,
				"disa_msg":WHT"$N��ʹ�����ڽ�����ɢ��\n"NOR,
				"disa_type": 1,
			]);
			ANNIE_D->buffup(buff);	
		}

        return 1;
}
