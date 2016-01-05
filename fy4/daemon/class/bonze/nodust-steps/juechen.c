// Silencer@fengyun

#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;

int perform(object me, object target)
{
        int skill, agi_skill;
        mapping buff;
        
        if(me->query("class")!="bonze") 
		return notify_fail("ֻ���˹���ɮ����ʹ�á�������\n");
	
		skill = me->query_skill("nodust-steps", 1);		
		if(skill < 150) 	
			return notify_fail("����������Ҫ150�����޳�������\n");
	      
        if(!target) target = me;
        if( target != me ) 
        	return 	notify_fail("��������ֻ�������Լ����ϡ�\n");
        	
        if (ANNIE_D->check_buff(me,"agiup"))
        	return notify_fail("���Ѿ���ʹ�����Ƶ��书�ˡ�\n");
        
        if( me->query("force") < 100 )     
        	return  notify_fail("����������Ҫ100��������\n");   	
		me->add("force", -100);
	
		agi_skill = skill/20;	// 200/20 = 10
	
		buff =
		([
			"caster":me,
			"who": me,
			"type":"agiup",
			"att":"bless",
			"name":"�޳���������",
			"buff1": "apply/agility",
			"buff1_c":agi_skill,
			"buff2":"pfm/nodust_inquire",
			"buff2_c":1,
			"time":  900,
			"buff_msg":BGRN + WHT"$N����������ӡ�羪��̤ѩ�࣬������ȸ����һ�����޼���ѭ��\n"NOR,
		]);
		ANNIE_D->buffup(buff);
	
        return 1;
}