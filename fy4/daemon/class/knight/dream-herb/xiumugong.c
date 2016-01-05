// Silencer@fengyun


#include <ansi.h>
inherit F_CLEAN_UP;

int perform(object me, object target)
{
	int skill, resist, resist_gin_sen;
	mapping buff;
	string buff_msg;

	if( me->query("class") != "knight" ) {
		return notify_fail("ֻ�п���ֵ��Ӳ���ʹ����ľ����\n");
	}
	skill = me->query_skill("dream-herb", 1);
	if( skill < 100 ) {
		return notify_fail("��ľ��������Ҫ100���������廨����\n");
	}
	if( !target ) {
		target = me;
	}
	if( target != me ) {
		return notify_fail("��ľ��ֻ�������Լ����ϡ�\n");
	}
	if( ANNIE_D->check_buff(me,"resistup") ) {
		return notify_fail("���Ѿ���ʹ�����Ƶ��书�ˡ�\n");
	}
	switch( skill/50 ) {
		case 2:
			resist = 5;
			buff_msg = YEL"$N"NOR+YEL"˫Ŀ���գ�����һ�������ֻ��������˳�����\n"NOR;
			break;
		case 3:
			resist = 10;
			buff_msg = YEL"$N"NOR+YEL"���ƻ����Լ��ٻ�Ѩ�ϣ���Ѫ��ת��������ľ��\n"NOR;
			break;
		default:
			resist = 15;
			buff_msg = YEL"$N"NOR+YEL"�����ⷢ����ɫ���䣬�����Ұף�˲Ϣ���Ρ�\n"NOR;
			break;
	}
	resist += F_ABILITY->check_ability(me, "3_xiumu_add", 3);
	resist_gin_sen = F_ABILITY->check_ability(me, "resist_gin");
	buff =
	([
		"caster":me,
		"who": me,
		"type":"resistup",
		"att":"bless",
		"name":"�����廨������ľ��",
		"buff1": "resistance/kee",
		"buff1_c":resist,
		"buff2": "resistance/gin",
		"buff2_c":resist_gin_sen,
		"buff3": "resistance/sen",
		"buff3_c":resist_gin_sen,
		"time": 900,
		"buff_msg":buff_msg,
	]);
	ANNIE_D->buffup(buff);
	if( userp(me) && skill < 200 ) {
		me->perform_busy(1);
	}
	return 1;
}