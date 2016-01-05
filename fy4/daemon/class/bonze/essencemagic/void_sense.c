// void_sense.c by Silencer@fy4 workgroup
// -200 atk, -200 dodge for 50 sec

#include <ansi.h>
inherit SSERVER;

int conjure(object me, object target)
{
	int skill, mod, amount;
	mapping buff;

	if( me->query("class") != "bonze" ) {
		return notify_fail("ֻ���˹����µĵ��Ӳſ���ʹ�á���ʶ��ͨ����\n");
	}
	if( me->query_skill("essencemagic", 1) < 60 ) {
		return notify_fail("����ʶ��ͨ����Ҫ60����ʶ��ͨ��");
	}
	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail("����ʶ��ͨ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	}
	if( ANNIE_D->check_buff(target, "powerdown") ) {
		return notify_fail("�����Ѿ������ˣ�����ץ��ʱ��������\n");
	}
	if( me->query("atman") < 100 ) {
		return notify_fail("��Ҫ100��������\n");
	}
	if( userp(me) ) {
		me->add("atman", -100);
	}
	message_vision(HIY "$N˫�ֺ�ʮ����ü���ף��������С�����\n" NOR, me);
	skill= (int) me->query_skill("essencemagic",1);
	skill = skill > 200 ? 200: skill;
	skill = skill + F_ABILITY->check_ability(me,"3_void_add",3)*5;
	mod = COMBAT_D->can_busy(me, target, "essencemagic");
	if( !mod ) {
		mod = 10000;
	}
	amount = 30 + F_ABILITY->check_ability(me,"void_add");
	if( COMBAT_D->do_busy_attack( me, target, "essencemagic/void_sense", "unarmed", 400, mod) ) {
		buff =
		([
			"caster":me,
			"who":target,
			"type":"powerdown",
			"att":"curse",
			"name":"��ʶ��ͨ����ʶ",
			"buff1":"apply/dodge",
			"buff1_c":-skill,
			"buff2":"apply/attack",
			"buff2_c":-skill,
			"time": amount,
			"buff_msg":HIW"$N��ͷһ����ֻ���������½�Ϊ�������ƣ����β�������������\n"NOR,
			"disa_msg":RED"$N����һ�ݣ��������γ��ѡ�\n" NOR,
			"disa_type":1,
		]);
		ANNIE_D->buffup(buff);
		return 1;
	}
	message_vision(HIR"$N���һ����������֮�飬Ҳ�Ź⻪����\n"NOR, target);
	message_vision(YEL"$N������ɫ�����Ծ���΢΢������\n"NOR, me);
	me->perform_busy(2);
	return 1;
}

