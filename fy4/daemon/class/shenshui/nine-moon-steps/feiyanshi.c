#include <ansi.h>
#include <command.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int lvl;
	object *enemy,*enemy_here;
	
	if (me->query("class")!="shenshui")
		return notify_fail("ֻ����ˮ���Ӳ���ʹ�á�����ʽ��");
		
	if ( me->query_skill("nine-moon-steps",1) < 150
		|| me->query_skill("chaos-steps",1) < 100)
		return notify_fail("������ʽ����Ҫ150���ľ���������100���ĵ������ǲ���\n");
	
	if( !target ) target = me;
	if( target != me)
		return notify_fail("������ʽ��ֻ�ܶ��Լ�ʹ�á�\n");
	
	enemy=me->query_enemy();
	if (enemy)	
		enemy_here=filter_array(enemy,(: environment($1)==environment($2) :),me);
	
	if (!enemy_here || !sizeof(enemy_here))
		return notify_fail("������ʽ��ֻ����ս����ʹ�á�\n");

	if(!me->is_fighting() )	
		return notify_fail("������ʽ��ֻ����ս����ʹ�á�\n");
			
	if (me->query("force")<150)
		return notify_fail("������ʽ��������Ҫ150���������\n");
	if (userp(me))	me->add("force",-150);
	
	msg = HIG "\n$N"HIG"���һ�У�ͻȻһƮһ���������Ӱ�б�ɳ�ȥ��������\n" NOR;
	message_vision(msg, me);
		
	me->delete_temp("marks/escape");
	GO_CMD->do_flee(me);

	me->perform_busy(1);		
	return 1;
}






/*

������     /��              ��\      
������   ��   �ܣߣߡ�������  ��       
������   �� ����    ���������v��       
������    �M                  ��       
������    ��   /��\    /��\   ��      
������    ��   ����    ��  �� ��       
������   ��    \ /    \��/    ��      
������    ����      ��      ���M         
������    ���v��    ��   ������         
������    �q������������������           
������   ��   ��           /���\����    
������  ��____��  �� ��  �� .. ����     
������        \���/ ����ܡ�         
                       ��             
����������������- FengYun - ������
 ��������������annie 06.2005
 ��������dancing_faery@hotmail.com

*/
