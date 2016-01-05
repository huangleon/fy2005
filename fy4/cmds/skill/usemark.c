#include <ansi.h>
inherit SSERVER;

int main(object me, string arg)
{
	string roomname;
	object room;
	int skill,atman;
	if( (skill=me->query_skill("incarnation",1)) < 160 )
       		return notify_fail("��Ҫ������������������ʹ�á���ң�Ρ���\n");
	if( me->is_fighting() )
		return notify_fail("ս�����޷�ʹ���ɷ���\n");
	
	if (me->is_busy())
		return notify_fail("��������æ��\n");
	if( me->is_ghost())
		return notify_fail("����޷�ʹ���ɷ���\n");
		
	if (stringp(me->query_temp("no_move")))
		return notify_fail(me->query_temp("no_move"));	
		 	
	if( !(roomname=me->query_temp("timespacemark")))
		return notify_fail("��û���趨���ꡣ\n");
	if( time()>me->query_temp("timespacemark_time"))
		return notify_fail("���趨�ĵ����Ѿ�ʧЧ�ˡ�\n");
	if(environment(me)->query("no_death_penalty") || environment(me)->query("no_fly")
		|| environment(me)->query("no_magic") )
    		return notify_fail("�˵ز���ʹ�á���ң�Ρ�\n");
	
	if( (atman=me->query("atman")) < 200 )
		return notify_fail("�������������\n");
	me->add("atman", -200);
	me->force_status_msg("atman");
	
	if( random(atman/5+(skill-90)/2+180) <100)	{
		 message_vision( HIY "$N��ָ����������Ĭ���ʲô��Ҳû������\n" NOR, me);
		 return notify_fail("��ġ���ң�Ρ�ʧ���ˡ�\n");	
		}
	message_vision( HIC "$N��ָ����������Ĭ���Ȼ����һ��������ʧ�� ....\n" NOR, me);
	TASK_D->flying_risk(me);
	room = load_object(roomname);
	me->move(room);
	message( "vision", HIC "\n��Ȼһ�����̴ӵ���ð����"+me->query("name")+"�������г��֣�\n\n" NOR,
		room, ({ me }) );
	return 1;
}


int help(object me)
{
write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ :		usemark
[0;1;37m����������������������������������������������������������������[0m   

�����ң�Σ���Ҫ160��������������һ���ط��趨���꣨setmark����
	������һ��ʱ���ڿ��ٷ��أ�usermark��
	ÿ�κķ�200��������
			
[0;1;37m����������������������������������������������������������������[0m   
HELP
    );
    return 1;
}
