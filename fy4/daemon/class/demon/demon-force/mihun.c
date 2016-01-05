#include <ansi.h>
inherit SSERVER;

int exert(object me, object target, int amount)
{
	object *ob;
	int i, skill, damage;

	if (userp(me) && me->query_skill("demon-force",1)<100)
		return notify_fail("���Ի�󷨡���Ҫ100�������ħ�ķ���\n");
		
	if( !me->is_fighting() )
		return notify_fail("���Ի�󷨡�ֻ����ս����ʹ�á�\n");

	if( (int)me->query("force") < 50 )
		return notify_fail("���Ի�󷨡�������Ҫ50���������\n");

	if( !target || target==me ) {
		target = offensive_target(me);
		if( !target) return notify_fail("��Ҫ��˭ʩչ���Ի�󷨡���\n");
	}

	if (target->is_busy())
		return notify_fail("�Է��Ѿ��겻�����ˡ�\n");
		
	skill = me->query_skill("force");
	if (userp(me))	me->add("force", -50);

	message_vision(	HIB "\n$N����������죬˫�۱���쳣���ʣ�\n" NOR, me, target);
	
	if( random(skill) < (int)target->query("cps") * 2 ){
		message_vision("$N�ܿ��ת��ͷȥ���ܿ���$n��Ŀ�⡣\n", target, me);
		me->perform_busy(2);
		return 1;
	}

	damage = (int)me->query("force_factor");
	target->receive_damage("gin", damage, me);
	message_vision(HIM"$N��$n�Ĺ����������󣬲��Խ�������������\n"NOR, target, me);
	target->force_busy(3);
	me->perform_busy(1);
	return 1;
}

