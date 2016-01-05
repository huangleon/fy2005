#include <ansi.h>
inherit SSERVER;

int main(object me, string arg)
{
	object room;
	int marktime;
	if((int) me->query_skill("incarnation",1) < 160)
    	return notify_fail("��Ҫ������������������ʹ�á���ң�Ρ���\n");
	if( me->is_fighting() )
		return notify_fail("ս�����޷�ʹ���ɷ���\n");

	if( me->query("atman") < 200 )
		return notify_fail("�������������\n");

	if (me->is_busy())
		return notify_fail("��������æ��\n");
	if( me->is_ghost())
		return notify_fail("����޷�ʹ���ɷ���\n"); 	
        if (environment(me))
        if (environment(me)->query("no_fly_in"))
    		return notify_fail("�˵ز���ʹ�á���ң�Ρ�����\n");
    	if(environment(me)->query("no_fly")||environment(me)->query("no_death_penalty")
    		|| environment(me)->query("no_fly"))
    		return notify_fail("�˵ز���ʹ�á���ң�Ρ���\n");

	me->add("atman", -200);
	me->force_status_msg("atman");
	
	me->start_busy(1);
	message_vision( HIM "$N�����ķ���˫��һ�ӣ�����һ����ɫ�����������ʧ�� ��������\n" NOR, me);
	room = environment(me);
	marktime=900+random((me->query_skill("incarnation",1)-80)*100);
	me->set_temp("timespacemark",base_name(room));
    	me->set_temp("timespacemark_time",time()+marktime);
	return 1;
}

int help(object me)
{
write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ :		setmark
[0;1;37m����������������������������������������������������������������[0m   

�����ң�Σ���Ҫ160��������������һ���ط��趨���꣨setmark����
	������һ��ʱ���ڿ��ٷ��أ�usermark��
	ÿ�κķ�200��������

[0;1;37m����������������������������������������������������������������[0m   
HELP
    );
    return 1;
}
