// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;

int exert(object me, object target, int amount)
{
		int i,t,skill,level;
		mapping buff;

		if (userp(me))
			return notify_fail("���������Ѿ�ʧ���ˡ�\n");

		level = me->query("annie/snowforce_budongzhijie");
		if (me->query("class") != "moon")
			level = 0;
		if (!userp(me))
			level = 5;

        skill = me->query_skill("snowforce",1);

		if (skill < 30)
        	return notify_fail("������֮�硻��Ҫ����30������ѩ�ľ���\n");

		if (me->query("class") != "moon")
			t = 80;
		else
			t = (140-skill)/2;

		if (me->query("timer/solidstat") + t > time())
        	return notify_fail("���ʱ���ﻹ�޷�����ʩ��������֮�硻��\n");

		if( ANNIE_D->check_buff(me,"blocked")) 
			return notify_fail("����������ʩչ���Ƶ�������\n");

		if (level)
		{
			if(me->query("force") < 50 )    
				return notify_fail("�������������\n");
	        me->add("force", -50);
		}
		else
		{
			if(me->query("force") < 100 )
				return notify_fail("�������������\n");
	        me->add("force", -100);
		}

		me->set("timer/solidstat",time());

		buff =
			([
				"caster":me,
				"who":me,
				"type":"blocked",
				"att":"bless",
				"name":"��ѩ�ľ�������֮��",
				"time":me->query("class") != "moon"?10:30,
				"buff_msg":HIR BLK"$N����ѩ�ľ��˱��С���죬ֻ���ľ���ˮ����Ȼ��Ϊ����������\n"NOR,
			]);
		ANNIE_D->buffup(buff);

        return 1;
}
