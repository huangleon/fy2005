// silencer@fengyun  ����ɺ�̶��

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int my_exp,your_exp, mod;
	object *weapon;
	int enhance;
	
	if (userp(me) && me->query("class")!="shenshui")
		return notify_fail("ֻ����ˮ���Ӳ���ʹ�ô��ؼ���\n");
	
	if (me->query_skill("nine-moon-sword",1) < 150 || me->query_skill("qingpingsword",1) < 100)
		return notify_fail("����ɺ�̶����Ҫ150���ľ���������100����ƽ������\n");
		
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("����ɺ�̶��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	mod = COMBAT_D->can_busy(me, target, "nine-moon-sword");	
	if (!mod)
		return notify_fail(HIW"���˹�����տ�����ᱻ�˽����Ի�ġ�\n"NOR);
	
	if( target->is_busy() )
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");
	
	weapon = me->query_temp("weapon");
	msg = WHT"\n$N"NOR+WHT"ƽ�հ���һ����ɺ�̶��"+weapon->name()+WHT"�ڿ���һ������ʱ�������������ǧ�ٵ㺮�ǡ�\n\n"NOR;
	
	me->perform_busy(1);
	
	enhance=325;

	if (COMBAT_D->do_busy_attack( me, target, "nine-moon-sword/yanduhantan", "unarmed", enhance, mod))
	{
		msg += MAG"$n"NOR+MAG"��æ��ס���̣�����$N"NOR+MAG"����ʵʵ��������Ϣ���۽�����$n"NOR+MAG"����������һ����\n"NOR,
		message_vision(msg, me, target);
		tell_object(target,MAG"����ð�������������飬�������˾���������\n\n"NOR);
		target->force_busy(3);
		target->set_temp("busy_timer/nine-moon-sword",time());
		
	} else {
		msg += YEL"$n"NOR+YEL"ʶ��$N"NOR+YEL"�����У���������Ծ����\n\n"NOR;
		message_vision(msg, me, target);
	}
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
