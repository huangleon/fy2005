// Silencer@fengyun
// ����ӥ���á���riposte��

#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;

int perform(object me, object target)
{
        int skill, timer, duration, time;
        mapping buff;
        
        if(me->query("class")!="fugui") 
		return notify_fail("ֻ�и�����Ӳ���ʹ�á���ӥ���á�\n");
	
		skill = me->query_skill("hawk-steps", 1);		
		if(skill < 160) 	
			return notify_fail("����ӥ���á���Ҫ160��������������\n");
	        
        if(!target) target = me;
        if( target != me ) 
        	return 	notify_fail("����ӥ���á�ֻ�������Լ����ϡ�\n");
        
        timer = 180;		
		duration = me->query("timer/pfm/hk_jiying")+timer-time();
		if (duration>0)
    		return notify_fail("��������ɢ��һʱ�޷��ٴ�ʹ�ü�ӥ���ã���"+duration+"�룩��\n");
        
        if (ANNIE_D->check_buff(me,"riposte"))
        	return notify_fail("���Ѿ���ʹ�����Ƶ��书�ˡ�\n");
       
		time = 20 + F_ABILITY->check_ability(me,"jybt_add")*2;
		me->set("timer/pfm/hk_jiying", time());
//		write ("time is "+ time + "\n");
		buff =
		([
			"caster":me,
			"who": me,
			"type":"riposte",
			"att":"bless",
			"name":"������������ӥ����",
			"buff1": "counter_action_extra",
			"buff1_c":1,
			"time":  time,
			"buff_msg":BGRN + WHT"$N"NOR+BGRN + WHT"������գ��������裬�缢ӥ���ã���Ȼȫ���²�����\n"NOR,
		]);
		ANNIE_D->buffup(buff);
	
        return 1;
}
