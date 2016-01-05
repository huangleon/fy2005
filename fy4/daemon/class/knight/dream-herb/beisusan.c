// sillencer@fy4.com

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	object *team, *team1;
	int i, skill, enhance, num, amount, duration;
	string msg;

	if( me->query("class") != "knight" ) {
		return notify_fail("ֻ�п���ֵ��Ӳ��ܹ�ʹ�á�����ɢ��\n");
	}
	skill = me->query_skill("dream-herb", 1);
	if( skill <120 ) {
		return notify_fail("������ɢ����Ҫ120���������廨����\n");
	}
	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail("������ɢ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	}
	duration = me->query("timer/pfm/khl_beisusan") - time() + 20;
	if( duration > 0 ) {
		return notify_fail("�㻹��Ҫ�ȴ�"+(duration)+"�������Ҳ����ٴ�ʹ�á�����ɢ��\n");
	}
	enhance = 300;
	me->set("timer/pfm/khl_beisusan", time());
	// + 400 force for everyone, +350 for self. ... but need hit enemy.
	amount = skill*2*(100+F_ABILITY->check_ability(me, "3_beisusan_add", 3)*5)/100;
	message_vision(BBLU + HIM "\n$N��ʽ��Ȼ����������˼�������ÿ��һ�У����е������󡣡�\n"NOR, me);
	if( COMBAT_D->do_magic_attack(me, target, "herb", "kee", enhance) ) {
		message_vision(HIR"$N����ͨ�죬����ײײ�������Ǻ����˾�һ�㡣\n"NOR, target);
		tell_object(me,WHT"���������Խ��Խ�ȣ��ƺ���һ��ů��ע�롣\n"NOR, target);
		if( userp(target) ) {
			if( target->query("force") >= amount ) {
				target->add("force", -amount);
			} else {
				target->set("force",0);
			}
			target->force_status_msg("force");
		}
		call_out("take_effect", 2, me, amount);
	} else {
		message_vision(YEL"$N��Ϣ���񣬲�Ϊ������\n"NOR, target);
	}
	me->perform_busy(2);
	return 1;
}

int take_effect(object me, int amount)
{
	object *team1, *team;
	int i, num;
	
	if( !me || me->is_ghost() ) {
		return 1;
	}
	team1 = me->query_team();
	if( !team1 ) {
		if( me->query("force") + amount < me->query("max_force")*2 ) {
			me->add("force", amount);
		} else {
			me->set("force", me->query("max_force")*2);
		}
		tell_object(me, WHT"ů���ھ�����Ѳ��һ�ܣ���������Ѩ��\n"NOR);
		me->force_status_msg("force");
	}else {
		team = filter_array(team1, (: present($1,environment($2)) :), me);
		num = sizeof(team);
		for( i = 0; i < num; i++ ) {
			if( !COMBAT_D->legitimate_buff(me, team[i]) ) {
				continue;
			}
			if( team[i]->query("force") + amount < team[i]->query("max_force")*2 ) {
				team[i]->add("force", amount);
			} else {
				team[i]->set("force", team[i]->query("max_force")*2);
			}
			tell_object(team[i],WHT"һ�ɵ�����ů�����㾭����Ѳ��һ�ܣ���������Ѩ��\n"NOR);
			team[i]->force_status_msg("force");
		}
	}
	return 1;
}