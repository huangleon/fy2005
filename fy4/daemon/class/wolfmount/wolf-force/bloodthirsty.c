// Silencer @ FY4 workgroup. Aug.2004

#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me, object target, int amount)
{
    	int skill, duration;
    	string msg;
    	mapping buff;

		if (me->query_skill("wolf-force",1) < 160)
        	return notify_fail("��ս�Ǿ�����Ҫ160���������ķ���\n");
        		
    	if( target != me )
        	return notify_fail("��ս�Ǿ���ֻ����������\n");
    	    	
    	// duration = 10 mins.
		duration = me->query("timer/pfm/wm_bloodthirsty")+ 600 -time();
		if (duration>0)
    	return notify_fail("��ս�Ǿ�������Ԫ����Ҫ"+chinese_number(duration/60)+"���Ӻ�����ٴ����á�\n");
    	
    	if (ANNIE_D->check_buff(me,"bloodthirsty"))
    	       	return notify_fail("���Ѿ����������Ƶ��书�ˡ�\n");

    	if( me->query("force") < 100 )
        	return notify_fail("��ս�Ǿ�����Ҫ100���������\n");
    	if (userp(me)) me->add("force", -100);

    	msg = BRED+HIW"$NͻȻ��Хһ��������Ϊץ����ͷ���������Ʈ��\n" NOR;

    	buff =
		([
			"caster":me,
			"who": me,
			"type":"bloodthirsty",
			"att":"bless",
			"name":"�����ķ���ս�Ǿ�",
			"buff1":"pfm/wm_bloodthirsty",
			"buff1_c":1,
			"time": 90,
			"buff_msg": msg,
		]);
		
		me->set("timer/pfm/wm_bloodthirsty", time());
		
		ANNIE_D->buffup(buff);
	
    	return 1;
}
