// Geese/Silencer @fy4 workgroup

#include <ansi.h>
inherit SSERVER;

int curse(object me, object target)
{
	int skill, i, mod, duration;
	int time;
	object* inv;

	if( me->query("class") != "wolfmount" ) {
		return notify_fail("ֻ����ɽ���Ӳ���ʹ�á������䡻\n");
	}
	skill = me->query_skill("wolf-curse", 1);	
	if( (skill < 200 || me->query_skill("cursism", 1) < 200) && userp(me) || me->query_skill("summonwolf", 1) < 260 ) {
		return notify_fail("�������䡻��Ҫ200������Ѫ��ͽ�ͷ����260����������\n");
	}
	// duration = 5mins.
	duration = me->query("timer/pfm/wm_mindcurse") + 300 - time();
	if( duration > 0 ) {
		return notify_fail("�������䡻����Ԫ����Ҫ"+duration+"���Ӻ�����ٴ����á�\n");
	}
	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail("�������䡻ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	}
	if( target->query_temp("mesmerize") || target->is_busy() ) {
		return notify_fail("�Է��Ѿ���ʧ�����ǻ�æ�����ˣ���ץ��ʱ������ɡ�\n");
	}
	mod = COMBAT_D->can_busy(me, target, "wolf-curse");	
	if( !mod ) {
		return notify_fail(HIW"���˹�����տ�����ᱻ���䷨���ġ�\n"NOR);
	}

	if( userp(target) ) {
		time = 10;
	} else {
		time = 10 + F_ABILITY->check_ability(me, "3_shexin_add", 3) * 2;
	}
	// Mesmerize timer, ���۳ɰܶ�����
	me->set("timer/pfm/wm_mindcurse", time());
	target->set_temp("busy_timer/wolf-curse", time());
	message_vision(HIB"\n$NͻȻ��������ë���Х�У���ͬ��������ް���������$n��\n\n" NOR, me, target);

	// Quite high rate of success
	if( COMBAT_D->do_busy_attack(me, target, "wolf-curse/mindcurse", "step", 300, mod) ) {
		message("vision",HIR""+me->name()+HIR"���۾�ͻȻ�ֳ�һƬ�Ⱥ�֮ɫ��"+target->name()+HIR"��������֮һ������������������\n"NOR, environment(me), ({target,me}));
		tell_object(me, HIR"����۾�ͻȻ�ֳ�һƬ�Ⱥ�֮ɫ��"+target->name()+HIR"���۾���֮һ������������������\n"NOR);
		tell_object(target,
HIR""+me->name()+HIR"����ͫͻȻͻȻ�ֳ�һƬ�Ⱥ�֮ɫ��ͻȻ���ǧ��ͷ�Ǵ�����˷�������
�����޿��ӣ��ܲ��ɱܣ������ң�\n"NOR);
		target->set_temp("mesmerize", time());
		target->start_call_out((: call_other, __FILE__, "remove_effect", target :), time*2);	
		target->start_busy(time);
		target->set_temp("condition_type", HIB" <ʧ����> "NOR);
		me->remove_killer(target);
		me->add_rival(target);
		inv = all_inventory(environment(me));
		for( i = 0; i < sizeof(inv); i++) {
			// It can't stop teammate's pet
			if( inv[i]->query("possessed") == me || inv[i]->team_member(me) ) {
				if( inv[i]->is_fighting(target) ) {
					inv[i]->remove_killer(target);
					inv[i]->add_rival(target);		
				}
			}
		}			
		return 1;
	} else {	
		message_vision(HIC "$n���Ʋ��ԣ���æ���ˣ�$Nһ����գ����²��ȣ���ǰ���������վ�ȣ�\n" NOR, me, target);	
	}
	me->perform_busy(1) ;      	   	
	return 1;
}

void remove_effect(object target)
{
	object* enemy;
	int i;

	if( !target || !living(target) ) {
		return;
	}
	if( !target->query_temp("mesmerize") ) {
		return;
	}
	target->delete_temp("mesmerize");
	target->delete_temp("condition_type");
	tell_object(target, YEL"�����ڻع�������\n"NOR);
	enemy = target->query_enemy();
	for( i = 0; i < sizeof(enemy); i++) {
		if( objectp(enemy[i]) ) {
			enemy[i]->kill_ob(target);
			target->kill_ob(enemy[i]);
		}
	}
}


