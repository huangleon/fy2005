//mimicat@fy4

#include <ansi.h>
inherit SSERVER;

int cast(object me, object target)
{	
	int extra,my_exp;
	extra=me->query_skill("kwan-yin-spells",1);
	my_exp=me->query("combat_exp");
	
	if(userp(me))
		return notify_fail("����ѡ�õ��书��û�����ֱ�ɱ������\n");
	
	if(me->query("class")!="lama")
		return notify_fail("ֻ�д����µĵ��Ӳ���ʹ�����ԡ�\n");
	
	if(extra<60) return notify_fail("��Ĺ����������䲻��������\n");
	
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
	if( me==target)
		return notify_fail("���Է������������Լ����ϡ�\n");

	if( (int)me->query("mana") < 400 )
		return notify_fail("��ķ���������\n");

	message_vision(
		HIR "$N���ڡ�������Ϊһ�壬��ɫׯ�أ���������������� \n"NOR,
			me, target );
	
	extra=extra*extra*100;
	
	if(my_exp/2+random(my_exp)*3/2+random(extra)>target->query("combat_exp"))
	{
		message_vision(RED"$nֻ������ͷ�����ش�һ��������ƺ�Ҫ���϶�ȥ�� \n\n"NOR,me,target);
		target->receive_wound("gin", 10 + (int)me->query_skill("spells")*3 + random(2)*75,me);
	        COMBAT_D->report_status(target);
        	COMBAT_D->win_lose_check(me,target,1);
	}
	else
		message_vision(RED"$nֻ������ͷһ������æ�������ġ� \n"NOR,me,target);

	if (userp(me)) me->add("mana", -400);
	me->set("mana_factor", 0);
	me->start_busy(3);
	return 1;
}
