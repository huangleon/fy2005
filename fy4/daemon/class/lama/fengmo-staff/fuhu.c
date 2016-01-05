// Silencer@fengyun4

#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;

int perform(object me, object target)
{
	int skill, duration;
	mapping buff;

	if( me->query("class") != "lama" ) { 
		return notify_fail("ֻ�д����ӵܲ���ʹ�á�����ʽ��\n");
	}
	skill = me->query_skill("fengmo-staff", 1);		
	if( skill < 40 ) {
		return notify_fail("������ʽ����Ҫ40���ķ�ħ�ȷ���\n");
	}
	if( me->query_temp("pfm/fengmo_1") || me->query_temp("pfm/fengmo_2") || me->query_temp("pfm/fengmo_3") ) {
		return notify_fail("���Ѿ���ʹ�����Ƶ��书�ˡ�\n");
	}
	duration = me->query("timer/pfm/fengmo_1") - time() + 240  - F_ABILITY->check_ability(me, "fuhu_add") * 12;
	if( duration > 0 ) {
		return notify_fail("�㻹��Ҫ�ȴ�"+duration+"�������Ҳ����ٴ�ʹ�á�����ʽ��\n");
	}

	if( !target ) {
		target = me;
	}
	if( target != me ) { 
		return notify_fail("������ʽ��ֻ�������Լ����ϡ�\n");
    }   
	if( me->query("force") < 100 ) {    
		return  notify_fail("������ʽ����Ҫ100��������\n");   	
	}
	if( userp(me) ) {
		me->add("force", -100);
	}
	buff =
		([
			"caster":me,
			"who":me,
			"type":"pfm/fengmo",
			"att":"bless",
			"name":"��ħ�ȷ�������ʽ",
			"buff1":"pfm/fengmo_1",
			"buff1_c":1,
			"time":80,
			"buff_msg":WHT"$N"NOR+WHT"���ַ��ȣ����������Ҹ������ƣ��������ȴ�ᣬ���������ֽ�ס��̤��
���������Ƿ�ħ�ȷ���һ������ʽ��������"HIR"����\n\n"NOR,
			"disa_msg":YEL"��һ�ס�����ʽ���ݻ���ϣ���ס���Ρ�\n"NOR,
			"special_func":0,
		]);

	ANNIE_D->buffup(buff);
	me->set("timer/pfm/fengmo_1", time());
	return 1;
}