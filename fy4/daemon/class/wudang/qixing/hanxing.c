// Silencer@fy4

#include <ansi.h>
inherit SSERVER;
int cast(object me, object target)
{
    	string msg;
    	int lvl;
	mapping buff;
		
   	if((int)me->query_skill("qixing",1) < 60 )
   	     return notify_fail("�����Ǿ�����Ҫ60�����Ƿ���\n");
      	
    	if( !target ) target = me;
    	else if( me != target)
        	return notify_fail("�����Ǿ���ֻ���������Լ������ϡ�\n");
    
	if( ANNIE_D->check_buff( me, "armorup")
		|| ANNIE_D->check_buff(me,"powerup2"))
        	return notify_fail("���Ѿ���ʹ�����Ƶ��ľ��ˡ�\n");

    	if(me->query("mana") < 150 )
        	return notify_fail("�����Ǿ�����Ҫ150�㷨����\n");
    	me->add("mana", -150);
    
    	msg = HIC "\n$N���������дʣ�һ����â��$Nͷ�������������$N��Χ��\n" ;
	msg +="��â����һ����ף�����ס$N��ȫ��\n\n"NOR;
	
//	50 + 200 = 250	/5 = 50
	lvl = me->query_skill("spells")/5;
                
        buff =
		([
			"caster":me,
			"who": me,
			"type":"armorup",
			"att":"bless",
			"name":"���Ƿ������Ǿ�",
			"buff1":"apply/armor",
			"buff1_c":lvl,
			"time":   360,
			"buff_msg":msg,
		]);
	ANNIE_D->buffup(buff);
	me->perform_busy(1);
    	return 1;
}
