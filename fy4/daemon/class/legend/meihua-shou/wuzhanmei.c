// Silencer @ FY4 workgroup. Oct.2004
// ���е�BUSY, ÿ1.5����ʹ��һ��

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int lvl, i, mod, extra, n, skill, duration;

	if( userp(me) ) {
		if( me->query("class") != "legend" ) {
			return notify_fail("����չ÷������ѩɽׯ�Ķ����书��\n");
		}
	}
	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail("����չ÷��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	}
	extra = (int)me->query_skill("meihua-shou", 1);
	skill = me->query_skill("six-sense", 1);
	if( extra < 150 || skill < 250 ) {
		return notify_fail("����չ÷����Ҫ250�������鰵ʶ��150����÷���֡�\n");
	}
	duration = me->query("timer/pfm/tx_wzm") + 90 - time() - F_ABILITY->check_ability(me,"3_wuzhanmei_add",3)*3;
	if( duration > 0 ) {
		return notify_fail("�㻹��Ҫ�ȴ�"+(int)(duration)+"�������Ҳ��ܹ��ٴ�ʹ����չ÷��\n");
	}
	if( target->is_busy() ) {
		return notify_fail(target->name()+"�Ѿ���æ�����ˣ�\n");
	}
	mod = COMBAT_D->can_busy(me, target, "meihua-shou");	
	if( !mod ) {
		return notify_fail(HIW"���˹�����տ�����ᱻ���Ʒ��Ի�ġ�\n"NOR);
	}
	me->set("timer/pfm/tx_wzm",time());
	// INherently, Every busy has 4*level hate, unarmed makes it 14x
	if( target && !userp(target) ) {
		target->add_hate(me, F_LEVEL->get_level(me->query("combat_exp"))*10);
	}
	message_vision(HIY"\n$N�������һ����ͳ��֣����ֱ�����Ѫ������$n��ǰ���ţ�����\n\n"NOR, me, target);
	msg = HIR "$N"HIR"˫�ֻó�����÷������ѩ�Ƶ���$n"HIR"������\n" NOR;
	msg += WHT"���$n��$N���˸���æ���ң�\n"NOR;
	message_vision(msg, me, target);
	target->start_busy(3); // bypass zqlz
	me->perform_busy(1);
	return 1;
}