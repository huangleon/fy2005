// Silencer@fengyun4

#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;

int perform(object me, object target)
{
        int skill, num;
        
        if(me->query("class")!="bonze") 
		return notify_fail("ֻ���˹���ɮ����ʹ�á����须\n");
	
		skill = me->query_skill("nodust-steps", 1);		
		if(skill < 100) 	
			return notify_fail("�����须��Ҫ100�����޳�������\n");
	   
        if(!target) target = me;
        if( target != me ) 
        	return 	notify_fail("�����须ֻ�������Լ����ϡ�\n");
        	      
        if( me->query("force") < 100 )     
        	return  notify_fail("�����须��Ҫ100��������\n");   	
		me->add("force", -100);
	
       	me->set("bellicosity",0);
        	
        message_vision( BGRN + WHT "$N���̷�ţ�ǰ������������������أ�������Ϣ�佫ɱ������������\n" NOR, me);
        me->perform_busy(1);
        return 1;
}