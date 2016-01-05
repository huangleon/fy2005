
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
		string msg,name;
		mapping buff;
		int extra,level, mod, count,amount,duration;
		object weapon;
		
		if (me->query("class") != "moon")
			return notify_fail("ֻ����¹��ĵ��Ӳ���ʩչ�����ǰ��¡���\n");
	
		extra = me->query_skill("starrain",1);
		if (extra <100)
			return notify_fail("�����ǰ��¡���Ҫ����100���ĺ���������\n");
	
		if( !target ) target = offensive_target(me);
		if( !target
		||	!target->is_character()
		||	!me->is_fighting(target) )
			return notify_fail("�����ǰ��¡�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
			
		// We don't use mod since we want it to be workable on tough NPCs. but we need a timer to limit its repeatability.
		
		duration = me->query("timer/pfm/starrain_sp")+ 20 - time();	
		if (duration > 0)
			return notify_fail("����ź��С��������ǰ��¡��͡�����˥�ݡ�ÿ��������ֻ��ʹ��һ�Σ�����ȴ�"+duration+"�룩\n");
		
		if (ANNIE_D->check_buff(target,"healshield"))
       		return notify_fail("�Է��Ѿ��ܵ������Ƶ�Ӱ�졣\n");
       				
		weapon = me->query_temp("weapon");
		count = weapon->query_amount();
		if (count < 7)
			return notify_fail("�����ǰ��¡�������Ҫ7ö������\n");
		
		name = weapon->name();
		if (userp(me))	weapon->add_amount(-7);
		
		me->set("timer/pfm/starrain_sp",time());
				
		msg = WHT"$N"NOR+WHT"һ���֣�������ǵ�㣬������ɢ���·������ꡢ��Ĩ��˼����Ѹ��תΪɱ����\n";
		message_vision(msg,me,target);
		
		level = me->query("annie/starrain_qixingbanyue");
		if (me->query("class") != "moon")
			level = 0;
		if (!userp(me))
			level = 5;
		
		if (!level)					amount = 50;
		else if (level == 1)		amount = 70;
		else						amount = 90;
			
		amount = amount* (100 + F_ABILITY->check_ability(me,"yzhs_add")*5)/100;
		
		if (!COMBAT_D->do_busy_attack( me, target, "starrain/yanzihuishi","step", 200, 10))
		{
			msg = YEL "$N"NOR+YEL"��Ц������"+ name+ NOR YEL"��ɢ��ء�\n"NOR;
			message_vision(msg,target);
		}
		else
		{
			msg = HIR+BLK"���а���ǣ����"+name+HIR BLK"���ǹ��°���$N"HIR BLK"����������\n"NOR;
			buff =
			([
				"caster":me,
				"who":target,
				"type":"healshield",
				"att":	"curse",
				"name":"�������������ǰ���",
				"time":  10,
				"buff_msg":msg,
				"disa_msg":WHT"$N��Χ��"+name+ NOR WHT"�����Ѿ���ɢ����¡�\n"NOR,
				"disa_type": 1,
				"shield_type":"kee",
				"shield_amount": amount,
				"shield_desc": HIR BLK"$n"HIR BLK"��ͷһ������Ѫ������ֹ��\n"NOR,								
			]);
			ANNIE_D->buffup(buff);	
		}

        return 1;
}
