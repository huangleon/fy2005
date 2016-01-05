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
		if(skill < 150) 	
			return notify_fail("���Ʋ���Ҫ150���ļ�����ʮ��ʽ��\n");
	     
        if(!target) target = me;
        if( target != me ) 
        	return 	notify_fail("���Ʋ�ֻ�������Լ����ϡ�\n");
        	      
        if (ANNIE_D->check_buff(me,"khl-atk-stance")>0)
        	return notify_fail("���Ѿ���ʹ�����Ʋ��ˡ�\n");
        
        if (me->query_temp("timer/khl-stance")+30>time())
	    	return notify_fail("����ֵĲ���ÿ30�������ת��һ�Ρ�\n");

        if (ANNIE_D->check_buff(me,"khl-df-stance")>0)
        	ANNIE_D->debuff(me,"khl-df-stance");
        
        if (ANNIE_D->check_buff(me,"dodgeup")>0 || ANNIE_D->check_buff(me,"powerup")>0)
        	return notify_fail("���Ѿ���ʹ�����Ƶ��书�ˡ�\n");
        
	    me->set_temp("timer/khl-stance",time());
	    
                
        buff =
			([
				"caster":me,
				"who": me,
				"type": "khl-atk-stance",
				"type2":"powerup",
				"att":"bless",
				"name":"������ʮ��ʽ�����Ʋ�",
				"buff1": "apply/attack",
				"buff1_c":100,
				"buff2": "apply/parry",
				"buff2_c":-200,	
				"buff3": "apply/dodge",
				"buff3_c":-200,	
				"time":  600,
				"buff_msg":BGRN + HIY"$N����һ�λ������࣬��ʱ�ֻص���ԭ�أ���������ˮ��һ���ǳɡ�\n"NOR,
			]);
		ANNIE_D->buffup(buff);

        return 1;
}