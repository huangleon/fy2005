// silencer@fengyun
// ѩ����֪��������
// ��÷��׺��֦�壬
// �����뿪���컣�
// ��ͥ�ʣ�
// ����ԡ����ױϴ��



#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
    	string msg;
    	int extra, count, i;
    	int tmp,chance;
    	object weapon;
    	
    	extra = me->query_skill("meihua-biao",1);
    	if ( userp(me) && extra < 150) 
    		return notify_fail("�ۺ�÷�����Ҫ150���ģ�÷���ڷ��ݣ�\n");
  	
    	if( !target ) target = offensive_target(me);
    	if( !target
		||	!target->is_character()
		||	!me->is_fighting(target) )
        	return notify_fail("�ۺ�÷���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        
        weapon = me->query_temp("weapon");
	count = weapon->query_amount();
	if (count < 10)
		return notify_fail("��İ�������̫�١�\n");
        
    	me->add_temp("apply/attack",extra);
    	me->add_temp("apply/damage",extra*2);
    
    	msg = HIG  "\n\n$Nʹ��÷���ڷ��еģۺ�÷��ݣ�һ��������ʽ��������÷���ţ���\n\n"NOR;
/*	  msg += HIR"
		��      ��     	��      ��  	ѩ
						  	
		��      ͥ     	��      ÷  	��
						  
		ԡ      ��     	��     	��  	��
					 
		��      	��     	׺  	֪
		        	  	
		��      	��     	��  	��
			          	
		ױ      	�     	֦  	��
			          	
		ϴ      	�     	��    	��
	  	
	  	\n"NOR;			
	  message_vision(msg,me,target);
	  
	  i = 5; 
	  while (i--) 
	  	  COMBAT_D->do_attack(me,target, TYPE_REGULAR,0); */
	  	msg+=HIM"    ѩ����֪����������÷��׺��֦�壬" NOR;
	    	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	   
	    	msg = HIM"    �����뿪���컣�" NOR;
	    	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	       
	    	msg = HIM "    ��ͥ�ʣ�����ԡ����ױϴ����" NOR;
	    	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
 
    	me->start_busy(3);
    	me->add_temp("apply/attack",-extra);
    	me->add_temp("apply/damage",-extra*2);
    	return 1;
}
