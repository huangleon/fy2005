// tie@fengyun
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
    int extra;
    int tmp,chance;
    extra = me->query_skill("tang-blade",1);
    if ( userp(me) && extra < 150) 
    	return notify_fail("�۰�����ʽ����Ҫ150���ģ�����������ݣ�\n");
  	
    if( !target ) target = offensive_target(me);
    if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
        return notify_fail("�۰�����ʽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        
    me->add_temp("apply/attack",extra);
    me->add_temp("apply/damage",extra*2);
    
    msg = HIG  "\n\n$Nʹ������������еģ۰�����ʽ�ݣ�һ��������ʽ�������������ţ���\n"NOR;
  	msg+=HIC"��һ������������" NOR;
    	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
   
    	msg = HIC"�ڶ���������ΡΡ" NOR;
    	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
  
      	msg = HIC "����������������" NOR;
    	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
       
    	msg = HIC  "���ĵ�����б�Ǻ�" NOR;
    	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
    
    	msg = HIC  "���嵶���������" NOR;
    	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
 
    me->start_busy(3);
    me->add_temp("apply/attack",-extra);
    me->add_temp("apply/damage",-extra*2);
    return 1;
}
