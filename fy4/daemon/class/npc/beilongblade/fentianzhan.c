
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string dodskill,msg;
	int extra, busy,busy2,pp=0,pd=0;
	object weapon;
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("������ն��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (me->query_skill("beilongblade",1) < 135)
		return notify_fail("��Ա����������ղ��㣬�޷�ʹ�á�����ն����\n");
	
	extra = me->query_skill("blade");

	pp=random(random(extra*6))+1;
	pd=random(random(random(extra*12)))+1;
	// �����ȶ�������С������ֳ����˺���
	me->add_temp("apply/attack",pp);
	me->add_temp("apply/damage",pd);	

	msg =  HIW"$Nƽ̧"+(me->query_weapon())->name()+HIW"���磬��������Ȼһ���Ϻȣ����$n"HIW"������������ð���ǣ�����Ϊ֮һ�١�\n"HIR"$N"HIR"���Ƴ���������$n"HIR"�һ��֮�ϣ�Ю����֮����������һ����\n" NOR;
	message_vision(msg, me, target);
	
    COMBAT_D->do_attack(me,target,TYPE_PERFORM,"");

	me->add_temp("apply/attack",-pp);
	me->add_temp("apply/damage",-pd);	

	me->perform_busy(2);
	
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
