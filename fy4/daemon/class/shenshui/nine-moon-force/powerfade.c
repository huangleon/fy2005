// powerfade.c

#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me, object target, int amount)
{
        int skill, num;
        
        if ( !target) target = me;
        if( target != me ) 
        	return notify_fail("��ֻ���þ����ľ�ѹ���Լ���ɱ����\n");

 		if (me->query_skill("nine-moon-force",1) < 80)
        	return notify_fail("������������Ҫ�������ľ����ľ���\n");
               
        if(me->query("bellicosity") <= 0 )
                return notify_fail("�����ں���ɱ����\n");
        
        if( me->query("force") < 50 )     
        	return notify_fail("����������������Ҫ50��������\n");
        me->add("force",-50);
		me->set("bellicosity",0);
		
		message_vision(BGRN + HIW"$N˫��΢�ϣ�ʩչ�����ľ�����֮����������������ʼ�����Լ�������������\n" NOR, me);
	
		me->start_busy(1);   
        return 1;
}

 
