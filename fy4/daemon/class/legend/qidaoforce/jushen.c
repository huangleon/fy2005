// Silencer@fengyun	June.2005
// L300������������������������ʣ�2������12�룬cdt20��

#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me,object target,int amount)
{
        int level, fix, duration, add;
        mapping buff;
        string msg;

		if(me->query("class")!="legend" && userp(me))
		return notify_fail("ֻ����ѩɽׯ�ĵ��Ӳ��ܹ�ʹ�þ������\n");

	 	if (userp(me) && !REWARD_D->check_m_success(me,"��������"))
	 			return notify_fail("ֻ�о���"WHT"����"NOR"����ѩ���Ӳ���ʹ�þ������\n");
	 	
 		level = me->query_skill("six-sense",1);
 		if( level < 150 || me->query_skill("qidaoforce",1)<150)
			return notify_fail("�����������Ҫ150�������鰵ʶ������ķ���\n");
 	
 		if (ANNIE_D->check_buff(me,"legend_jushen") )
 			return notify_fail("���Ѿ���ʩչ���Ƶ��ľ��ˡ�\n");
              
        if (target && target!= me)
 		return notify_fail("���ķ�ֻ�������Լ����ϡ�\n");
        
        // ��mins, feat -��mins, eventually=��min
        fix = 300;
        add = F_ABILITY->check_ability(me,"jushen_add",2);
	    fix = fix - add *12;
                
        duration = me->query("timer/pfm/jushen")-time() + fix;
        if (duration>0)
        	return notify_fail("�㻹��Ҫ�ȴ�"+(duration)+"�������Ҳ��ܹ��ٴ�ʹ�þ������\n");
        
        amount = 150;
        if (level >=250)	amount = 200;
                        
		me->set("timer/pfm/jushen",time());
	  
		msg = BRED + HIY"$N�����������������ý��˾��ޡ��ܿ죬��������ǣ��Գ��ջ�����˲�伴��!\n\n"NOR;
	
		buff =
			([
				"caster":me,
				"who": me,
				"type":"legend_jushen",
				"att":"bless",
				"name": "���������",
				"buff1": "apply/attack",
				"buff1_c": amount,
				"time":  60,
				"buff_msg": msg,
			]);
		ANNIE_D->buffup(buff);
		return 1;       
}
