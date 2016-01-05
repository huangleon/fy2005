// annie 6.27.03
// dealt sen damage depends on how many skills target learned

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	int i;
	mapping buff;
	function f;
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���޶����С�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

    i = sizeof(target->query_skills());
	if (!i)
		return notify_fail("���޶����С��޷��ԶԷ�ʹ�á�\n");

	if (ANNIE_D->check_buff(target,"chaosmind"))
		return notify_fail("�Է��Ѿ��������飬���޶����С��������á�\n");

	message_vision( YEL"\n$N�۽�$n��ǰ������$n����������³�������\n"NOR,me,target);
	tell_object(target,BLU"��ƽ����ѧ���պ�Ȼ����ӿ����ͷ����һ�����ǷǷ�֮�����������һƬ���硣\n"NOR);

	f = (: call_other, __FILE__, "fullnpc",target,i :);

	target->receive_damage("sen",i*i*2,me);

	buff =
			([
				"caster":me,
				"who":target,
				"type":"chaosmind",
				"att":"curse",
				"name":"��а�ľ����޶�����",
				"time":120,
				"buff_msg":MAG"$N��ɫ��䣬��Բ���ۣ�˫����ס����̫�����ƺ�ͷʹ���ѣ�\n"NOR,
				"disa_msg":"����ס���ҵ����񣬽���������˼����\n",
				"finish_function":bind(f, this_object()),
			]);
	ANNIE_D->buffup(buff);
    COMBAT_D->report_status(target);
	return 1;
}


void fullnpc(object target,int i)
{
	if (!target)
		return;
	target->add("sen",i*i*2);
	if (target->query("sen") > target->query("eff_sen"))
		target->set("sen",target->query("eff_sen"));
	target->status_msg("sen");
	return;
}

 
