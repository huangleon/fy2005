// void_sense.c

#include <ansi.h>

inherit SSERVER;

int conjure(object me, object target)
{
    	int lvl;
    
    	if (me->query("class")!="bonze")
    		return notify_fail("��ʶ��ͨΪ�˹�������\n");
    	
    	lvl = (int) me->query_skill("essencemagic",1);
    	if (lvl<30) 
    		return notify_fail("��Ҫ30����ʶ��ͨ����ʹ�ü�ʶ��ͨ��\n");
    
    	if (me->is_fighting())
    		return notify_fail("��ʶ��ͨ������ս����ʹ�á�\n");
    
    	if (environment(me)->query("no_fly") )
    		return notify_fail("�˵ز���ʹ�ü�ʶ��ͨ��\n");
        
        if (stringp(me->query_temp("no_move")))
        	return notify_fail(me->query_temp("no_move"));
        	
    	if (target)  
    		return notify_fail("��ʶ��ֻͨ�ܶ��Լ�ʹ�á�\n");
    	    	
    	if( me->query("atman") < 100 )
        	return notify_fail("��ʶ��ͨ��Ҫ100��������\n");
    	me->add("atman", -100);
    
    	message_vision(HIB "$N��ϥ��������ʼ���ü�ʶ��ͨ��˼�붨 ...\n" NOR, me);
     	
    	if( random(me->query_skill("essencemagic",1)) +14 < me->query_skill("essencemagic",1))
    	{
	 		tell_object(me,WHT"�����ΧһƬ�ž�����о����岻�ϵ��³���\n"NOR);
	 		TASK_D->flying_risk(me);
	 		me->move("/d/death/gate");
	 		me->start_busy(5);
        	return 1;
    	}
    	write("����ʲô���鶼û�з�����\n");
       	return 1;
}




