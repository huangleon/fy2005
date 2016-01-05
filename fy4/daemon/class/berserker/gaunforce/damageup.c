#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me, object target, int amount)
{
    	int skill;
    	string msg;
    	mapping buff;
    
    	if (ANNIE_D->check_buff(me,"damagecurse"))
    	       	return notify_fail("���Ѿ����������Ƶ��书�ˡ�\n");

    	skill = me->query_skill("gaunforce",1);
    	if( (int)me->query("force") < 100 )
        	return notify_fail("���������ƾ�����Ҫ100���������\n");
    	if (userp(me))
		{
    		me->add("force", -100);
    	}

    	msg = YEL "$N"NOR+YEL"�������ģ��������³�һ�ڳ�������ɫ������ľ����ޱ��顣\n" NOR;

    	buff =
		([
			"caster":me,
			"who": me,
			"type":"damagecurse",
			"att":"bless",
			"name":"��������������ƾ�",
			"time": 60,
			"buff_msg": msg,
		]);
		ANNIE_D->buffup(buff);
	
    	if( me->is_fighting() && userp(me)) 
    		me->start_busy(1);

    	return 1;
}

/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/
