// annie 7.02.03
// LOBOTOMY - NPC ONLY

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	int i;
	mapping buff;
	
	
	if (userp(me))
	if (!wizardp(me))
		return notify_fail("�㲻���������ܡ�\n");

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��������롹ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	
	if (ANNIE_D->check_buff(target,"idiot"))
		return notify_fail("�Է��Ѿ��ܵ����Ƽ��ܵ�Ӱ���ˡ�\n");

	buff =
	([
		"caster":me,
		"who":	target,
		"type": "idiot",
		"att": "curse",
		"buff1":"disable_inputs",
		"buff1_c":1,
		"disable_type":NOR CYN " <�������>" NOR,
		"name": "��а�ľ����������",
		"time": 16,
		"buff_msg":HIG"\n$n"HIG"˫��£���ؿڣ�������գ�����΢̧������յ���ף��������\n"BLU"$N"BLU"����һ��ֻ���������壬��������ǲ��ܼ���\n\n"NOR,
	]);
	ANNIE_D->buffup(buff);
	me->perform_busy(3);
	return 1;
}

