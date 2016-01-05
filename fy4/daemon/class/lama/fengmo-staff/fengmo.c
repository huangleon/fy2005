// Silencer@fengyun4

#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;

int perform(object me, object target)
{
	int skill, duration, stage;
	object weapon;
	mapping buff;

	if( me->query("class") != "lama" ) { 
		return notify_fail("ֻ�д����ӵܲ���ʹ�á���ħʽ��\n");
	}
	skill = me->query_skill("fengmo-staff", 1);		
	if( skill < 180 ) { 	
		return notify_fail("����ħʽ����Ҫ180���ķ�ħ�ȷ����Ķ����ᣡ\n");
	}
	stage = me->query("scroll/fengmo-staff_fengmo");
	if( stage < 1 ) {
		return notify_fail("����ħʽ��ֻ�дӾ����ϲ�������\n");
	}
	if( me->query_temp("pfm/fengmo_2") || me->query_temp("pfm/fengmo_1") || me->query_temp("pfm/fengmo_3") ) {
		return notify_fail("���Ѿ���ʹ�����Ƶ��书�ˡ�\n");
    }
	duration = me->query("timer/pfm/fengmo_3") - time() + 720 - F_ABILITY->check_ability(me, "3_fengmo_add", 3) * 36;
	if( duration > 0 ) {
		return notify_fail("�㻹��Ҫ�ȴ�"+(int)(duration/60+1)+"�������Ҳ����ٴ�ʹ�á���ħʽ��\n");
	}
	if( !target ) {
		target = me;
	}
	if( target != me ) { 
		return 	notify_fail("����ħʽ��ֻ�������Լ����ϡ�\n");
	}
	if( me->query("force") < 100 ) {
		return  notify_fail("����ħʽ����Ҫ100��������\n");   	
	}
	if( userp(me) ) {
		me->add("force", -100);
	}
	weapon = me->query_temp("weapon");

	buff =
	([
		"caster":me,
		"who":me,
		"type":"pfm/fengmo",
		"att":"bless",
		"name":"��ħ�ȷ�������ʽ",
		"buff1":"pfm/fengmo_3",
		"buff1_c":1,
		"buff2":"buff/berserk_attack",
		"buff2_c":2,
		"time":30,
		"buff_msg":HIR"
$N"HIR"����"+weapon->name()+HIR"��ͷָ�죬��β��أ���ʽδ�����Ѽ������ػ�Ҷ���������ջƵ���
���Ƿ�ħ�ȷ������һ������ʽ��������"HIR"��ħ��\n\n"NOR,
			"disa_msg":YEL"��һ�ס�����ʽ���ݻ���ϣ���ס���Ρ�\n"NOR,
			"special_func":0,
		]);

	ANNIE_D->buffup(buff);
	me->set_temp("buff/berserk_skill", "fengmo-staff");
	me->set_temp("buff/berserk_attack_msg", CYN"$N���Ʒ転��������������ͷ��������$n������\n"NOR);

	me->set("timer/pfm/fengmo_3", time());
	me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), 30);
	return 1;
}


int remove_effect(object me)
{
	if( !me ) {
		return 0;
	}
	me->delete_temp("buff/berserk_skill");
	me->delete_temp("buff/berserk_attack_msg");
	return 1;
}

