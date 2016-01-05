// silencer@fy4: a high success rate busy skill with 7 round timer.

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int exert(object me, object target, int amount)
{
	int skill, per, base, mod, damage, duration, cost;

	if( me->query("class") != "shenshui" ) {
		return notify_fail("�Ի�������ˮ���ľ�����\n");
	}
	skill = me->query_skill("nine-moon-spirit", 1);
	if( skill < 50 ) {
		return notify_fail ("�Ի�����Ҫ�������Ů�񹦡�\n");
	}
	duration = me->query("timer/mihunshu") + 14 - time();
	if( duration > 0 ) {
		return notify_fail(HIM"��ȴ�"+duration+"������ٴ�ʹ���Ի�����\n"NOR);
	}
	cost = skill/2;
	if( cost < 50 ) {
		cost = 50;	
	}
	if( (int)me->query("force") < cost ) {
		return notify_fail("�Ի���������Ҫ"+cost+"��������\n");
	}
	if( !target || target == me ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail("�Ի���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	}
	mod = COMBAT_D->can_busy(me, target, "nine-moon-force");	
	if( !mod ) {
		return notify_fail(HIW"���˹�����տ�����ᱻ�Ի����Ի�ġ�\n"NOR);
	}
	if( userp(me) ) {
		me->add("force", -cost);
	}
	me->set("timer/mihunshu", time());
	message_vision(HIG"\n$N"HIG"ͣס���֣���ƮƮ���۹����������$n"+HIG"��������˿����Цӯӯ ...\n\n"NOR
					WHT"$N"NOR+WHT"��������ǰ�죬��ֻ����ϸ��������������覴ã����������ص�����֮����\n\n\n" NOR, me, target);

	if( !COMBAT_D->do_busy_attack( me, target, "nine-moon-force/mihunshu", "rev-unarmed", 100, mod) ) {
		message_vision(HIY"$N"HIY"�ܿ�$n"HIY"��Ŀ�⣬����бն"HIY"$n���ţ�\n"NOR, target, me);
		return 1;
	}
	message_vision(HIM"һʱ֮�䣬$N"+HIM"����һ�������ѽ���Ϣ���۹����ؿ���$n"+HIM"��������ָ������ǰ��\n\n"NOR, target, me);
	message_vision(RED"$N"NOR+RED"��ͷ����̰��ʹ�����ĺ�������Ѫ����\n\n"NOR,target);

	// 200 + random(skill) = 200 + random(200)
	damage = skill + random(skill);
	damage = COMBAT_D->magic_modifier(me, target, "sen", damage);
	damage = damage*(100+10*F_ABILITY->check_ability(me,"3_mihun_add",3))/100;

	target->receive_damage("sen", damage, me);
	target->receive_damage("kee", damage, me);
	target->set_temp("damaged_during_attack", 1);
	target->force_busy(1);

	COMBAT_D->report_status(target);
	COMBAT_D->win_lose_check(me, target, 1);

	return 1;
}


