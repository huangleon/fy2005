// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;

int cast(object me, object target)
{
		int i,t,skill,level,sec,duration,duration2;
		mapping buff;

		if (me->query("class") != "moon")
        	return notify_fail("ֻ����¹����˲���ʩչ���޷���á���\n");

        skill = me->query_skill("heart-listening",1);
		if (skill < 120 && userp(me))
        	return notify_fail("���޷���á���Ҫ����120���Ļ���������\n");

		duration = me->query("timer/no_busy") + 300 - time();
		if (duration > 0 && userp(me))
        	return notify_fail("�㻹��ȴ�"+ duration+"�������Ҳ����ٴ�ʩ�����޷���á�\n");

		if( ANNIE_D->check_buff(me,"feat")) 
			return notify_fail("���޷���á���������ʹ�õ�ĳһ�ؼ�����ͬʱʹ�á�\n");

        if(me->query("mana") < 100 && userp(me))    
        	return notify_fail("��ķ���������\n");
        if (userp(me))
	        me->add("mana", -100);
	
		me->set("timer/no_busy",time());
		
		duration2 = 90 + F_ABILITY->check_ability(me,"wfbh_add")*6 ;
		
		buff =
			([
				"caster":me,
				"who":me,
				"type":"feat",
				"att":"bless",
				"name":"�����������޷����",
				"buffup_name":"no_busy",
				"buffup_type":CYN"$N"NOR+CYN"���Ϻ�����ת��Ʈ���鶯������޷���\n"NOR,
				"buffup_ratio":0,
				"time":duration2,
				"buff_msg":HIW"$N"HIW"Ĭ�����������Ϊһ���������룬�����ƻõ����̱��������ϡ�\n"NOR,
			]);
			
		ANNIE_D->buffup(buff);
        return 1;
}


