// annie 6.27.03
// absorb iron-cloth

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	int i;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��������ȱ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (target->query_temp("buff/no_abs"))
			return notify_fail("�Է��Ѿ����ˡ�������ȱ��������ץ��ʱ��������\n");

	i = target->query_skill("iron-cloth") + target->query_temp("apply/iron-cloth");
	if (!i)
		return notify_fail("����û�б�Ҫʩչ��������ȱ����\n");

	message_vision( HIC
"\n$N����һ��$n������������ˮ�߰�˳�ƻ���$n���С�\n"NOR MAG"$N�����޹ǵ��ַ���$n�����ţ��ḧ��һ·����С�����\n" NOR, me,target);
	message_vision( HIW
"$n��Ӧ������ɲ�Ǽ�������ɫ������ɸ����񶶣������Ӳ����������һ˲��$N������ȥ��\n\n" NOR, me,target);

	target->add_temp("buff/no_abs",1);
	me->perform_busy(1);
	target->start_call_out( (: call_other, __FILE__, "remove_effect", target, 
						 i :), 60);
	return 1;
}

void remove_effect(object me,int amount)
{
	if (!me)	return;
	if (me->query_temp("buff/no_abs")>0)
		me->add_temp("buff/no_abs",-1);
	tell_object(me, "��ǽ��е�����֮�н�����ȥ�ˡ�\n");
}
 
