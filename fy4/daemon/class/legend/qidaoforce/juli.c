// Silencer@fengyun	June.2005
// L300��������damage����random,��Զ�����ֵ��12�룬cdt20��

#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me,object target,int amount)
{
        int level, fix, duration, add;
        mapping buff;
        string msg;

		if(me->query("class")!="legend" && userp(me))
			return notify_fail("ֻ����ѩɽׯ�ĵ��Ӳ��ܹ�ʹ�þ�������\n");

		if (userp(me) && !REWARD_D->check_m_success(me,"��������"))
 			return notify_fail("ֻ�о���"WHT"����"NOR"����ѩ���Ӳ���ʹ�þ�������\n");

	 	level = me->query_skill("dormancy",1);
	 	if( level < 300)
			return notify_fail("������������Ҫ300����Ϣ��������\n");
	 	
 		if (ANNIE_D->check_buff(me, "damagecurse"))
 			return notify_fail("���Ѿ���ʩչ���Ƶ��ľ��ˡ�\n");
              
        if (target && target!= me)
 			return notify_fail("���ķ�ֻ�������Լ����ϡ�\n");
        
        // ��mins, feat -��mins, eventually=��min
        fix = 300;
        add = F_ABILITY->check_ability(me,"juli_add",2);
        fix = fix - add *12;
        
        duration = me->query("timer/pfm/juli")-time() + fix;
        if (duration>0)
        	return notify_fail("�㻹��Ҫ�ȴ�"+(int)(duration)+"�������Ҳ��ܹ��ٴ�ʹ�þ�������\n");
                
		me->set("timer/pfm/juli",time());
	  
	msg = BRED + HIY"$N����������һ�����죬�����һ��ָ�أ��ض���ָ�ⷢ��ХХ�������Ӻ�ת������������!\n\n"NOR;
	
	buff =
		([
			"caster":me,
			"who": me,
			"type":"damagecurse",
			"att":"bless",
			"name": "���������",
			"time":  60,
			"buff_msg": msg,
		]);
	ANNIE_D->buffup(buff);
	return 1;       
}
