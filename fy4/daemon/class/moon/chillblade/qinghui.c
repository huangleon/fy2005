// annie 07.2003
// �������� 
// ���(perform blanche.....*escape)

// ��Ҫ��ҹ��ʩչ :pp

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra, bonus = 1, level;
	object weapon;

	if( me->query("class") != "moon" ) {
		return notify_fail("ֻ����¹����˲���ʩչ����ԡ���\n");
	}
	if( me->query("gender") == "����" && userp(me) ) {
		return notify_fail("���Ӳ��ʺ�ʩչ�����߾��ġ���ԡ�һʽ��\n");
	}
	if( me->query_skill("chillblade",1) < 190 && userp(me) ) {
		return notify_fail("����ԡ���Ҫ����190���ı����߾���\n");
	}
	if( me->query("max_mana") < 1000 ) {
		return notify_fail("����ԡ���Ҫ����1000�����Ϊ������\n");
	}
	if( userp(me) && !me->query("annie/chillblade_qinghui") ) {
		return notify_fail("�����¡���Ҫ�ȴӾ������������ʹ�á�\n");
	}
	if( me->query("mana") < 1000 ) {
		return notify_fail("��ķ���̫�ͣ����������Ҳû��ʲôЧ���ġ�\n");
	}
	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail("����ԡ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	}

/*
	���?�ϲ�		chillblade_qinghui_1		L150	1M
	���?�в�		chillblade_qinghui_2		L150	2.4M
	���?�²�		chillblade_qinghui_3		L150	6.4M
*/
	level = me->query("annie/chillblade_qinghui");
	if( !userp(me) ) {
		level = 5;
	}
	weapon = me->query_temp("weapon");
	extra = target->query_busy();
	target->start_busy(1);
	msg = HIW"\n��ʱ�䣬һ�ֱ�����ӯ�����ģ���ˮ����Ա�����أ�֦�Ϸ�����
�¹����������ţ�������Ư����һ���������޵ĵ������㡣

"HIG"����������ɫ�У�$N"HIG"���������"+(me->query_weapon())->name()+HIG"��˳���¹�����������쾰
�������$n"HIG"һ��ն�¡�\n"NOR;

	message_vision(msg, me, target);
	COMBAT_D->do_attack(me, target, TYPE_PERFORM, "");
	extra?target->start_busy(extra):target->stop_busy();
	if( target->query_temp("damaged_during_attack") && me->query("mana") ) {
		// 150v spells + 200lv heart-listening = 150*6 + 200*2 = 1300 max mana
		// 1300 * 2 = 2600 damage.
		// ability + 500 --> 3600 damage
		if( level >= 1 ) {
			extra = 1;
		}
		if( level >= 2 ) {
			extra = 3;
		}
		bonus = me->query("mana")*(extra+1)/4;
		bonus = COMBAT_D->magic_modifier(me, target,"kee", bonus);
		bonus = bonus*(100+F_ABILITY->check_ability(me,"3_myqh_add",3)*2)/100;
		if( userp(me) ) {
			me->set("mana", 0);
		}
		message_vision(WHT"\n����������ƺ��̣���������ǳǳ������$N"NOR+WHT"�������˿�֮�У�����\n"NOR, target);
		target->receive_damage("kee", bonus, me);
	//	target->receive_wound("kee", bonus, me);
		COMBAT_D->report_status(target);
		if( level >= 3 ) {
			target->perform_busy(target->query_busy()+1); // +1 busy,cant cancel.
		}
	} else {
		if( userp(me) ) {
			me->add("mana", -250);
		}
		// so maximum you can attempt 3600/3350/3100/2850/2600������������
		// at lower level it's 2000/1750/1500/1250/1000 5 times, but low level easier to hit due to full chillblade early.
	}
	me->force_status_msg("all");
	COMBAT_D->win_lose_check(me, target, bonus);
	me->perform_busy(2);
	return 1;
}