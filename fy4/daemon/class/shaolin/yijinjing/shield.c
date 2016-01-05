// Silencer @ FY4 workgroup. Aug.2004
//	1:1 -- 1:2 forceshield	2800 force == + 5600 kee

#include <ansi.h>

int exert(object me, object target)
{
	int extra, ratio, delay, factor;
	mapping buff;
	
	if( me->query("class") != "shaolin" ) {
		return notify_fail("ֻ�����ָ�ɮ����ʹ���׽�ġ�����Ʒ�����\n");
	}
	extra = me->query_skill("yijinjing", 1);
	if( extra < 100 ) {
		return notify_fail("������Ʒ�����Ҫ100�����׽��\n");
	}
	if( userp(me) && F_LEVEL->get_level(me->query("combat_exp")) <= 55 ) {
		return notify_fail("��������ɱ���������ʹ���ؼ�������\n");
	}
	if( target && me != target ) {
		return notify_fail("������Ʒ���ֻ�������Լ����ϡ�\n");
	}
	if( ANNIE_D->check_buff(me, "forceshield") ) {
		return notify_fail("���Ѿ���ʹ�����Ƶ��书�ˡ�\n");
	}
	if( me->query("force") < 10 ) {
		return notify_fail("��������Ҫ����10��������\n");
	}
	if( userp(me) ) {
		me->add("force",-10);
	}

	factor = (int)me->query_skill("force");
	if( me->query("scroll/yijinjing_shield") ==2 ) {
		ratio = 180*(10+factor/10)/20;
	} else if( me->query("scroll/yijinjing_shield") == 3 ) {
		ratio = 200*(10+factor/10)/20;
	} else {
		ratio = 150*(10+factor/10)/20;
	}

	message_vision(BGRN + WHT"$N����һ���������������ȶ�������������\n"NOR,me);
	buff =
		([
			"caster":me,
			"who":me,
			"type":"forceshield",
			"att":"bless",
			"name":"�׽������Ʒ�",
			"buff1":"till_death/shield_lock",
			"buff1_c":1,
			"time":300,
			"buff_msg":BGRN + WHT"�����Ŷ����ƺ���$N��Χ���һΧ��ǽ��\n"NOR,
			"disa_msg":YEL"�����ϵ���ǽ������ʧ�ˡ�\n"NOR,
			"shield_desc":WHT"$N��ʽ����$n��ǰ����֮�⣬����������һ������֮����ȴ�ּ�Ӳ֮�������ϡ�\n"NOR,
			"shield_amount":ratio,
			"shield_type":"force",
		]);
	ANNIE_D->buffup(buff);
	return 1;
}