// Silencer@fengyun
#include <ansi.h>
#include <combat.h>

int perform(object me, object target)
{
        int skill;
		mapping buff;	
	
        if(me->query("class")!="fugui")
    		return notify_fail("ֻ�и���ɽׯ���Ӳ���ʹ����һ���ޡ��ľ�����\n");

        skill = me->query_skill("henglian",1);
		if(skill < 100) return notify_fail("һ������Ҫ100���ĺ�������\n");
        
        if(!target) target = me;
        if( target != me ) 
        	return notify_fail("��ֻ�ܽ�һ���������Լ������ϡ�\n");
        
        if( ANNIE_D->check_buff(me,"ironup")) {
        	ANNIE_D->debuff(me, "ironup");
        	return 1;
        }
//        	return notify_fail("���Ѿ���ʩչ���ƵĻ������ˡ�\n");
        
        if( me->query("force") < 150 )     
        	return	notify_fail("һ������Ҫ150���������\n");
		if (userp(me))	me->add("force", -150);
		
		buff =
			([
				"caster":me,
				"who":	me,
				"type": "ironup",
				"att": "bless",
				"name": "������һ����",
				"buff1":"apply/iron-cloth",
				"buff1_c":50,
				"time":  900,
				"buff_msg":HIY"$Nȫ��ÿһ���ǽں�Ȼȫ�����������һ���������ͣ����\n" NOR,
			]);
		ANNIE_D->buffup(buff);
    	return 1;
}
