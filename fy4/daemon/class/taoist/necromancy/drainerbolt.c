// drainerbolt.c

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	string msg;
	int damage, ap, lvl, cost;
	int dam, leach, flag ;

	if( me->query("class") != "taoist" ) {
		return notify_fail("ֻ�����幬�ĵ��Ӳ��ܹ�ʹ�����������\n");
	}
	lvl = me->query_skill("necromancy",1);
	if( lvl < 40 ) {
		return notify_fail("������֮������Ҫ40�������������\n");
	}
	if( me->query_skill_mapped("force") != "gouyee" ) {
		return notify_fail("���������ʹ�ù����ķ�����ת���š�\n");
	}
	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail("���ַ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	}
	if( ANNIE_D->check_buff(me,"manatwist") > 0 ) {
		flag = 3;
	} else {
		flag = 1;
	}
	cost = (20+lvl/2 )*flag;
	if( me->query("mana") < cost || me->query("sen") < cost ) {
		return notify_fail("������֮����������Ҫ"+ cost + "������ͷ�����\n");
	}
	if( userp(me) ) {
		me->add("mana", -cost);
	}
	msg = BBLU + HIM "$N�����૵��������ģ�����һ�ӣ����о���һ���Ϲ�����$n��\n" NOR;
	me->set_temp("last_sqpfm_used", 2);
	me->add_temp("apply/spells", lvl*2);
	if( COMBAT_D->do_magic_attack( me, target, "spells", "gin", 0) ) {
		msg += BBLU + HIR "������͡���һ�����Ϲ��$p"+HIR"����͸��������ϳ�һ���������߲ʹ�����\n"
					"�������˻�ת�����ִ�$N"+HIR"����ע��$P"+HIR"�����ڣ�\n" NOR;
		message_vision(msg, me, target);
		ap = me->query_skill("spells");
		damage = 60 + ap*ap/540 + random(ap*ap/540); 
		if( flag == 3 ) {
			damage *= 2;
		}
		// +20% chance double damage.
		if( !me->query("possessed") && random(100) < F_ABILITY->check_ability(me,"feeble_add",1)*2 ) {
			damage = damage*2;
		}
		if( me->query("possessed") ) {
			damage = damage*8/10; // Pet damage*80/100
		}
		damage = COMBAT_D->magic_modifier(me, target, "gin", damage);
		damage = damage*(100+F_ABILITY->check_ability(me,"3_bolt1_add",3)*2)/100;
		target->receive_damage("gin", damage, me);
		target->set_temp("damaged_during_attack", damage);
		// each aa level +5% damage 
		leach = damage/2;
		me->receive_fulling("gin", leach, me);
		target->add_hate(me, -leach);
		COMBAT_D->report_status(target);
		COMBAT_D->win_lose_check(me, target, damage);
	} else {
		msg += YEL"���Ǳ�$n����ض㿪�ˡ�\n"NOR;
		message_vision(msg, me, target);
	}
	me->add_temp("apply/spells", -lvl*2);
	me->perform_busy(2);
	return 1;
}
