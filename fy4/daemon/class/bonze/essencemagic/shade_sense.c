// void_sense.c

#include <ansi.h>
inherit SSERVER;

int	shade_done(object me, object caster);

int conjure(object me, object target)
{
	int lvl,i,duration;
	object env, *inv;
	string msg;
	mapping buff;
		
	if(me->query("class")!="bonze")
		return notify_fail("ֻ���˹����µĵ��Ӳſ���ʹ�á���ʶ��\n");
	
	lvl = me->query_skill("essencemagic",1);
	if ( lvl < 60)
        return notify_fail("����ʶ����Ҫ60����ʶ��ͨ��\n");
	
/*	if (me->is_fighting())
		return notify_fail("����ʶ��������ս����ʹ�á�\n");*/
		
	if(ANNIE_D->check_buff(me, "invisible"))
   		return notify_fail("���Ѿ��������ˡ�\n");
    
    duration = me->query("timer/no_shade")+ 600 - time();
    if (duration>0)
    	return notify_fail("�����ʶ���ƣ���ʱ�䣨"+ duration/60+"���ӣ����޷��ٴ�ʹ��\n");
                
	if(me->query("atman") < 100 )
		return notify_fail("��Ҫ100���������\n");
    me->add("atman", -100);
	
	msg = HIW "$N����������һ�Ű�âէ�����ڣ������˽����黯������\n" NOR;

	buff =
		([
			"caster":me,
			"who": me,
			"type":"invisible",
			"att":"bless",
			"name":"��ʶ��ͨ����ʶ",
			"env_type": "invisibility",
			"env_type_c":1,
			"time":  300,
			"buff_msg":  msg,
			"disa_type": 2,		// �������ж�ʱҲҪִ�� shade_done
			"finish_function": (: shade_done :),
		]);
	ANNIE_D->buffup(buff);
	if (me->is_fighting() ) me->start_busy(3);
	return 1;
}


int	shade_done(object me, object caster)
{
        if (!me || !caster)	return 1;
        message_vision(HIG "$N�����ν��������ֳ�����\n" NOR, me);
        me->add_temp("block_msg/all",1);
        me->move(environment(me));
        me->add_temp("block_msg/all",-1);
        me->perform_busy(2);
		return 1;
}
