// Silencer @ FY4 workgroup. Aug.2004
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
    	int skill, amount,wolf;
    	string msg;
    	mapping buff;
    
    	if (me->query("class")!="wolfmount")
    		return notify_fail("����ͻ������ɽ�����书��\n");
    	
    	skill = me->query_skill("xueyeqianzong",1);
    	if (skill < 50)
    		return notify_fail("����ͻ����Ҫ50����ѩҰǱ�١�\n");
    			
    	if(!target ) target=me;
    	if(target != me )
        	return notify_fail("��ֻ����ѩҰǱ�������Լ���ս������\n");
    	    	
    	if (ANNIE_D->check_buff(me,"powerup")
    		|| ANNIE_D->check_buff(me,"atkup"))
    	       	return notify_fail("���Ѿ����������Ƶ��书�ˡ�\n");

		if (me->query_temp("pfm/wm_stance"))
			return notify_fail("���޷�ͬʱʹ�ò�ͬ��ѩҰǱ�ٵ�����\n");
			
    	msg = BBLU + HIW"$N�������ӣ��ǽڿ������죬��������һƥ�ǣ�һƥ�¶�����į�����䡢�������ǣ�\n" NOR;

		wolf = me->query_skill("summonwolf",1);
		
		amount = 50;
		if (skill >=120)	amount = 80;
		if (skill >=160 && me->query("scroll/xueyeqianzong_wolverine")==3)	amount = 120;

    	buff =
		([
			"caster":me,
			"who": me,
			"type":"atkup",
			"att":"bless",
			"name":"ѩҰǱ�١���ͻ",
			"buff1":"apply/attack",
			"buff1_c":amount,
			"buff0": "pfm/wm_stance",
			"buff0_c": 1,
			"time": 600,
			"buff_msg": msg,
		]);
		ANNIE_D->buffup(buff);
	
    	return 1;
}
