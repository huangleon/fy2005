// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;

int exert(object me, object target, int amount)
{
		int i,t,skill,level,sec,duration;
		mapping buff;

		if (userp(me))
			return notify_fail("��ѧ���书��û������ؼ���\n");
		
		if (me->query("class") != "moon")
        	return notify_fail("ֻ����¹����˲���ʩչ���޷���á���\n");

        skill = me->query_skill("snowforce",1);
		if (skill < 140 && userp(me))
        	return notify_fail("���޷���á���Ҫ����140������ѩ�ľ���\n");

		duration = me->query("timer/no_busy") + 1800 - time();
		if (duration > 0 && userp(me))
        	return notify_fail("�㻹��ȴ�"+ duration/60+"�������Ҳ����ٴ�ʩ�����޷���á�\n");

		if( ANNIE_D->check_buff(me,"feat")) 
			return notify_fail("���޷���á���������ʹ�õ�ĳһ�ؼ�����ͬʱʹ�á�\n");

        if(me->query("force") < 100 && userp(me))    
        	return notify_fail("�������������\n");
        if (userp(me))
	        me->add("force", -100);
	
		me->set("timer/no_busy",time());
		
		buff =
			([
				"caster":me,
				"who":me,
				"type":"feat",
				"att":"bless",
				"name":"��ѩ�ľ����޷����",
				"buffup_name":"no_busy",
				"buffup_type":CYN"$N"NOR+CYN"���Ϻ�����ת��Ʈ���鶯������޷���\n"NOR,
				"buffup_ratio":0,
				"time":120,
				"buff_msg":HIW"$N"HIW"Ĭ�����������Ϊһ���������룬�����ƻõ����̱��������ϡ�\n"NOR,
			]);
			
		ANNIE_D->buffup(buff);
        return 1;
}


