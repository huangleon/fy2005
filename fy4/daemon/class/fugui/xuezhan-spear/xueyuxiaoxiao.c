// Silencer@fengyun	June.2005
// ��Ѫ�����졻�����к��5���غϿɽ��Ͷ��ֵ���Ч��������2-SB

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int basic_armor(object victim)
{
	int armor, eff_ness, absorb_vic;
	string absorb_skill;
	
	if( victim->query_skill("iron-cloth") ) {
		absorb_skill = victim->query_skill_mapped("iron-cloth");
		if( absorb_skill ) {
			if( !(eff_ness = SKILL_D(absorb_skill)->ic_effect()) ) {
				eff_ness = 100;	
			}
			absorb_vic = victim->query_skill("iron-cloth",1)/2
					+ victim->query_skill(absorb_skill) * eff_ness/200
					+ victim->query_temp("apply/iron-cloth");
		} else {
			absorb_skill = "iron-cloth";
			absorb_vic = victim->query_skill("iron-cloth",1)/2
							+ victim->query_temp("apply/iron-cloth");
		}
	} else {
		absorb_vic = victim->query_temp("apply/iron-cloth");
	}
	return absorb_vic;
}

int perform(object me, object target)
{
	string forceskill, msg;
	int extra, exp_bonus;
	int tmp, rate;
	int time, chance;
	object weapon;
	mapping buff;
	
	if( me->query("class") != "fugui" ) {
		return notify_fail("��Ѫ�����졻�Ǹ�����ӵľ��С�\n");
	}
	weapon = me->query_temp("weapon");
 	extra = me->query_skill("xuezhan-spear", 1);
	tmp = me->query_skill("skyforce", 1);
    	    	
	if( tmp < 150 || extra < 160 ) {
		return notify_fail("��Ѫ�����졻��Ҫ160����Ѫսǹ����150���̿��ķ�!\n");
	}
	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail("��Ѫ�����졻ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	}
	if( ANNIE_D->check_buff(target, "ic-curse") ) {
		return notify_fail("�����Ѿ����˴����ˡ�\n");
	}
	if( !target->query_skill("iron-cloth") ) {
		return notify_fail("�Է�û��Ӳ�����ô���û���ð���\n");
	}
	me->add_temp("apply/attack", 100+extra);
	me->add_temp("apply/damage", tmp);
	msg = RED"\n$N"RED"����"+weapon->name()+NOR+RED"ǹ����ʢ�����Ƶ��ֱ꣬��$n"NOR+RED"���ţ�$n"NOR+RED"�󾪼��ˣ�
��ǹ������δ����������������Ѫ�����죬����$n��\n" NOR;
	message_vision(msg, me, target);
	COMBAT_D->do_attack(me, target, TYPE_PERFORM,"");
	me->add_temp("apply/attack", -100-extra);
	me->add_temp("apply/damage", -tmp);
        
	if( target->query_temp("damaged_during_attack") && !ANNIE_D->check_buff(target, "ic-curse") && target->query_skill("iron-cloth") ) {	
		rate = target->query_skill("iron-cloth");
		extra = (extra > 200) ? 200 : extra;
		rate = basic_armor(target);
		rate = rate * (extra + 150)/1000;
		if( wizardp(me) ) {
			write ("deduction is " + rate + "\n");
		}
		chance = F_ABILITY->check_ability(me, "3_xyxx_add", 3) * 10;
		if( random(100) < chance ) {
			time = 16;
		} else {
			time = 8;
		}
		buff =
		([
			"caster": me,
			"who": target,
			"type": "ic-curse",
			"att": "curse",
			"name": "Ѫսǹ����Ѫ������",
			"buff1": "apply/iron-cloth",
			"buff1_c": -rate,
			"time": 8,
			"buff_msg": WHT"$N����һ��������й��һ��Ӳ������ܼס�\n" NOR,
			"special_func": 0,
		]);
		ANNIE_D->buffup(buff);
		tell_object(me, WHT"Ѫսǹ����Ѫ������ĳ���ʱ�䣨"+(int)time+"�룩��\n"NOR);
	}
        
	me->perform_busy(1); 
	return 1;
}


