// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int target_exp;

    	if(userp(me))
		return notify_fail("����ѡ�õ��书��û�����ֱ�ɱ������\n");  
	
	extra = me->query_skill("nine-moon-steps",1);
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if(target->is_busy())
		return notify_fail(target->name()+"�Ѿ���æ�����ˣ�\n");
	
	message_vision(HIM"$N�Ų�������������$nת����ͣ��\n"NOR,me,target);
	if (target->query("possessed")) target_exp=target->query("combat_exp")/2;
		else target_exp=target->query("combat_exp");
		
	if(random(target_exp) < me->query("combat_exp")/2)
	{
		message_vision(YEL"        ���$N���ŵ��ۻ����ң���Ӧ��Ͼ��\n"NOR,target);
		target->start_busy(3);
	}
	else{
		message_vision(BLU"        ���$N�Լ�ת�˸�ͷ���ۻ���\n"NOR,me);
		me->start_busy(1);
	}
	return 1;
}
