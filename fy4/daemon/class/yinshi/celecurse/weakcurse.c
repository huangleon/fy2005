// Silencer@fengyun workgroup	June.2005

#include <ansi.h>
inherit SSERVER;

int curse(object me, object target)
{
    	string msg,msg1;
    	int skill,duration;
    	mapping buff;
    	   	
    	if(me->query("class")!="yinshi")
			return notify_fail("ֻ�е����ȵ��Ӳ�����˥����\n");
    	
    	skill = me->query_skill("celecurse",1);
    	if(skill<90 && userp(me))
    		return notify_fail("˥����Ҫ90��ͨ�콵��\n");

        if( !target ) target = offensive_target(me);        
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���ַ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    	
    	if (ANNIE_D->check_buff(target,"strdown"))
			return notify_fail("�Է��Ѿ�����˥���ˣ�����ץ��ʱ��������\n");
		
    	if((int)me->query("sen") < 50 && userp(me))
        	return notify_fail("˥����Ҫ�ķ�50�������\n");
    	if (userp(me))	me->add("sen",-50);
    		
    	msg = BLU "$N"+BLU"΢΢�������ְ��أ����������������ŵ������������ζ��������Ũ�ҵĵط���
��Ȼ�������ֳ�һ����ɫ����Ӱ����Ӱ�����ض���$n��������������$n��ȥ��\n\n" NOR;
        	
    	message_vision(msg, me, target);
    	
    	if (target->query("boss")|| target->query("big_boss"))
    		duration = 10;
    	else
    		duration = 30;
    	
    	if( COMBAT_D->do_busy_attack( me, target, "celecurse/weakcurse", "unarmed", 250, 10)) {	
	    	message_vision(YEL"$N���ŵ������޴룬��Ӱ����һ���ڹ⣬ע����$N��ü�ġ�\n"NOR, target);
	    	buff = 
			([
				"caster": me,
				"who":   target,
				"type":  "strdown",
				"att":	"curse",
				"name":	"ͨ�콵��˥��",
				"buff1":"apply/strength",
				"buff1_c": -5,
				"time":   duration,
				"buff_msg": "",
			]);
			ANNIE_D->buffup(buff);
		
			if (!ANNIE_D->check_buff(me,"strup")) {
				buff = 
				([
					"caster": me,
					"who":    me,
					"type":  "strup",
					"att":	 "bless",
					"name":	 "ͨ�콵��˥��",
					"buff1": "apply/strength",
					"buff1_c": 5,
					"time":   duration,
					"buff_msg": "",
				]);
				ANNIE_D->buffup(buff);
			}
		
		} else
			message_vision(WHT"$N������𣬶���˺ڹ⡣\n"NOR, target);
	
		me->perform_busy(1);
    	return 1;
}

