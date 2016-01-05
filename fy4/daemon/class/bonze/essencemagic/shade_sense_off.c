#include <ansi.h>
inherit SSERVER;

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
        return notify_fail("��Ҫ60����ʶ��ͨ��\n");
	
	if(!ANNIE_D->check_buff(me, "invisible"))
   		return notify_fail("�����ڲ���������\n");
    
    if (me->query("timer/pfm/shade_off")+ 60 > time())
    	return notify_fail("����ֹͣ����ʶ��ÿ����ֻ��ʹ��һ�Ρ�\n");
        
	if(me->query("atman") < 100 )
		return notify_fail("��Ҫ100���������\n");
    me->add("atman", -100);
	me->set("timer/pfm/shade_off", time());
	
	ANNIE_D->debuff(me, "invisible");
	me->start_busy(2);
	return 1;
}
