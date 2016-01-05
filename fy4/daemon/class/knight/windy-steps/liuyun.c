// Silencer@fengyun

#include <ansi.h>
inherit F_CLEAN_UP;

int perform(object me, object target)
{
        int skill, cps_skill;
        mapping buff;
        
        if(me->query("class")!="knight") 
			return notify_fail("ֻ�п���ֵ��Ӳ���ʹ�����Ʋ���\n");
	
		skill = me->query_skill("windy-steps", 1);		
		if(skill < 100) 	
			return notify_fail("���Ʋ���Ҫ100���ļ�����ʮ��ʽ��\n");
		     
	    if(!target) target = me;
	    if( target != me ) 
	      	return 	notify_fail("���Ʋ�ֻ�������Լ����ϡ�\n");
	        			
	    if (ANNIE_D->check_buff(me,"khl-df-stance")>0) 
			return notify_fail("���Ѿ���ʹ�����Ʋ��ˡ�\n");
	    
	    if (me->query_temp("timer/khl-stance")+30>time())
	    	return notify_fail("����ֵĲ���ÿ30�������ת��һ�Ρ�\n");
	    	
	    if (ANNIE_D->check_buff(me,"khl-atk-stance")>0) {
	    	ANNIE_D->debuff(me,"khl-atk-stance");
	    }
	    
	    if (ANNIE_D->check_buff(me,"dodgeup")>0 || ANNIE_D->check_buff(me,"powerup")>0)
        	return notify_fail("���Ѿ���ʹ�����Ƶ��书�ˡ�\n");
	    
	    me->set_temp("timer/khl-stance",time());	    
	    	    	
		cps_skill = skill/20;
		
		buff =
			([
				"caster":me,
				"who": me,
				"type": "khl-df-stance",
				"type2":"dodgeup",
				"att":"bless",
				"name":"������ʮ��ʽ�����Ʋ�",
				"buff1": "apply/composure",
				"buff1_c":cps_skill,
				"buff2": "apply/dodge",
				"buff2_c": skill/3,
				"time":  600,
				"buff_msg":BGRN + WHT"$N����һ�λ������࣬��ʱ�ֻص���ԭ�أ���������ˮ��һ���ǳɡ�\n"NOR,
			]);
		ANNIE_D->buffup(buff);	
        return 1;
}

