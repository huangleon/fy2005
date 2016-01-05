// Silencer@fengyun

#include <ansi.h>
inherit F_CLEAN_UP;

int perform(object me, object target)
{
        int skill, stage, rate,duration;
        mapping buff;
        string buff_msg;
        
        if(me->query("class")!="knight") 
		return notify_fail("ֻ�п���ֵ��Ӳ���ʹ�û����䡣\n");
	
		skill = me->query_skill("dream-herb", 1);		
		if(skill < 140) 	
			return notify_fail("������������Ҫ140���������廨����\n");
		     
        if(!target) target = me;
        if( target != me ) 
        	return 	notify_fail("������ֻ�������Լ����ϡ�\n");
        
        if (!me->query_temp("weapon"))
        	return notify_fail("������ֻ�������ԯ�����������á�\n");
        	
        duration = me->query("timer/pfm/huanmengluo")+ 900 - time();
        if (duration >0)
        	return notify_fail("����Ҫ�ȴ�"+ (duration/60) + "�������Ҳ����ٴ�ʹ�û����䡣\n");
        
        if (ANNIE_D->check_buff(me,"poison_spirit"))
        	return notify_fail("���Ѿ���ʹ�����Ƶ��书�ˡ�\n");
        
        	// SCROLL ADVANCE PERFORM, 
	    stage = me->query("scroll/dream-herb_huanmengluo");
	    rate = 2;
	    
	    switch (stage) {
	    	case 2:		rate   	= 3; break;	// L150  c-d
	    	case 3:		rate	= 4; break;	// L170 c-d
	    }
        
        me->set("timer/pfm/huanmengluo",time());
        
		buff =
			([
				"caster":me,
				"who": me,
				"type":"poison_spirit",
				"att":"bless",
				"name":"�����廨����������",
				"buff1": "poison_spirit",
				"buff1_c":rate,
				"time":  90,
				"buff_msg":MAG"$N"NOR+MAG"�������Ȼ���ɣ���������������һ�����Σ���������������\n"NOR,
			]);
		ANNIE_D->buffup(buff);
	        
        return 1;
}


