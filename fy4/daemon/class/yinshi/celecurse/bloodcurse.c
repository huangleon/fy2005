// Silencer@fengyun workgroup	June.2005

#include <ansi.h>
inherit SSERVER;
int curse(object me, object target)
{
	string msg, id_enemy, dot_owner, dir, index;
	int damage, ap, skill, ability, busy, super;
	int total;

	if( me->query("class") != "yinshi" ) {
		return notify_fail("ֻ�е����ȵ��Ӳ����¡�Ѫ����\n");
	}
	skill = me->query_skill("celecurse", 1);
	if( skill < 120 && userp(me) ) {
		return notify_fail("��Ѫ������Ҫ120��ͨ�콵��\n");
	}
	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail("���ֽ�ͷ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	}
	if( me->query("kee") < 5 && userp(me) ) {
		return notify_fail("��Ѫ����������Ҫ������Ѫ5�㡣\n");
	}
	me->receive_wound("kee", 5);
	msg = HIR"\n$N" HIR"�ڿ��д�����һ��Ѫ����������ϵ���ͷ��Ȼ�Ͽ�����$n��ײ������"NOR;
	me->add_temp("apply/cursism", skill*2);

	if( COMBAT_D->do_magic_attack(me, target, "cursism", "kee") ) {
		msg += WHT"
$n��֪�Ӻã����ǲ��Ӻã�ֻ������һ����һ��֮�£�������ָһ��
����ͬʱ����ֻ�������򾣬һ������ָָ��Ǳ��Ѫ��֮�У�\n\n"NOR;
		message_vision(msg, me, target);
		// 1500 damage, SB 3
		// ��Ϊ initial + 3 DOT, 375*4 each
		damage = me->query_skill("cursism");
		damage = damage*3/4;
		ability = F_ABILITY->check_ability(me,"blood_add")*3;
		damage = damage * (100 + ability)/100;
		damage = COMBAT_D->magic_modifier(me, target, "gin", damage);
		target->receive_damage("gin", damage, me);
		COMBAT_D->report_status(target);
		COMBAT_D->win_lose_check(me, target, damage);

		if( random(100) < F_ABILITY->check_ability(me,"3_bcurse_add",3)*10 ) {
			total = 6;
		}else {
			total = 3;
		}
		dot_owner = file_name(me);
		sscanf(dot_owner,"%s#%s", dir, index);
		dot_owner = me->query("id")+ index;
		if( !target->query_temp("dot/celecurse/bloodcurse/"+dot_owner) ) {
			tell_object(target, BLU"һ������˳������ֱ��������졣\n"NOR);
			target->set_temp("dot/celecurse/bloodcurse/"+dot_owner,1);
			call_out("dot", 8, me, target, total, 0, damage, dot_owner);
		} else {
			message_vision("no dot\n", me);
		}
	} else {
		msg += YEL"\n$n"YEL"����$NѪ���Ļ�������һ�ԣ���\n"NOR;
		message_vision(msg, me, target);
	}
	me->add_temp("apply/cursism", -skill*2);
	busy = 2;
	super = me->query_skill("flying-dragon",1);
	if( super >= 100 ) {
		super = (super-100)/10;
		if( random(100) < super && me->query_temp("yl9x_times") < 2 ) {
			me->add_temp("yl9x_times",1);
			message_vision(WHT"$Nһ�������³�������Ȼ˿�����Գ��͡�\n"NOR, me);
			busy = 0;
		} else {
			me->set_temp("yl9x_times",0);
		}
	}
	me->perform_busy(busy);
	return 1;
}

void dot(object me, object enemy, int total, int count, int damage, string dot_owner)
{
	if( !me || !enemy || !enemy->is_fighting(me) ) {
		if( enemy ) {
			tell_object(enemy, YEL"���е�Ѫ��������ʧ�ˡ�\n"NOR);
			enemy->delete_temp("dot/celecurse/bloodcurse/"+dot_owner);
		}
		return;
	}
	message_vision(WHT"$N���ֱ�͸��һ˿����������������\n"NOR,enemy);
	enemy->receive_damage("gin",damage, me);
	COMBAT_D->report_status(enemy);
	COMBAT_D->win_lose_check(me,enemy,damage);
	count = count+1;
	if( count < total ) {
		call_out("dot", 8, me, enemy, total, count, damage, dot_owner);
	} else {
		message_vision(YEL"$N���ϵķ�ɫ����ת�ơ����ɻ�ת�ף����ڻָ���ԭ״��\n"NOR,enemy);
//		enemy->delete_temp("dot/celecurse/bloodcurse/"+dot_owner);
		enemy->delete_temp("dot/celecurse/bloodcurse/"+dot_owner);
		return;
	}
	return ;
}
