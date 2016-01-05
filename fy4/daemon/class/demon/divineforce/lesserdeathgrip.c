// annie 7.02.03
// DEATHGRIP - NPC ONLY

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	int i;
	mapping buff;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("����ʹ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (ANNIE_D->check_buff(target,"lowresist"))
		return notify_fail("�Է��Ѿ��ܵ����Ƽ��ܵ�Ӱ���ˡ�\n");

	buff =
	([
		"caster":me,
		"who":	target,
		"type": "lowresist",
		"att": "curse",
		"buff1":"resistance/kee",
		"buff1_c":-50,
		"name": "��а�ľ�����ʹ����",
		"time": 60,
		"buff_msg":HIB"\n$n˫��ͻת����֮ɫ����������$N��������һ��ӡ�ǡ�\n$Nֻ����֫�ٺ�������������̣���ʹ�ޱȣ�����\n\n"NOR,
	]);
	ANNIE_D->buffup(buff);
	me->perform_busy(2);
	return 1;
}

