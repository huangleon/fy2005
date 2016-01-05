#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg, type;
	int extra;
	int mod, rate;
	
	if( me->query("class") != "legend" ) {
		return notify_fail("��Ҷ���Ϊ��ѩ�ؼ���\n");
	}
	if( me->query_temp("pfm/luoyeqiufeng") + 2 > time() ) {
		return notify_fail("��ո�ʩչ������Ҷ��硻����û����������\n");
	}
	extra = me->query_skill("fall-steps",1);
	if( extra < 100 ) {
		return notify_fail("����Ҷ��硻��Ҫ100������粽��\n");
	}
	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail("����Ҷ��硻ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	}
	if( ANNIE_D->check_buff(me,"tx-turtle-stance") ) {
		return notify_fail("�����ڵ����������ƣ��޷�ʹ����������Ҷ��硣\n");
	}
	mod = COMBAT_D->can_busy(me, target, "fall-steps");
	if( !mod ) {
		return notify_fail(HIW"���˹�����տ�����ᱻ�˲����Ի�ġ�\n"NOR);
	}
	if( target->is_busy() ) {
		return notify_fail(target->name()+"�Ѿ���æ�����ˣ�\n");
	}
	message_vision(HIY"$N"+HIY"��̤�˷�������������е���Ҷ��Ʈ�첻����\n"NOR, me, target);
	me->set_temp("pfm/luoyeqiufeng",time());
	rate = 250;
	if( me->query_temp("pfm/legend_berserk") ) {
		rate = 200;
	}
	if( COMBAT_D->do_busy_attack(me, target, "fall-steps/luoyeqiufeng", "step", rate, mod) ) {
		message_vision(YEL"���$N���ŵ��ۻ����ң�Ӧ�Ӳ�Ͼ��\n"NOR,target);
		target->force_busy(3);
		target->set_temp("busy_timer/fall-steps",time());
	} else {
		if( random(100) < F_ABILITY->check_ability(me,"3_luoye_add",3)*10 ) {
			message_vision(YEL"����$Nһ�ۿ���$n"NOR+YEL"�Ĳ�������������,��Ϊ������\n"NOR,target,me);
		} else {
			msg = HIR"��ϧ$N"+HIR"������$n"+HIR"��������$p"+HIR"ٿȻ������"NOR;
			me->add_temp("cant_dodge",1);
			me->add_temp("cant_parry",1);
			COMBAT_D->do_attack(target, me, TYPE_PERFORM, msg);
			me->add_temp("cant_dodge",-1);
			me->add_temp("cant_parry",-1);
		}
	}
	return 1;
}