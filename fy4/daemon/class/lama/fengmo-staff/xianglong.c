// Silencer@fengyun4

#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;

int perform(object me, object target)
{
	int skill, duration;
	object weapon;
	mapping buff;

	if( me->query("class") != "lama" ) {
		return notify_fail("ֻ�д����ӵܲ���ʹ�á�����ʽ��\n");
	}
	skill = me->query_skill("fengmo-staff", 1);		
	if( skill < 120 ) {
		return notify_fail("������ʽ����Ҫ120���ķ�ħ�ȷ���\n");
	}
	if( me->query_temp("pfm/fengmo_2") || me->query_temp("pfm/fengmo_1") || me->query_temp("pfm/fengmo_3") ) {
		return notify_fail("���Ѿ���ʹ�����Ƶ��书�ˡ�\n");
	}    
	duration = me->query("timer/pfm/fengmo_2") - time() + 480 - F_ABILITY->check_ability(me, "xianglong_add") * 24;
	if( duration > 0 ) {
		return notify_fail("�㻹��Ҫ�ȴ�"+duration+"�������Ҳ����ٴ�ʹ�á�����ʽ��\n");
	}
	if( !target ) {
		target = me;
	}
	if( target != me ) {
		return 	notify_fail("������ʽ��ֻ�������Լ����ϡ�\n");
	}     
	if( me->query("force") < 100 ) {
		return  notify_fail("������ʽ����Ҫ100��������\n");   	
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
		"buff1":"pfm/fengmo_2",
		"buff1_c":1,
		"buff2":"buff/berserk_attack",
		"buff2_c":1,
		"time":40,
		"buff_msg":HIY"
$N"HIY"һ�����ȣ�����"+weapon->name()+HIY"һ�����裬���ƺ������������������Ӱ��
�������ȣ������ɵ��������߰˲������ֳ�����岽�����Ƿ�ħ�ȷ���
�ڶ�������ʽ��������"HIR"������\n\n"NOR,
		"disa_msg":YEL"��һ�ס�����ʽ���ݻ���ϣ���ס���Ρ�\n"NOR,
		"special_func":0,
	]);
	ANNIE_D->buffup(buff);
    
	me->set_temp("buff/berserk_skill", "fengmo-staff");
	me->set_temp("buff/berserk_attack_msg", CYN"$N���Ʒ転��������������ͷ��������$n������\n"NOR);		
	me->set("timer/pfm/fengmo_2", time());
	me->start_call_out((: call_other, __FILE__, "remove_effect", me :), 40);
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

