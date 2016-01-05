// Silencer @ FY4 workgroup. Aug.2004

#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me, object target, int amount)
{
    	int skill, duration;
    	string msg;
    	mapping buff;

		if (me->query_skill("wolf-force",1) < 170 || me->query_skill("summonwolf",1)< 270)
        	return notify_fail("�����Ǿ�����Ҫ170���������ķ���270���Ļ�������\n");
        		
    	if( target != me )
        	return notify_fail("�����Ǿ���ֻ����������\n");
    	    	
    	// duration = 20mins.
		duration = me->query("timer/pfm/wm_assassinate")+ 1200 -time();
		if (duration>0)
    	return notify_fail("�����Ǿ�������Ԫ����Ҫ"+chinese_number(duration/60)+"���Ӻ�����ٴ����á�\n");
    	
    	if (ANNIE_D->check_buff(me,"assassinate"))
    	       	return notify_fail("���Ѿ����������Ƶ��书�ˡ�\n");

    	if( me->query("force") < 100 )
        	return notify_fail("�����Ǿ�����Ҫ100���������\n");
    	if (userp(me)) me->add("force", -100);

    	msg = BRED + HIW"\n$N�����������ϡ�����Ϣ�������������ҹ���е��ǣ�һ��������\n" NOR;

    	buff =
		([
			"caster":me,
			"who": me,
			"type":"assassinate",
			"att":"bless",
			"name":"�����ķ������Ǿ�",
			"buff1":"pfm/wm_assassinate",
			"buff1_c":skill,
			"time": 16,
			"buff_msg": msg,
		]);
		me->set("timer/pfm/wm_assassinate", time());
		
		ANNIE_D->buffup(buff);
	   	return 1;
}
