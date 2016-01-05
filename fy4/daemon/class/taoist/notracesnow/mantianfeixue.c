// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;

int perform(object me, object target)
{
        int skill;
        mapping buff;
        
        skill = me->query_skill("notracesnow", 1);
		
		if ((string)me->query("class") != "taoist") {
	  		skill=skill/2;
			if(skill < 30) 
				return notify_fail("��Ҫ60��̤ѩ�޺۲���ʹ�á������ѩ��\n");
		} else if (skill<30)
			return notify_fail("��Ҫ30��̤ѩ�޺۲���ʹ�á������ѩ��\n");
        
        if (!target) target = me;
        if( target != me ) 
        	return 	notify_fail("��ֻ�ܽ��������ѩ�������Լ������ϡ�\n");
        
        if (ANNIE_D->check_buff(me,"dodgeup"))
        	return notify_fail("���Ѿ���ʹ�����Ƶ��书�ˡ�\n");
        
		buff =
			([
				"caster":me,
				"who": me,
				"type":"dodgeup",
				"att":"bless",
				"name":"̤ѩ�޺ۡ������ѩ",
				"buff1":"apply/dodge",
				"buff1_c":skill,
				"time":  900,
				"buff_msg":BGRN + HIW"$N�й����������ξ�Ȼ��������������е�ѩ��Ʈ���޶���\n" NOR,
	//			"warn_msg":WHT"�������ѩ���Ĺ�Ч��Ҫ�����ˡ�\n"NOR,
	//			"disa_msg":YEL"��ʩչ��ϡ������ѩ������ס���Ρ�\n"NOR,
				"special_func":0,
			]);
		ANNIE_D->buffup(buff);
        
        return 1;
}