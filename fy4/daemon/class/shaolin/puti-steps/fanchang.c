// Silencer @ FY4 workgroup. Oct.2004

#include <ansi.h>
inherit F_CLEAN_UP;

int perform(object me, object target)
{
    	int skill,duration;
    	object room;
    	    	
    	if (me->query("class")!="shaolin")  
     		return notify_fail("Ψ�����ָ�ɮ����ʹ�á������󳪡�\n");
     		    	
    	skill = me->query_skill("puti-steps", 1);
		if(skill < 150 || me->query_skill("zen",1)<160) 
			return notify_fail("�������󳪡�������Ҫ150��������ղ�����160��������\n");
	 
	 	if (me->is_fighting())
	 		return notify_fail("�������󳪡�������ս����ʹ�á�\n");
	 		
    	if (!target)
    		return notify_fail("�������ľ�ʬ��ʹ�á������󳪡���\n");
    	
    	if (!target->is_corpse())
    		return notify_fail("�������󳪡�����ȥ����ʹ�á�\n");
    	       	
        if( (int)me->query("force") < 100 )     
    		return notify_fail("�������󳪡���Ҫ�ķ�100��������\n");
    	if (userp(me))	me->add("force", -100);
	    
		message_vision(HIW"$N���"+target->query("victim_name")+"��ʬ������������������ָ�ڵ���������£�������̷�
����������֯���޴����ڣ��޷����ԣ��������ɣ����಻�����������󳪡�\n"NOR, me);
		
		room = environment(me);
		call_out("getup", 6, me, room);
		me->perform_busy(3);
		return 1;
}


int getup(object me, object room) {
	
	int amount;
	
	if (!me)	return 1;
	if ( room != environment(me))	return 1;
	
	tell_object(me,WHT"���̾���ϣ���������ֻ������һƬ������\n"NOR);
	amount = me->query_skill("zen",1) * 4;	// 800 top
	me->receive_curing("kee", amount);
	return 1;
}

		