// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me, object target, int amount)
{
        int skill,t,level,duration;
		object iceshield;

    	if (me->query("class") != "moon")
        	return notify_fail("ֻ����¹����˲���ʩչ�����Ǿ��ڡ���\n");

		skill = me->query_skill("snowforce",1);
		if (skill < 120 && userp(me))
        	return notify_fail("�����Ǿ��ڡ���Ҫ����120������ѩ�ľ���\n");
        
/*���Ǿ���?��һ��	snowforce_bingpojingbi_1 L100	1M, 10%
���Ǿ���?�ڶ���	snowforce_bingpojingbi_2 L120	2.4M	20%
���Ǿ���?������	snowforce_bingpojingbi_3 L140	4M		30%
���Ǿ���?���ľ�	snowforce_bingpojingbi_4 L160	6.4M	30%

*/
		level = me->query("annie/snowforce_bingpojingbi");
		if (!userp(me))
			level = 5;

		if (!level)
        	return notify_fail("����û��������ѩ�ľ��еġ����Ǿ��ڡ���\n");

		t = 60;		// same as iceshield expiration time
		duration = me->query("timer/iceshield")+t -time();
		if (duration >0 && userp(me))			
        	return notify_fail("�����Ǿ��ڡ�����Ҫ�ȴ�"+duration+"���ӡ�\n");

        if(present("ice shield",me)) 
        	return notify_fail("���Ѿ����˹����ˡ�\n");

		if(me->query("force") < 100 && userp(me))   
			return notify_fail("�����Ǿ��ڡ���Ҫ100���������\n");
		if (userp(me))
	        me->add("force", -100);

		me->set("timer/iceshield",time());
		seteuid(getuid());

		iceshield=new("/obj/specials/moon/iceshield");

		message_vision(HIW"$N"HIW"��ת�ľ�����㺮����������ۣ���������һ�����֮�ڣ�\n"NOR,me);

		if (!iceshield->move(me))
		{
			message_vision(WHT"Ȼ��$N"NOR+WHT"��һ���������ھͻ���ˮ����ɢ���Ρ�\n\n"NOR,me);
			return 1;
		}
		iceshield->protect(me,level);
		
		if (userp(me))	me->perform_busy(2);
		
        return 1;
}

