inherit SSERVER;
#include <ansi.h>

int exert(object me, object target, int amount)
{
		int force, lvl, duration;
		object obj, *mem;
		string msg;
		mapping buff;
		int skill,t,level;
	
		if (me->query("class") != "moon")
        	return notify_fail("ֻ����¹����˲���ʩչ����Ӱ���ա���\n");
        
        skill = me->query_skill("snowforce",1);
        if (skill < 90 && userp(me))
        	return notify_fail("����Ӱ���ա���Ҫ����170������ѩ�ľ���\n");
        
		if(!objectp(obj = present(target, environment(me))))
			return notify_fail("����û������ˡ�\n");
		if (!obj->is_character() || obj->is_corpse() )
			return notify_fail("�����һ�㣬�ǲ����ǻ��\n");
		
		if(!target) target=me;
		if(target!= me) {
			mem = me->query_team();
			if (!pointerp(mem) || member_array(target,mem) == -1)
				 return notify_fail("����Ӱ���ա�ֻ�����ڶ��ѡ�\n");
		}
	
		if (ANNIE_D->check_buff(target, "fma"))
			return notify_fail("�����Ѿ��ܵ���Ӱ���յ�Ӱ���ˡ�\n");	
	
		if (me->query("force")< skill*5)
        	return notify_fail("����Ӱ���ա�������Ҫ"+ skill*5 + "��������\n");
        if (userp(me))	me->add("force",-skill*5);
        		
	// 100 - 1000, 50-500 for others.
	// duration = effect.
		
		if (skill< 170)
			amount =  500;
		else
			amount = 1000;
			
		duration = 900;
	
		if ( target == me) {
			msg = WHT"$N"NOR+WHT"�����˺�Ȼ���ˣ�����ֹˮ�������������������������Ⱦ˪����\n"NOR;
			msg += HIB"$N"HIB"�峺�����з���һ�����ļ��ĵĵ���������ʮ���н���������գ�������
Զ��������ף�û��һ�ư��ơ�\n"NOR;
		} else {
			msg =  WHT"$n"NOR+WHT"�����˺�Ȼ���ˣ�����ֹˮ�����������������һ���ĳ�������$N"NOR+WHT"ͷ����\n"NOR;
			msg += HIB"$N"HIB"�峺�����з���һ�����ļ��ĵĵ���������ʮ���н���������գ�������
Զ��������ף�û��һȾ���ơ�\n"NOR;
			amount = amount /2 ;
		}

		buff =
			([
				"caster": me,
				"who":  target,
				"type": "fma",
				"att":	"bless",
				"name":	"��ѩ�ľ�����Ӱ����",
				"buff1":"force",
				"buff1_c":amount,
				"time":  duration ,
				"buff_msg": msg,
				"special_func":3,
			]);
	
		ANNIE_D->buffup(buff);	
		me->perform_busy(2);
		return 1;
}