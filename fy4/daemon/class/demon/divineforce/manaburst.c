// annie 7.02.03
// MANABURST - NPC ONLY

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
		return notify_fail("����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!target->query("force") && !target->query("mana") && !target->query("atman") )
		return notify_fail("�����������޷��ԶԷ�ʹ�á�\n");

	message_vision( HIB"\n$N����������˫�Ʊ���$n�����ֿ��������ﴫ��һ��·�ˮ���Ƶ��������졣\n"NOR,me,target);
	message_vision( HIW
"$n����������ڣ�ֻ���÷·������˶������һ�㣬�۵����һ����Ѫ��\n" NOR, me,target);
	
	target->receive_damage("kee",target->query("force")*(1+random(3)),me);
	target->receive_wound("kee",target->query("force")*(1+random(3))/3,me);
	target->receive_damage("kee",target->query("mana")*(1+random(3)),me);
	target->receive_wound("kee",target->query("mana")*(1+random(3))/3,me);
	target->receive_damage("kee",target->query("atman")*(1+random(3)),me);
	target->receive_wound("kee",target->query("atman")*(1+random(3))/3,me);
	target->set("force",0);
	target->set("mana",0);
	target->set("atman",0);
    COMBAT_D->report_status(target);
	me->perform_busy(2);
	return 1;
}

