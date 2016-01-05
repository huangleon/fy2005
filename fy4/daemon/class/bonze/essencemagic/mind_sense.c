// mind_sense.c by silencer@fy4

#include <ansi.h>
inherit SSERVER;

int conjure(object me, object target)
{
	string msg;
	string *vis = ({ "���Ρ�", "����", "���㡻", "����" });
	int cost, damage, skill, dp, bonus, n, i;
	int force_rate;

	if( me->query("class") != "bonze" ) {
		return notify_fail("ֻ���˹����µĵ��Ӳſ���ʹ�á���ʶ��\n");
	}
	skill = me->query_skill("essencemagic",1);
	if( skill < 40 ) {
		return notify_fail("����ʶ����Ҫ40����ʶ��ͨ��\n");
	}
	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail("���ַ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	}
	cost = skill/2;
	if( cost < 50 ) {
		cost = 50;
	}
	if( (int)me->query("atman") < cost ) {
		return notify_fail("����ʶ����Ҫ"+cost+"��������\n");
	}
	me->add("atman", -cost);
	msg = HIY "$N��Ŀ����ӡ�÷���һƬ��ϼ����Ȼ����ҫ�ۣ��������ϼ�������$n��\n\n" NOR;
	message_vision(msg, me, target);
	// 600+ random(400) --> L220: 430*3/2 + random(430) = 645 + random (430)
	damage = me->query_skill("magic");
	damage = damage*3/2 + random(damage);
	if( ANNIE_D->check_buff(me, "xg-evil") ) {
		damage = damage*(150+F_ABILITY->check_ability(me,"3_zhuxian_add",3)*2)/100;
	}
	damage = COMBAT_D->magic_modifier(me, target, "kee", damage/4);
	if( skill > 200 ) {
		skill = 200;
	}
	me->add_temp("apply/magic", skill*2);
	for( i = 0; i < 4; i++) {
		if( COMBAT_D->do_magic_attack(me, target, "magic", "kee") ) {
			message_vision(HIC"  "+vis[i]+NOR,me, target);
			target->receive_damage("kee", damage, me);
			COMBAT_D->report_status(target);
			force_rate = F_ABILITY->check_ability(me,"3_mind_add",3)/2;
			if( me->query_skill("essencemagic",1) >= 200 ) {
				force_rate += 10;
			}
			if( force_rate > 0 ) {
				if( me->query("force") + damage*force_rate/100 < 2*me->query("max_force") ) {
					me->add("force", damage*force_rate/100);
				} else {
					me->set("force", me->query("max_force")*2);
				}
				me->force_status_msg("force");
			}
		} else {
			message_vision(HIC"  "+vis[i]+NOR,me, target);
			msg = YEL"( ���Ǳ�$n����ض㿪��)\n"NOR;
			message_vision(msg, me, target);
		}
	}
	me->add_temp("apply/magic", -skill*2);
	COMBAT_D->win_lose_check(me, target, damage);
	message_vision("\n\n", target);
	me->perform_busy(2);
	return 1;
}