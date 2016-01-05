
#include <ansi.h>
inherit SSERVER;
int cast(object me, object target)
{
    	string msg;
    	int lvl;
    	mapping buff;
      	
    	if( !target ) target = me;
    		else if( me != target)
        		return notify_fail("�����Ǿ���ֻ���������Լ������ϡ�\n");
    
    	if((int)me->query_skill("qixing",1) < 80 )
        	return notify_fail("�����Ǿ�����Ҫ80�����Ƿ���\n");
 	    
    	if(ANNIE_D->check_buff(target, "damageup")
    		|| ANNIE_D->check_buff(target,"powerup2"))
		return notify_fail("���Ѿ���ʩչ���Ƶ��ľ��ˡ�\n");
    
    	if((int)me->query("mana") < 150 )
        	return notify_fail("�����Ǿ�����Ҫ150�㷨����\n");
    	if(userp(me))	me->add("mana", -150);  
    	
    	msg = HIC "\n$N���������дʣ�һ����â��$Nͷ�������������$N��Χ��\n" ;
	msg +="��â����һ��������ע����$N��ȫ��\n\n"NOR;

	// 200 + 50  = 250 /5 = 50
	lvl = me->query_skill("spells")/5;
                
        buff =
		([
			"caster":me,
			"who": me,
			"type":"damageup",
			"att": "bless",
			"name":"���Ƿ������Ǿ�",
			"buff1":"apply/damage",
			"buff1_c":lvl,
			"time":   300,
			"buff_msg":msg,
		]);
	ANNIE_D->buffup(buff);
	me->perform_busy(1);
    	return 1;
}

