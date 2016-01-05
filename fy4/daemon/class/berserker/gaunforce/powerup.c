#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me, object target, int amount)
{
    	int skill;
    	string msg;
    	mapping buff;
    
//    	if (me->query_skill("gaunforce",1) < 150)
//        	return notify_fail("������Ͽ��Ҿ�����Ҫ��150�����������Ϊ������\n");
        	
    	if( (int)me->query("force") < 100 )
        	return notify_fail("����������������Ҫ100���������\n");
    	
    	if (ANNIE_D->check_buff(me,"powerup"))
    	       	return notify_fail("���Ѿ����������Ƶ��书�ˡ�\n");

    	skill = me->query_skill("gaunforce",1)/2;
    	if (userp(me))
		{
    		me->add("bellicosity", skill/2);
    		me->add("force", -100);
    	}

    	msg = HIR "$N"HIR"����һ�����������������ٶ����������һ�󳴶����Ѱ�����죬������֫�·��������˼��硣\n" NOR;

    	buff =
		([
			"caster":me,
			"who": me,
			"type":"powerup",
			"att":"bless",
			"name":"�����������������",
			"buff1":"apply/attack",
			"buff1_c":skill,
			"buff2":"apply/damage",
			"buff2_c":skill,
			"time": 300,
			"buff_msg": msg,
		]);
		ANNIE_D->buffup(buff);
	
    	if( me->is_fighting() && userp(me)) 
    		me->start_busy(1);

    	return 1;
}

/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/
