// -by foxgirl@fengyun.com

#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;

int perform(object me, object target)
{
    	int skill;
    	mapping buff;
		string msg;
	    
    	if (me->query("class") != "huashan") 
    		return notify_fail("ֻ�л�ɽ���ӿ���ʹ�á��������ϡ���\n");
    	
    	if( userp(me) && me->query("gender") != "Ů��" )
        	return notify_fail("��һ�������˾�Ȼѧ��������ŤŤ����Ĺ���Ҳ����˼�ã�\n");
    
    	skill = me->query_skill("spring-water",1);
    	if(skill < 50) 
    		return notify_fail("����������Ҫ50���Ĵ�ˮ������\n");
    	
    	if(!target) target=me;
    	else if( target != me )
        	return notify_fail("��ֻ�ܽ��������������Լ������ϡ�\n");
    
    	if( ANNIE_D->check_buff(me, "ironup"))
        	return notify_fail("���Ѿ���ʩչ���ƵĻ������ˡ�\n");
        	
    	if( (int)me->query("force") < 100 )
        	return notify_fail("ʹ�ñ���������100���������\n");
    	if (userp(me))	me->add("force", -100);    	
    	
    	msg = HIY
"$N��ü���ף����𡺱������ϡ������������紺ˮ�������޷��Զ���\n"NOR;
    	msg += HIG
"�ƺ���һ����ϵ�΢�⵭������$N��Χ������\n" NOR;

    	buff =
		([
			"caster":me,
			"who":	me,
			"type": "ironup",
			"att": "bless",
			"name": "��ˮ��������������",
			"buff1":"apply/iron-cloth",
			"buff1_c":skill/2,
			"time":  600,
			"buff_msg":msg,
		]);
		ANNIE_D->buffup(buff);
    	if( me->is_fighting() ) me->perform_busy(2);
    	return 1;
}
