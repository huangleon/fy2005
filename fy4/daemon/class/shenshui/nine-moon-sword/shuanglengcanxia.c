// neon@fengyun  ��˪���ϼ��

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra, bonus, attack_bonus, damage;
	object weapon;

	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail("��˪���ϼ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	}
		
	weapon = me->query_temp("weapon");
	bonus = me->query_skill("nine-moon-sword",1) + F_LEVEL->get_level(me->query("combat_exp"));
	extra = me->query_skill("sword");

	msg = WHT"$N"NOR+WHT"����"+weapon->name()+WHT"����бָ���ϣ�����һ�ڣ�"+weapon->name()+WHT"���޲�б�Ӷ����������Ľ��������ص���˪�� \n"NOR;
	me->add_temp("apply/attack", bonus);	
	me->add_temp("apply/damage", extra);
	COMBAT_D->do_attack(me,target, TYPE_PERFORM, msg);
	me->add_temp("apply/attack", -bonus);
	me->add_temp("apply/damage", -extra);
	
	if( random(100) < F_ABILITY->check_ability(me,"3_slcx_add",3)*3 ) {
		msg = RED"$N"NOR+RED"����"+weapon->name()+RED"������ת����â������"+weapon->name()+RED"ӳ����ӰһƬ���������ӿ������������ĵĲ�ϼ�� \n"NOR;
		me->add_temp("apply/attack", bonus);	
		me->add_temp("apply/damage", extra);
		COMBAT_D->do_attack(me,target, TYPE_PERFORM, msg);
		me->add_temp("apply/attack", -bonus);
		me->add_temp("apply/damage", -extra);
	}

	if( target->query_temp("damaged_during_attack") && random(me->query_skill("nine-moon-force",1)/90) ) {
		msg = MAG"\n��ɭɭ��Ӱ��õ��ɫ�ı���ȽȽ����˵�������������ޣ�$n"NOR+MAG"����������ת��ҡҡ��׹��\n"NOR ;
		damage = COMBAT_D->magic_modifier(me, target, "sen", random(extra)/2);
		target->receive_damage("sen", damage, me);
    	target->set_temp("marks/pfm/polu_chance", time());
    	message_vision(msg, me, target);
	}

	me->perform_busy(2);
	return 1;
}
