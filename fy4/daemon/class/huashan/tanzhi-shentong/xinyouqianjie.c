// ������ǧ�᡻��xinyouqianjie����An attack that do 1/2 damage to self 

#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra,i,bonus,count,amount;
	int num, damage;
	object weapon, *enemy;
	
	extra = me->query_skill("tanzhi-shentong",1);
	if(extra < 160 || me->query_skill("cloud-dance",1)<200)
		return notify_fail("������ǧ�᡻������Ҫ160���ĵ�ָ��ͨ��200���Ļ÷�Ʈ���裡\n");
	
	if( !target ) target = offensive_target(me);
	if(!objectp(target) || !target->is_character() || !me->is_fighting(target)) {
		return notify_fail("������ǧ�᡻ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	}
	
	weapon = me->query_temp("weapon");
	count = weapon->query_amount();
	if (count < 12)
		return notify_fail("������ǧ�᡻������Ҫ12ö������\n");
		
	enemy=me->query_enemy();
	if(!sizeof(enemy))
		return notify_fail("������ǧ�᡻ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	msg = RED"
$N"RED"��ɫ�Ұס�������������ɽ��룬��ˮ��������ǧ�ᣬ���ͬ�䡣"HIG"

$N����һ�ӣ�˫����������Ϸ����͵ض��ִ�ȥ��ʮ��ö"+ weapon->name()+ NOR+HIG"
����ɳ��������������裬�������䡣

"NOR+YEL"$n����չ����ٲ�������Ӳ������ѵ�ˮ��"HIG"

��ʮ��ö"+ weapon->name()+ NOR+HIG"ȴ��Ȼ���ڿ���ת�ۻ�˷����ö����
��ö���ң�������ö��ת��ͷ����$n���µ�ȥ·������"NOR+WHT"

��Ȼ�䣬��������һ�����ѵ���ǰ��ȴ��$N������������ָ�ڣ�\n"NOR;

	if (userp(me))	weapon->set_amount(count-1);
	message_vision(msg, me, target);
	
	me->add_temp("apply/attack", extra*3);
	me->add_temp("apply/damage", extra*3);
	target->add_temp("buff/no_abs",1);
	
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");		
	
	me->add_temp("apply/attack",-extra*3);
	me->add_temp("apply/damage", -extra*3);
	if (target) {
		target->add_temp("buff/no_abs",-1);
		if (!target->query_temp("buff/no_abs"))
			target->delete_temp("buff/no_abs");
	}
	
	if (target->query_temp("damaged_during_attack")){
		// 160*3 = 480	// Roughly 1/2 damage at least
		message_vision(RED"\n$N��ɫ���Բ԰ף������ֿȳ�һ����Ѫ��\n"NOR, me);
		amount = extra*3* (100 - F_ABILITY->check_ability(me,"xyqj_add")*3)/100;
		amount = COMBAT_D->magic_modifier(me, target, "sen", amount);
		me->receive_damage("kee",amount,target);
		COMBAT_D->report_status(me);
	}
	
	me->perform_busy(2);
	return 1;
}


