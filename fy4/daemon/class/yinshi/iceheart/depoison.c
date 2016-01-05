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
	object obj, *mem;
	
	lvl = me->query_skill("iceheart",1);
    if( target != me && lvl < 100) 
       	return notify_fail("Ϊ���˱ƶ���Ҫ100�����ľ���\n");
                
    force =(int) me->query("force");
	if( force <=150) 
		return notify_fail("������Ҫ150��������\n");
	
	if (target == me)
	{
		message_vision(HIW"$N�˹�������ͷ��ð������ĺ��顣������\n"NOR, me);	
		me->add("force", -100  );
		
		if (lvl < 75)
			me->clear_condition_type(GENERIC);
		else if (lvl < 150)
			me->clear_condition_type(LOW_POISON);
		else
			me->clear_condition_type(MID_POISON);
		message_vision(HIC"$N�������£��۵�һ���³�һ�ں�Ѫ��\n"NOR, me);
       	return 1;	
	}	
	else	
	{
		if(!objectp(obj = present(target, environment(me))))
			return notify_fail("����û������ˡ�\n");

		if( !obj->is_character() || obj->is_corpse() )
			return notify_fail("�����һ�㣬�ǲ����ǻ��\n");
		
		mem = me->query_team();
		if (!pointerp(mem) || member_array(target,mem) == -1)
			 return notify_fail("��ֻ�ܸ�ͬһ�����е������ˡ�\n");
	
		message_vision(HIW"$Nһ�ư���$n�����˹�������ͷ��ð������ĺ���������\n"NOR, me,target);
		me->add("force", -150);
		
		if (lvl < 75)
			target->clear_condition_type(GENERIC);
		else if (lvl < 150)
			target->clear_condition_type(LOW_POISON);
		else
			target->clear_condition_type(MID_POISON);
		
			message_vision(HIC"$N�������£��۵�һ���³�һ�ں�Ѫ�����ϵ���������ɢȥ������\n"NOR, target);		
	}
	return 1;

}