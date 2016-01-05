#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me, object target, int amount)
{
    	int skill;
    	string msg;
    	mapping buff;
		function f;
   
		if (me->query_skill("gaunforce",1) < 200)
        	return notify_fail("������Ͽ��Ҿ�����Ҫ��200�����������Ϊ������\n");
        	
    	if( me->query("force") < 500 )
        	return notify_fail("������Ͽ��Ҿ�����Ҫ500���������\n");
    	
    	if (ANNIE_D->check_buff(me,"powerup"))
    	       	return notify_fail("���Ѿ����������Ƶ��书�ˡ�\n");
		
    	if (userp(me))
    		me->add("force", -500);

    	msg = HIR "$N����һ�����������α�������������������֡�\n" NOR;
	
		f = (: call_other, __FILE__, "fullnpc",me,me->query("force_factor") :);

		me->set("old_force_factor",1);	// ��ֹpplͨ��quit������factor-up.

		me->set("force_factor",me->query("force_factor")*3/2);

    	buff =
		([
			"caster":me,
			"who": me,
			"type":"powerup",
			"att":"bless",
			"name":"�����������Ͽ��Ҿ�",
			"time": 20,
			"buff_msg": msg,
			"finish_function":bind(f, this_object()),
		]);
		ANNIE_D->buffup(buff);
	
    	if( me->is_fighting() && userp(me)) 
    		me->start_busy(1);

    	return 1;
}



void fullnpc(object target,int i)
{
	if (!target)
		return;
	target->set("force_factor",i);
	return;
}

 

/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/
