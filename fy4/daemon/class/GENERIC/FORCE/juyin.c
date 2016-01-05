// Silencer @ FY4 workgroup. Aug.2004

#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me, object target, int amount)
{
    int skill;
 	mapping buff;
 	string msg;
 	       
 	skill = me->query_skill("ghosty-force",1);
    
    if ( skill<100)
       	return notify_fail("��������Ҫ100�����޿�������\n");
        
    if (!target) target = me;
    if( target != me ) 
       	return	notify_fail("��ֻ�����޿����������Լ��ķ�������\n");
     
    if( (int)me->query("force") < 150 )     
       	return	notify_fail("��Ҫ�ķ�100��������\n");
    me->add("force", -100);
               
    if (ANNIE_D->check_buff(me,"powerup")
    	|| ANNIE_D->check_buff(me,"dodgeup"))
       	return notify_fail("���Ѿ����������Ƶ��书�ˡ�\n");

    skill = 20 + skill /4;		// 20+200/4 = 70
    	    	
    msg = BGRN + HIW"$NĬ���޿������񹦣�ȫ����һ����������Ʈ������\n" NOR;

    buff =
		([
			"caster":me,
			"who": me,
			"type":"dodgeup",
			"att":"bless",
			"name":"�޿�������������",
			"buff1":"apply/dodge",
			"buff1_c":skill,
			"time": 300,
			"buff_msg": msg,
		]);
	ANNIE_D->buffup(buff);
   	if (userp(me))	me->perform_busy(1);
   	return 1;
}