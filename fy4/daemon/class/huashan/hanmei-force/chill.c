//	����˪��÷������multiple enemies, 

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int exert(object me, object target)
{
	object wp,weapon;
	int cost, extra, myexp,yourexp, i;
	int base;
	string msg, skill;
	object	*enemy;
	
	if (me->query("class") != "huashan") 
		return notify_fail("ֻ�л�ɽ���ӿ���ʹ�á���˪��÷����\n");
	
	extra = me->query_skill("hanmei-force", 1);
	if(extra < 50) 
		return notify_fail("����˪��÷����Ҫ50����÷�ķ���\n");
	if( !me->is_fighting() )
		return notify_fail("����˪��÷��ֻ����ս����ʹ�á�\n");
	
	if (ANNIE_D->checkbuff(me, "berserk"))
		return notify_fail("ʹ������ʱ����ʹ�ù��������⼼�ܡ�\n");
	
	if( me->query("force") < 200 )
		return notify_fail("����˪��÷��������Ҫ200�������Ϊ������\n");
	
	if (userp(me)){ 
		if (me->query("force")>50)
			me->add("force", -50);
		else
			me->set("force",0);
	}

	wp = me->query_temp("weapon");
	
	if(!wp){
		msg=HIW"\n$N�������ۣ�����������һ�㺮˪��˫�Ʒ��ף���ƮƮ�ĳ����ƺ���û��ʲôĿ�꣬
����ȴ������أ�����������ӿ��\n"NOR;
		
	} else {
		msg = HIW"\n$N"+HIW"�������ۣ�һ�㺮˪���������е�"+ wp->name()+HIW"�ϣ�����һת���������������������ߣ�
����֯����һƬ���������ܵ����������¡�\n"NOR;
	}

	message_vision(msg, me);
	
	enemy =	me->query_enemy();
	
	me->add_temp("apply/attack",  extra);
		
	for (i = 0 ; i< sizeof(enemy); i++) {	
		if( enemy[i]&& enemy[i]->is_character()
        		&& me->is_fighting(enemy[i]) && !me->is_busy() )               
		{	
			target = enemy[i];   									       			
	   		COMBAT_D->do_attack(me,target,TYPE_PERFORM,"");  
       	}
	}	        		
	
	me->add_temp("apply/attack", -extra);
    
	me->perform_busy(2);
	
	return 1;
}

