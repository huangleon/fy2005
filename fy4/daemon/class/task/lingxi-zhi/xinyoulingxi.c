#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
        int skill;
        mapping buff;
        
		skill=me->query_skill("lingxi-zhi",1);
		if (skill<160 && userp(me))
			return notify_fail("������Ϭ��Ҫ160����Ϭָ����\n");
		if (ANNIE_D->check_buff(me,"parry_busy"))
			return notify_fail("���Ѿ���ʹ�����Ƶ��书�ˡ�\n");
			
		tell_object(me,HIW"����Ժ��л�ȻһƬ�������Է�һ��һ���޲��������С�\n"NOR);
		buff =
			([
				"caster":me,
				"who":	me,
				"type": "parry_busy",
				"att":"bless",
				"name":"��Ϭָ��������Ϭ",
				"buff1":"xinyoulingxi",
				"buff1_c": 1,
				"time": 10,
				"buff_msg":"",
			]);
		ANNIE_D->buffup(buff);	
		
	    if (me->is_fighting()) me->start_busy(2);
	    return 1;
}
