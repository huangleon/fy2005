// Silencer@fengyun
// ��ӥ����졻������ٶȡ�����100������������

#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;

int perform(object me, object target)
{
        int skill, agi_skill;
        mapping buff;
        
        if(me->query("class")!="fugui") 
		return notify_fail("ֻ�и�����Ӳ���ʹ�á�ӥ����졻\n");
	
		skill = me->query_skill("hawk-steps", 1);		
		if(skill < 100) 	
			return notify_fail("��ӥ����졻��Ҫ100��������������\n");
	       
        if(!target) target = me;
        if( target != me ) 
        	return 	notify_fail("��ӥ����졻ֻ�������Լ����ϡ�\n");
        	
        if (ANNIE_D->check_buff(me,"agiup"))
        	return notify_fail("���Ѿ���ʹ�����Ƶ��书�ˡ�\n");
        
        if( me->query("force") < 100 )     
        	return  notify_fail("��ӥ����졻��Ҫ100��������\n");   	
		me->add("force", -100);
	
		agi_skill = skill/20;	// 160/20 = 8
	
		buff =
		([
			"caster":me,
			"who": me,
			"type":"agiup",
			"att":"bless",
			"name":"����������ӥ�����",
			"buff1": "apply/agility",
			"buff1_c":agi_skill,
			"time":  900,
			"buff_msg":BGRN + WHT"$N�������Ӱ�������𣬰�������Ǵ��˸�������ɽ��������\n"NOR,
		]);
		ANNIE_D->buffup(buff);
        return 1;
}