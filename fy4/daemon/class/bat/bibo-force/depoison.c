//About conditions types : ��see condition.h ���壩�����еĽⶾ���������С�
//NO_CURE        -  ����ҽ�ε�Conditions��һ���������ض��ĳ��ϡ�
//SPECIFIC_POISON     - �߼���--- ���඾���ձ�ⷨ��Ψ�ж�֢��ҩ�﷽�С�
//MID_POISON   -    �м��� -- �ض����ɵĽⶾ�ķ�����������ҩ� 
//LOW_POISON    --  �ͼ��� -- һ�����ѧ�����ķ���������ͨҩ�
//GENERIC	-- �˷���ԣ���ƻ����ࡣ
//	--- Silencer@fy4  in 12/21/2002

inherit "/daemon/condition/generic_condition";
inherit SSERVER;

#include <ansi.h>
#include <condition.h>

int exert(object me, object target, int amount)
{
	int force, lvl;
	object obj;
	lvl = me->query_skill("bibo-force",1);
	if (lvl<80)
		return notify_fail("�ƶ���Ҫ�������ı̲��ķ���\n");
		
        if( target != me)
        	return notify_fail("�̲��ķ�ֻ��Ϊ�Լ�������\n");
                
        force = me->query("force");
	if( force <=100) return notify_fail("�ƶ���Ҫ���������������\n");
	me->add("force", -100  );
		
	message_vision(HIW"$N�˹�������ͷ��ð������ĺ�������\n"NOR, me);	
		
	if (random(lvl) < 50)		
		return notify_fail("��ʧ���ˡ�\n");
	else if (lvl < 100)
		me->clear_condition_type(GENERIC);
	else
		me->clear_condition_type(LOW_POISON);
	
	me->perform_busy(1);
	return 1;
		
}	
