// avatar buff


#include <ansi.h>
int stone_done(object me, object caster);


int exert(object me, object target, int amount)
{
		int skill,duration, am1, ess;
		mapping buff;
		object *mem;
		string msg;
	
		if(me->query("class")!="bonze")
			return notify_fail("ֻ���˹����µĵ��Ӳ����̡�����������\n");
	
		skill = me->query_skill("lotusforce", 1);
		ess = me->query_skill("essencemagic",1);
		
		if(skill < 150 || ess < 210) 
			return notify_fail("����������������Ҫ150�������ķ���210����ʶ��ͨ��\n");
	
	    duration = me->query("timer/pfm/xg_preservation")-time() + 1200;
		if (duration>0)
			return notify_fail("�㻹��Ҫ�ȴ�"+(duration/60)+"�������Ҳ����ٴ�ʹ�á���������\n");
    		
    	if( me->query("force") < 100 )
        	return notify_fail("������������Ҫ100���������\n");
    	if (userp(me)) me->add("force", -100);

    	msg = HIG"$N����������һ����âէ�����ڣ������˽����黯������\n"NOR;
    	
    	me->add_temp("pfm/xg_preservation",3);
		buff =
			([
				"caster":me,
				"who":me,
				"type":"xg-detaunt",
				"att":"bless",
				"name":"�����ķ���������",
				"time":30,
				"buff_msg": msg,
				"finish_function": (: stone_done :),
		]);
		
		ANNIE_D->buffup(buff);
		me->set("timer/pfm/xg_preservation", time());
		return 1;
}

int stone_done(object me, object caster){
	me->delete_temp("pfm/xg_preservation");
	return 1;
}