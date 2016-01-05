// powerup.c 	+100 atk and dodge

#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me, object target, int amount)
{
    	int skill;
    	string msg;
    	mapping buff;

		if (me->query_skill("nine-moon-force",1) < 60)
        	return notify_fail("��ľ����ľ����Ҳ����������裶��������\n");
    	
    	if( target != me )
        	return notify_fail("��ֻ���þ����ľ������Լ���ս������\n");
    	    	
    	if (ANNIE_D->check_buff(me,"powerup")
    		|| ANNIE_D->check_buff(me,"dodgeup")
    		|| ANNIE_D->check_buff(me,"atkup"))
    	       	return notify_fail("���Ѿ����������Ƶ��书�ˡ�\n");

    	skill = me->query_skill("nine-moon-force",1)/2;
    	if( me->query("force") < 100 )
        	return notify_fail("������������Ҫ100���������\n");
    	if (userp(me)) {
    		me->add("force", -100);
    	}

    	msg = BGRN + HIW"$N"BGRN + HIW"�۹۱ǣ��ǹۿڣ��ڹ��ģ�ʩչ�����ľ�������Ϊʵ��ȫ��͸�������ޱȵ�������\n" NOR;

    	buff =
		([
			"caster":me,
			"who": me,
			"type":"powerup",
			"att":"bless",
			"name":"�����ľ���������",
			"buff1":"apply/attack",
			"buff1_c":skill,
			"buff2":"apply/dodge",
			"buff2_c":skill,
			"time": 900,
			"buff_msg": msg,
		]);
		ANNIE_D->buffup(buff);

    	return 1;
}
