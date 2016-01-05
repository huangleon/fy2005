// Silencer @ FY4 workgroup. Aug.2004

#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me, object target, int amount)
{
    	int skill, duration;
    	string msg;
    	mapping buff;
    	object *inv, *wolf;

		if (me->query_skill("wolf-force",1) < 170 || me->query_skill("summonwolf",1)< 200)
        	return notify_fail("�����Ǿ�����Ҫ170���������ķ���200������֮����\n");
                     
    	// duration = 10 mins.
		duration = me->query("timer/pfm/wm_fancyfeet")+ 90 -time();
		if (duration>0)
    		return notify_fail("�����Ǿ�����Ҫ"+duration+"���Ӻ�����ٴ����á�\n");

        inv = all_inventory(environment(me));
        wolf = filter_array(inv,(: $1->query("possessed")==$2 && $1->query("id")=="wolf" :), me);
        if (!wolf || sizeof(wolf)<1)
        	return notify_fail("�����Ǿ���ֻ���������Լ������������ϡ�\n");	
        if (!objectp(wolf[0]))
        	return notify_fail("�����Ǿ���ֻ���������Լ������������ϡ�\n");	
        
    	if( me->query("force") < 100 )
        	return notify_fail("�����Ǿ�����Ҫ100���������\n");
    	if (userp(me)) me->add("force", -100);

    	msg = HIB"$n"HIB"����һ���������ƴ���$N"HIB"���ģ�ɲʱ�䣬�ƺ�������$n"HIB"��ͨ��������
"HIG"$n˫������ӨӨ���̹⣬���˶����壬����һ����������ĳ�����\n"NOR,

		buff =
			([
				"caster":me,
				"who":wolf[0],
				"type":"feat",
				"type2": "evade",
				"att":"bless",
				"name":"�����ķ�������",
				"buffup_name":"evade",
				"buffup_type":""+3,
				"buffup_ratio":3,
				"time":10,
				"buff_msg": msg,
				"special_func":2,
			]);
		
		me->set("timer/pfm/wm_fancyfeet", time());
		ANNIE_D->buffup(buff);
    	return 1;
}
