// fyteam
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;

int perform(object me, object target)
{
    	int skill;
    	mapping buff;
    	
    	if (me->query("class")!="shaolin")  
     		return notify_fail("Ψ�����ָ�ɮ����ʹ�á��������ҡ�\n");
    	   	
    	if (!target) target = me;
    	if( target != me ) 
    		return notify_fail("��ֻ�ܽ����������ҡ������Լ������ϡ�\n");
    	
    	skill = me->query_skill("puti-steps", 1);
		if(skill < 50) 
			return notify_fail("���������ҡ�������Ҫ50��������ղ�����\n");
	 
    	if (ANNIE_D->check_buff(me,"dodgeup"))
     		return notify_fail("���Ѿ���ʹ�����Ƶ��书�ˡ�\n");
     		
    	if( (int)me->query("force") < 100 )     
    		return notify_fail("���������ҡ���Ҫ�ķ�100��������\n");
    	if (userp(me))	me->add("force", -100);
	      		
     	if (me->query("class")!="shaolin" && me->query("class")!="official")  
     		skill=skill/2;
     	    	
     	buff =
		([
			"caster":me,
			"who": 	me,
			"type":	"dodgeup",
			"att":	"bless",
			"name":	"������ղ�������������",
			"buff1":"apply/dodge",
			"buff1_c":skill,
			"time":  900 ,
			"buff_msg":BGRN + HIG"$N����������������̨һƬ��������ʱ�����������\n"NOR,			
		]);
		ANNIE_D->buffup(buff);
        
        if (me->is_fighting())
        	me->perform_busy(2);
        
        return 1;
        
}


