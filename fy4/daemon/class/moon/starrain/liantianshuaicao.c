#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	mapping buff;
	int extra, level, mod, count, duration, amount;
	object weapon;

	if( me->query("class") != "moon" ) {
		return notify_fail("ֻ����¹��ĵ��Ӳ���ʩչ������˥�ݡ���\n");
	}
	extra = me->query_skill("starrain",1);
	if( extra < 80 ) {
		return notify_fail("������˥�ݡ���Ҫ����80���ĺ���������\n");
	}
	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail("������˥�ݡ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	}
	duration = me->query("timer/pfm/starrain_sp") + 20 - time();
	if( duration > 0 ) {
		return notify_fail("����ź��С��������ǰ��¡��͡�����˥�ݡ�ÿ��������ֻ��ʹ��һ�Σ�����ȴ�"+duration+"�룩\n");
	}
	if( ANNIE_D->check_buff(target,"lowresist-sen") ) {
		return notify_fail("�Է��Ѿ��ܵ������Ƶ�Ӱ�졣\n");
	}
	// We don't use mod since we want it to be workable on tough NPCs. but we need a timer to limit its repeatability.
	weapon = me->query_temp("weapon");
	count = weapon->query_amount();
	if( count < 6 ) {
		return notify_fail("������˥�ݡ�������Ҫ6ö������\n");
	}
	if( userp(me) ) {
		weapon->add_amount(-6);
	}
	me->set("timer/pfm/starrain_sp",time());
	msg = HIG "\nһϮ�̹��$N"HIG"���ж�Ȼ��ն��ɣ������ڱ���������֮ǰӭ��������ɫ���񣬼���$n��\n"NOR;
	message_vision(msg, me, target);
	if( !COMBAT_D->do_busy_attack(me, target, "starrain/yanzihuishi", "step", 200, 10) ) {
		msg = YEL "$N"NOR+YEL"���һ�����̹��������������ת��ɢ��\n"NOR;
		message_vision(msg, target);
	} else {
		amount = -10;
		amount -= F_ABILITY->check_ability(me,"3_ltsc_add",3)*2;
		msg = HIR BLK"�̹�����������������$N"HIR+BLK"���ϣ�$N"HIR+BLK"ȴ�Ʊ��ش��������������ĵ�����������\n" NOR;
		buff =
		([
			"caster": me,
			"who": target,
			"type": "lowresist-sen",
			"att": "curse",
			"name":"��������������˥��",
			"time": 10,
			"buff1": "resistance/sen",
			"buff1_c": amount,
			"buff_msg": msg,
			"disa_msg": WHT"$N"NOR WHT"���������ڻ���������\n"NOR,
			"disa_type": 1,
		]);
		ANNIE_D->buffup(buff);
	}
	return 1;
}